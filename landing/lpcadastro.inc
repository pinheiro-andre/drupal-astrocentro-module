<?php
drupal_session_start();

require_once(drupal_get_path('theme', 'bootstrap') . '/theme/process.inc');

$parameters = drupal_get_query_parameters();
if(isset($parameters['tracker'])) {
	$_SESSION['tracker'] = $parameters['tracker'];
}


function astrocentro_br_app_form_lpcadastro($form, &$form_state){

	$form['name'] = array(
		'#title' => "Nome",
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t(''),
			'autocomplete' => 'off',
            'placeholder' => t('Digite seu nome'),
			'tabindex' => '1',
        )
	);
	$form['email'] = array(
		'#title' => "Email",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu email'),
			'autocomplete' => 'off',
			'tabindex' => '2',
        )
	);
	$form['password'] = array(
		'#type' => "password",
		'#required' => true,
		'#title' => t('Senha'),
		'#attributes' => array(
            'placeholder' => t('Digite sua senha'),
			'autocomplete' => 'off',
			'tabindex' => '3',
		)
	);
	$form['newsletter'] = array(
		'#title' => "Deseja receber a nossa newsletter?",
		'#required' => false,
		'#type' => 'checkbox',
		'#attributes' => array(
			'tabindex' => '4',
		)
	);
	$form['cgu'] = array(
		'#title' => t('Aceitar os !tdu',
			array(
				'!tdu'    => l(t('Termos de uso'), 'http://www5.wgcdn.net/static/por_bra/cgu/cgu_v2_regulamento_interno_wengo.html')
			)
		),
		'#required' => true,
		'#type' => 'checkbox',
		'#attributes' => array(
			'tabindex' => '5',
		)
		
	);
	$form['cgu']['cgu_link'] = array(
		'#markup' => "<a href='' target='_blank'>Termos de uso</a>",
	);
	 $form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Cadastrar-se',
		'#attributes' => array(
			'tabindex' => '6',
			'class' => array(
				'btn',
				'btn-astro-pink',
				'btn-block'
			),
        )
	);

	return $form;
}

function astrocentro_br_app_form_lpcadastro_submit($form, &$form_state){
	drupal_session_start();
	$detect = mobile_detect_get_object();

	if(!form_get_errors()){
		
		if($_SERVER['SERVER_NAME'] == "www.astrocentro.com.br"){
			$ws = "http://ws.wengo.fr/user/server.php";
		}
		else if($_SERVER['SERVER_NAME'] == "www.astrocentro.com.br.geekic.com"){
			$ws = "http://ws.wengo.fr.geekic.com/user/server.php";
		}
		else {
			$ws = "http://ws.wengo.fr.center.localdev4/user/server.php";
		}
		
		$data_json = array();
		
		$name = $form_state['values']["name"];
		
		// construct login
		$email = $form_state['values']["email"];
		$parts = explode("@", $email);
		$login = $parts[0];
		$login = substr($login, 0, 16);
		
		$password = $form_state['values']["password"];
		$password = substr($password, 0, 18);
		
		$registration = array();
		$registration[] = ASTROCENTRO_BR_COM_WS_WENGO_API_KEY; // API Key
		$registration[] = $login; //login
		$registration[] = $email; //email
		$registration[] = $password; //password
		$registration[] = "por"; //t9n
		$registration[] = "bra"; //i18n
		$registration[] = "140"; //population
		$registration[] = $_SESSION['tracker']; //tracker_id string $tracker_id context tracker_id (optional, default value )
		$registration[] = ''; //tracker_id_params string $tracker_id_params context tracker_id_params (optional, default value )
		$registration[] = ''; //prospect_keyid
		
		$data_s = '?method=create_generic_account_v1&args[]='.implode('&args[]=', $registration);
		$r = drupal_http_request($ws.$data_s, array(
			'method' => "get",
		));
		$check = json_decode( $r->data, true );
		
		if($check["status_code"] == 0){

			if ( $detect->isMobile() ) {
				$_SESSION['result'] = '<a href="http://m.astrocentro.com.br.center.localdev4/conta?tracker_id='.$_SESSION['tracker'].'" class="btn btn-success btn-lg btn-block" role="button">Obrigado '.$name.',<br>você acabou de se cadastrar.<br/><br/>Clique aqui para iniciar sua consulta</a><br/><br/><span class"countdown"><strong></strong></span>';
			} else {
				$link = $check["data"]["acl_recover_url"];
				$link = str_replace("www.wengo.com.br", "astrocentro.com.br", $link);
				$_SESSION['link'] = $link;
				
				$_SESSION['result'] = '<a href="'.$link.'" class="btn btn-success btn-lg btn-block" role="button">Obrigado '.$name.',<br>você acabou de se cadastrar.<br/><br/>Clique aqui para iniciar<br/>sua consulta</a><br/><br/><span class"countdown"><strong></strong></span>';
			}

			$_SESSION['redirect'] = TRUE;
			
		} 
		else if($check["status_code"] == 36006) {
			$_SESSION['result'] = '<a href=/lpcadastro?tracker='.$_SESSION['tracker'].' class="btn btn-warning btn-lg btn-block" role="button">Esses dados já existem.<br/><br/>Tente novamente!</a>';
			$_SESSION['redirect'] = FALSE;
		} 
		else {
			$_SESSION['result'] = '<a href=/lpcadastro?tracker='.$_SESSION['tracker'].' class="btn btn-warning btn-lg btn-block" role="button">Houve um problema durante o procedimento do cadastro.<br/><br/>Tente novamente!</a>';
			$_SESSION['redirect'] = FALSE;
		}

		/*debug*/
		global $user;
		if($user->uid == 1){
			echo "<pre>";echo($check["status_code"]);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($ws.$data_s);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($r);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($_SESSION['tracker']);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";echo $link;echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($login);echo "</pre>";
			die();
		}
		
		$form_state['no_cache'] = TRUE;
		$form_state['redirect'] = 'lpcadastro-c';
	} 
	else {
		return $form;
	}
}

function astrocentro_br_app_lpcadastro(){
	drupal_session_start();
	$detect = mobile_detect_get_object();

	$include_form = drupal_get_form('astrocentro_br_app_form_lpcadastro');
	
	//<head>	
    $style_css = array(
		'#tag' => 'link',
		'#attributes' => array(
			'href' => path_to_theme().'/css/lpcadastro.css',
			'rel' => 'stylesheet',
			'type' => 'text/css',
		),
	);
    drupal_add_html_head($style_css, 'css_page');

	$title = drupal_get_title().' Cadastrar-se';
	drupal_set_title($title);
	
	$content = "

		<div id='login-overlay'>
			<div class='modal-content'>
				<div class='modal-header'>
					<img src='" . path_to_theme() . "/images/commom/logo-astrocentro-v2.png' alt='Astrocentro, consultorio esotérico 24 horas' class='left-block' />
					<h4 class='pull-right'>Cadastre-se e aproveite uma oferta especial para primeira consulta</h3>
				</div>
				<div class='modal-body'>
					<div class='row'>
						<div class='col-md-12'>
							<div class='panel panel-astrocentro text-center'>
								<div class='panel-heading'>";
	if ( $detect->isMobile() ) {
		$content .="<a href='http://m.astrocentro.com.br/conta/step1?tracker_id=".$_SESSION['tracker']."'><h3 class='panel-title' id='panel-title'>10 minutos por R$1,00, depois R$3,99 por minuto.</h3></a>";
	} else {
		$content .="<h3 class='panel-title' id='panel-title'>10 minutos por R$1,00, depois R$3,99 por minuto.</h3>";
	}								
	$content .="				</div>
							</div>
						</div>
					</div>
					<div class='row'>
						<div class='col-xs-12 col-md-6'>
							<div class='well'>"; 				
	if ( $detect->isMobile() ) {
		$content .='<a href="http://m.astrocentro.com.br/conta/step1?tracker_id='.$_SESSION['tracker'].'" class="btn btn-success btn-lg btn-block" role="button">Cadastrar se</a>';
	}else{
		$content .= drupal_render($include_form);
	}
	$content .="			</div>
						</div>
						<div class='col-xs-12 col-md-6'>
							<ul class='list-unstyled'>
								<li class='text-center'>
									<span class='fa-stack fa-lg'>
										<i class='fa fa-circle fa-stack-2x'></i>
										<i class='fa fa-edit fa-stack-1x fa-inverse'></i>
									</span> <span class='color-astro-1'>Cadastro</span>
									<p class='text-left'>Preencha seu formulário com dados de contato: e-mail e uma senha para acesso exclusivo.</p>
									<p class='text-center'><span class='fa fa-chevron-down'></span></p>
								</li>
								<li class='text-center'>
									<span class='fa-stack fa-lg'>
										<i class='fa fa-circle fa-stack-2x'></i>
										<i class='fa fa-weixin fa-stack-1x fa-inverse'></i>
									</span> <span class='color-astro-1'>Seleção</span>
									
									<p class='text-left'>Após o cadastro, confira esotéricos disponíveis e escolha aquele com quem deseja falar e a forma de contato: e-mail, fone ou chat.</p>
									<p class='text-center'><span class='fa fa-chevron-down'></span></p>
								</li>
								<li class='text-center'>
									<span class='fa-stack fa-lg'>
										<i class='fa fa-circle fa-stack-2x'></i>
										<i class='fa fa-credit-card fa-stack-1x fa-inverse'></i>
									</span> <span class='color-astro-1'>Consulta</span>
									
									<p class='text-left'>Após escolher o especialista, defina o horário (imediato ou agendamento), cadastre os dados de pagamento (cartão de crédito) e tenha o seu atendimento.</p>
								</li>
							</ul>
						</div>
					</div>
				</div>
			</div>
		</div>
	  
		<div class='container'>
		  <div class='row'>
			<div class='col-md-offset-2 col-md-8 text-center'>
				<h3 class='color-dispo'>Confira alguns especialistas disponíveis</h3>
			</div>
			
		  </div>
		  <div class='row'>
			<div class='col-md-offset-2 col-md-8'>
			  <div class='carousel slide' data-ride='carousel' id='quote-carousel'>
				<!-- Bottom Carousel Indicators -->
				<ol class='carousel-indicators'>
				  <li data-target='#quote-carousel' data-slide-to='0' class='active'></li>
				  <li data-target='#quote-carousel' data-slide-to='1'></li>
				  <li data-target='#quote-carousel' data-slide-to='2'></li>
				  <li data-target='#quote-carousel' data-slide-to='3'></li>
				</ol>
				
				<!-- Carousel Slides / Quotes -->
				<div class='carousel-inner'>
				
				  <!-- Quote 1 -->
				  <div class='item active'>
					<blockquote>
					  <div class='row'>
						<div class='col-sm-3 text-center'>
						  <img class='img-circle' src='" . path_to_theme() . "/images/esotericos/solange-martins-sol.jpg' style='width: 100px;height:100px;' />
						</div>
						<div class='col-sm-9'>
						  <p>Tarot numerologia terapeuta</p>
						  <small>Solange Martins Sol</small>
						</div>
					  </div>
					</blockquote>
				  </div>
				  <!-- Quote 2 -->
				  <div class='item'>
					<blockquote>
					  <div class='row'>
						<div class='col-sm-3 text-center'>
						  <img class='img-circle' src='" . path_to_theme() . "/images/esotericos/ivone.jpg' style='width: 100px;height:100px;' />
						</div>
						<div class='col-sm-9'>
						  <p>Taróloga</p>
						  <small>Taróloga Ivone</small>
						</div>
					  </div>
					</blockquote>
				  </div>
				  <!-- Quote 3 -->
				  <div class='item'>
					<blockquote>
					  <div class='row'>
						<div class='col-sm-3 text-center'>
						  <img class='img-circle' src='" . path_to_theme() . "/images/esotericos/fernando-terapeuta.jpg' style='width: 100px;height:100px;' />
						</div>
						<div class='col-sm-9'>
						  <p>Tarólogo e terapeuta</p>
						  <small>Fernando Terapeuta</small>
						</div>
					  </div>
					</blockquote>
				  </div>
				  <!-- Quote 4 -->
				  <div class='item'>
					<blockquote>
					  <div class='row'>
						<div class='col-sm-3 text-center'>
						  <img class='img-circle' src='" . path_to_theme() . "/images/esotericos/daiana-tarologa.jpg' style='width: 100px;height:100px;' />
						</div>
						<div class='col-sm-9'>
							<p>Taróloga , vidente e numeróloga</p>
						  <small>Daiana Tarologa</small>
						</div>
					  </div>
					</blockquote>
				  </div>
				</div>
				
				<!-- Carousel Buttons Next/Prev -->
				<a data-slide='prev' href='#quote-carousel' class='left carousel-control'><i class='fa fa-chevron-left'></i></a>
				<a data-slide='next' href='#quote-carousel' class='right carousel-control'><i class='fa fa-chevron-right'></i></a>
			  </div>                          
			</div>
		  </div>
		</div>

	";
	
	return $content;
}

function astrocentro_br_app_lpcadastro_confirmation(){
drupal_session_start();
	
	//<head>	
    $style_css = array(
		'#tag' => 'link',
		'#attributes' => array(
			'href' => path_to_theme().'/css/lpcadastro.css',
			'rel' => 'stylesheet',
			'type' => 'text/css',
		),
	);
    drupal_add_html_head($style_css, 'css_page');
	
	
	$content = "

		<div id='login-overlay'>
			<div class='modal-content'>
				<div class='modal-header'>
					<img src='" . path_to_theme() . "/images/commom/logo-astrocentro-v2.png' alt='Astrocentro, consultorio esotérico 24 horas' class='left-block' />
					<h4 class='pull-right'>Cadastre-se e aproveite uma oferta especial para primeira consulta</h3>
				</div>
				<div class='modal-body'>
					<div class='row'>
						<div class='col-md-12'>
							<div class='panel panel-astrocentro text-center'>
								<div class='panel-heading'>
									<h3 class='panel-title' id='panel-title'>10 minutos por R$ 1, em seguida, R$ 3.99 por minuto.</h3>
								</div>
							</div>
						</div>
					</div>
					<div class='row'>
						<div class='col-xs-12 col-md-6'>
							<div class='well'>";
	$content .= 				$_SESSION['result'];
	$content .="			</div>
						</div>
						<div class='col-xs-12 col-md-6'>
							<ul class='list-unstyled'>
								<li class='text-center'>
									<span class='fa-stack fa-lg'>
										<i class='fa fa-circle fa-stack-2x'></i>
										<i class='fa fa-edit fa-stack-1x fa-inverse'></i>
									</span> <span class='color-astro-1'>Cadastro</span>
									<p class='text-left'>Preencha seu formulário com dados de contato: e-mail e uma senha para acesso exclusivo.</p>
									<p class='text-center'><span class='fa fa-chevron-down'></span></p>
								</li>
								<li class='text-center'>
									<span class='fa-stack fa-lg'>
										<i class='fa fa-circle fa-stack-2x'></i>
										<i class='fa fa-weixin fa-stack-1x fa-inverse'></i>
									</span> <span class='color-astro-1'>Seleção</span>
									
									<p class='text-left'>Após o cadastro, confira esotéricos disponíveis e escolha aquele com quem deseja falar e a forma de contato: e-mail, fone ou chat.</p>
									<p class='text-center'><span class='fa fa-chevron-down'></span></p>
								</li>
								<li class='text-center'>
									<span class='fa-stack fa-lg'>
										<i class='fa fa-circle fa-stack-2x'></i>
										<i class='fa fa-credit-card fa-stack-1x fa-inverse'></i>
									</span> <span class='color-astro-1'>Consulta</span>
									
									<p class='text-left'>Após escolher o especialista, defina o horário (imediato ou agendamento), cadastre os dados de pagamento (cartão de crédito) e tenha o seu atendimento.</p>
								</li>
							</ul>
						</div>
					</div>
				</div>
			</div>
		</div>
	  
		<div class='container'>
		  <div class='row'>
			<div class='col-md-offset-2 col-md-8 text-center'>
				<h3 class='color-dispo'>Confira alguns especialistas disponíveis</h3>
			</div>
			
		  </div>
		  <div class='row'>
			<div class='col-md-offset-2 col-md-8'>
			  <div class='carousel slide' data-ride='carousel' id='quote-carousel'>
				<!-- Bottom Carousel Indicators -->
				<ol class='carousel-indicators'>
				  <li data-target='#quote-carousel' data-slide-to='0' class='active'></li>
				  <li data-target='#quote-carousel' data-slide-to='1'></li>
				  <li data-target='#quote-carousel' data-slide-to='2'></li>
				  <li data-target='#quote-carousel' data-slide-to='3'></li>
				</ol>
				
				<!-- Carousel Slides / Quotes -->
				<div class='carousel-inner'>
				
				  <!-- Quote 1 -->
				  <div class='item active'>
					<blockquote>
					  <div class='row'>
						<div class='col-sm-3 text-center'>
						  <img class='img-circle' src='" . path_to_theme() . "/images/esotericos/solange-martins-sol.jpg' style='width: 100px;height:100px;' />
						</div>
						<div class='col-sm-9'>
						  <p>Tarot numerologia terapeuta</p>
						  <small>Solange Martins Sol</small>
						</div>
					  </div>
					</blockquote>
				  </div>
				  <!-- Quote 2 -->
				  <div class='item'>
					<blockquote>
					  <div class='row'>
						<div class='col-sm-3 text-center'>
						  <img class='img-circle' src='" . path_to_theme() . "/images/esotericos/ivone.jpg' style='width: 100px;height:100px;' />
						</div>
						<div class='col-sm-9'>
						  <p>Taróloga</p>
						  <small>Taróloga Ivone</small>
						</div>
					  </div>
					</blockquote>
				  </div>
				  <!-- Quote 3 -->
				  <div class='item'>
					<blockquote>
					  <div class='row'>
						<div class='col-sm-3 text-center'>
						  <img class='img-circle' src='" . path_to_theme() . "/images/esotericos/fernando-terapeuta.jpg' style='width: 100px;height:100px;' />
						</div>
						<div class='col-sm-9'>
						  <p>Tarólogo e terapeuta</p>
						  <small>Fernando Terapeuta</small>
						</div>
					  </div>
					</blockquote>
				  </div>
				  <!-- Quote 4 -->
				  <div class='item'>
					<blockquote>
					  <div class='row'>
						<div class='col-sm-3 text-center'>
						  <img class='img-circle' src='" . path_to_theme() . "/images/esotericos/daiana-tarologa.jpg' style='width: 100px;height:100px;' />
						</div>
						<div class='col-sm-9'>
							<p>Taróloga , vidente e numeróloga</p>
						  <small>Daiana Tarologa</small>
						</div>
					  </div>
					</blockquote>
				  </div>
				</div>
				
				<!-- Carousel Buttons Next/Prev -->
				<a data-slide='prev' href='#quote-carousel' class='left carousel-control'><i class='fa fa-chevron-left'></i></a>
				<a data-slide='next' href='#quote-carousel' class='right carousel-control'><i class='fa fa-chevron-right'></i></a>
			  </div>                          
			</div>
		  </div>
		</div>
		
	";
	if($_SESSION['redirect']){
	$content .= "
		<script type=\"text/javascript\">

			//Countdown
			function Countdown(options) {
				var timer,
				instance = this,
				seconds = options.seconds || 10,
				updateStatus = options.onUpdateStatus || function () {},
				counterEnd = options.onCounterEnd || function () {};

				function decrementCounter() {
					updateStatus(seconds);
					if (seconds === 0) {
						counterEnd();
						instance.stop();
					}
					seconds--;
				}

				this.start = function () {
					clearInterval(timer);
					timer = 0;
					seconds = options.seconds;
					timer = setInterval(decrementCounter, 1000);
				};

				this.stop = function () {
					clearInterval(timer);
				};
			}
		
			var Counter = new Countdown({
				seconds:5,
				onUpdateStatus: function(sec){
					console.log(sec);
					jQuery('.countdown strong').html(sec);
				},
				onCounterEnd: function(){ 
					window.location.replace('".$_SESSION["link"]."');
				}
			});
			
			Counter.start();
		</script>
			";
		}
	
	return $content;
	
	
}