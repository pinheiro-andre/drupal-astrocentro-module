<?php
//init mobile detect
$detect = mobile_detect_get_object();

//** Form Facebook // 1 por R$1 // nouveau webservice
function astrocentro_br_app_form_lp1p1own($form, &$form_state){

	if ( !$detect->isMobile() || !$detect->isTablet()) {
		$form['civility'] = array(
			'#type' => 'radios',
			'#options' => array(0 => 'Mulher', 1 => 'Homem'),
			'#default_value' => 0,
			'#description' => "",
			'#title' => ""
		);
	}

	$form['firstname'] = array(
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
	
	if ( !$detect->isMobile() || $detect->isTablet()) {
		$days = array_combine(range(1, 31), range(1, 31));
		$days = array("" => "Dia") + $days;
		$form['birth_day'] = array(
			'#title' => "Data de nascimento",
			'#type' => 'select',
			'#options' => $days,
			'#attributes' => array('tabindex' => '2'),
		);
		$months = array_combine(range(1, 12), range(1, 12));
		$months = array("" => "Mês") + $months;
		$form['birth_month'] = array(
			'#title' => "",
			'#type' => 'select',
			'#options' => $months,
			'#attributes' => array('tabindex' => '3'),
		);
		$years = array_combine(range(1920, date("Y")), range(1920, date("Y")));
		$years = array("" => "Ano") + $years;
		$form['birth_year'] = array(
			'#title' => "",
			'#type' => 'select',
			'#options' => $years,
			'#attributes' => array('tabindex' => '4'),
		);
	}
	
	$form['email'] = array(
		'#title' => "Email",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu email'),
			'autocomplete' => 'off',
			'tabindex' => '5',
        )
	);
	$form['phone1'] = array(
		'#title' => "Telefone celular",
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t('DDD'),
			'autocomplete' => 'off',
			'size' => 2,
			'maxlength' => 2,
			'tabindex' => '6',
        )
	);
	$form['phone2'] = array(
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu celular'),
			'autocomplete' => 'off',
			'size' => 9,
			'tabindex' => '7',
        )
	);	
	if ( $detect->isMobile() || $detect->isTablet()) {
		$form['age'] = array(
			'#title' => "Mais de 18 anos?",
			'#required' => true,
			'#type' => 'checkbox',
			'#attributes' => array(
				'tabindex' => '8',
			)
		);
	}
	
	 $form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'CADASTRAR',
		'#attributes' => array(
			'tabindex' => '9',
			'class' => array(
				'btn-yellow',
				'btn-lg',
				'btn-block'
			),
        )
	);

	return $form;
}
function astrocentro_br_app_form_lp1p1own_submit($form, &$form_state){
	if(!form_get_errors()){
	
		switch(WENGO_ENV){
			case 'prod':
				$ws = "http://ws.wengo.fr/user/server.php";
				break;
			case 'preprod':
				$ws = "http://ws.wengo.fr.geekic.com/user/server.php";
				break;
			default:
				$ws = "http://ws.wengo.fr.center.localdev4/user/server.php";
				break;
		}
		
		//$civility = ($form_state['values']['civility'] == 1) ? 1 : 0;
		$civility = $form_state['values']['civility'];
		
		$_SESSION['email'] = $form_state['values']["email"];
		
		$telephone = $form_state['values']['phone1'].$form_state['values']['phone2'];
		$telephone = str_replace (' ', '', $telephone);
		$telephone = str_replace ('-', '', $telephone);
		$telephone = str_replace ('(', '', $telephone);
		$telephone = str_replace (')', '', $telephone);
		
		if( !isset($_POST['age']) ){
			$birth_date = $form_state['values']["birth_day"].'-'.$form_state['values']["birth_month"].'-'.$form_state['values']["birth_year"];
			$birth_date_ws = date_create($birth_date);
			
			$age_requirement = 19;
			
			$datetime2 = new DateTime(date('Y-m-d'));
			$timestamp_from = (int) $birth_date_ws->format('U');
			$timestamp_to = (int) $datetime2->format('U');
			$difference = (int) round(($timestamp_to - $timestamp_from)/(60*60*24*365));
		
			$birthdate_for_webservice = date_format($birth_date_ws, 'Y-m-d');
		}else{
			$birthdate_for_webservice = "1900-1-1";
		}
		
		$family = "ownfbook_lp";

$subscription = array();
$subscription[] = ASTROCENTRO_BR_COM_WS_WENGO_API_KEY; // API Key
$subscription[] = NULL; //login
$subscription[] = $form_state['values']["email"]; //email
$subscription[] = NULL; // password
$subscription[] = $form_state['values']["firstname"]; //firstname
$subscription[] = "0055".$telephone; //phonenumber
$subscription[] = "por"; //t9n
$subscription[] = "bra"; //i18n
$subscription[] = "1"; //population
$subscription[] = ''; //tracker_id string $tracker_id context tracker_id (optional, default value )
$subscription[] = ''; //tracker_id_params string $tracker_id_params context tracker_id_params (optional, default value )
$subscription[] = "hdk_prospect"; //factory_channel string $factory_channel factory channel (optional, default value hdk_prospect)
$subscription[] = $civility; //ln1_gender inetger $ln1_gender gender (optional, default value NULL)
$subscription[] = NULL; //ln1_lastname string $ln1_lastname last name (optional, default value )
$subscription[] = ''; //ln2 string $ln2 address (optional, default value )
$subscription[] = ''; //ln3 string $ln3 address (optional, default value )
$subscription[] = ''; //ln4 string $ln4 address (optional, default value )
$subscription[] = ''; //ln6_zip string $ln6_zip zip (optional, default value )
$subscription[] = ''; //ln6_city string $ln6_city city (optional, default value )
$subscription[] = ''; //ln7_country string $ln7_country country (optional, default value )
$subscription[] = $birthdate_for_webservice; //birthdate string $birthdate birth date (optional, default value )
$subscription[] = ''; //mobile_phonenumber string $mobile_phonenumber mobile phonenumber (optional, default value)
$subscription[] = ''; //bof_user_keyid integer $bof_user_keyid bof user keyid (optional, default value )
$subscription[] = ''; //json_data string $json_data json_data (optional, default value )
$subscription[] = "1270"; //root_directory_keyid integer $root_directory_keyid root directory keyid (optional, default value )
$subscription[] = $family; //family string $family family (optional, default value ) // here the campaign_type

		$data_s = '?method=create_generic_prospect_v1&args[]='.implode('&args[]=', $subscription);
		//watchdog("lp1p1_own_submit", "call {$ws}{$data_s}");

		
		if($difference >= $age_requirement || isset($_POST['age']) ){
		
			$r = drupal_http_request($ws.$data_s, array(
				'method' => "get",
			));
			$check = json_decode( $r->data, true );
			
			if ($check["status_code"] == "0" ) {
				$_SESSION['confirmation_msg'] = 'PARABÉNS OFERTA GARANTIDA!';
				$_SESSION['paragraphe_msg'] = 'Um consultor do Astrocentro vai ligar no horário comercial para agendar sua consulta. Até breve!';
				$_SESSION['tracking'] = true;
				
			}else if( $check["status_details"]["trusted_errdesc"] == "email already exist" ){
				$_SESSION['confirmation_msg'] = 'ESSE EMAIL JÁ ESTÁ CADASTRADO';
				$_SESSION['paragraphe_msg'] = 'Ligue para nós para garantir sua oferta. Até breve!';
				$_SESSION['tracking'] = false;
			}else{
				$_SESSION['confirmation_msg'] = 'OCORREU UM ERRO TÉCNICO';
				$_SESSION['paragraphe_msg'] = 'Ligue para nós para garantir sua oferta. Até breve!';
				$_SESSION['tracking'] = false;
			}
			
		}else{
				$_SESSION['confirmation_msg'] = 'OFERTA VÁLIDA PARA MAIORES DE 18 ANOS';
				$_SESSION['paragraphe_msg'] = '';
				$_SESSION['tracking'] = false;
		}
		
		$form_state['redirect'] = $_SESSION['landing'].$_SESSION['promo'].'own-c';
		$form_state['no_cache'] = TRUE;

		/*debug*/
		global $user;
		if($user->uid == 1){
			echo "<pre>";echo($check["status_code"]);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($civility);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($ws.$data_s);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($r);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($telephone);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($birthdate_for_webservice);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($difference);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($_SESSION['confirmation_msg']);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($_SESSION['tracking']);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($form_state['no_cache']);echo "</pre>";
			die();
		}
		
		
	}
}

//******************************** Facebook 01 // 1 por R$1
function astrocentro_br_app_lp1p1own_page(){
	drupal_session_start();
	
	$_SESSION['landing'] = 'lp1';
	$_SESSION['promo'] = 'p1';
	$include_form = drupal_get_form('astrocentro_br_app_form_lp1p1own');
	$_SESSION['campaign_type'] = 'prospect_owngoogle';
	$_SESSION['partner'] = 'own';
	
	$_SESSION['campaign_phone_display'] = '(11) 3958-7453';
	
	$_SESSION['campaign_phone_call'] = '0055'.$_SESSION['campaign_phone_display'];
	$_SESSION['campaign_phone_call'] = str_replace (' ', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace ('(', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace (')', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace ('-', '', $_SESSION['campaign_phone_call']);
	

	$content = "
	
	<div id='landing_page' class='row row-offset-0'>
	
		<div id='lp_header' class='col-lg-12 col-xs-12 col-md-offset-0'>";
	
	$content .= "
		
			<img src='" . path_to_theme() . "/images/commom/logo-astrocentro-v2.png' alt='Astrocentro, consultorio esotérico 24 horas' class='img-responsive img-center' />
		</div>
		
		<section id='".$_SESSION['landing']."' class='row row-offset-0'>
			<div id='promo' class='col-xs-12 col-sm-6 col-md-8 col-lg-8 col-md-offset-0 text-center ".$_SESSION['promo']."'>
				<div class='titles'>";
					if ( !$detect->isMobile()) {
						$content .="<h1 class='offer-title'>NOSSOS VIDENTES REVELAM<br/>SEU FUTURO POR TELEFONE</h1>
									<ul class='list-unstyled'>
										<li>Os esotéricos do Astrocentro tem previsões<br />surpreendentes para você.</li>
										<li>Pergunte o que quiser em uma consulta<br />sigilosa e segura.</li>
									</ul>
									<img src='" . path_to_theme() . "/images/".$_SESSION['landing']."/".$_SESSION['promo']."/pastille-p1.png' alt='' class='img-responsive' id='pastille' />
									";
					} else {
						$content .="<h1 class='offer-title'>Vidência por telefone</h1>
									<img src='" . path_to_theme() . "/images/".$_SESSION['landing']."/".$_SESSION['promo']."/pastille-p1.png' alt='' class='img-responsive' id='pastille' />";
					}
	$content .="	
					<div id='conditions'>
						<h5>OFERTA EXCLUSIVA PARA<br />PORTADORES DE CARTÕES DE CRÉDITO</h5>
						<div class='creditcards'>
							<img src='" . path_to_theme() . "/images/commom/visa.png' alt='visa' class='img-responsive' />
							<img src='" . path_to_theme() . "/images/commom/mastercard.png' alt='mastercard' class='img-responsive' />
							<img src='" . path_to_theme() . "/images/commom/diners.png' alt='diners' class='img-responsive' />
						</div>
						<div class='clearfix'></div>
						<ul class='list-unstyled'>
							<li><span class='glyphicon glyphicon-ok'></span> DADOS 100% PROTEGIDOS</li>
							<li><span class='glyphicon glyphicon-ok'></span> VOCÊ DESLIGA QUANDO QUISER</li>
							<li><span class='glyphicon glyphicon-ok'></span> PAGAMENTO É EFETUADO SOMENTE<br />&nbsp;&nbsp;&nbsp;&nbsp;NO INÍCIO DA CONSULTA</li>
						</ul>
					</div>
					
					<div class='clearfix'></div>

				</div>
			</div>
			
			<div id='captation' class='col-xs-12 col-sm-6 col-md-4 col-lg-4 col-md-offset-0 bg-blue ".$_SESSION['promo']."'>
				<div class='col-xs-12'>
					<div class='titles-top text-center hidden-xs'>
						<h5>Sim eu quero aproveitar</h5>
						<h4>uma consulta de<br />R$1,00 por minuto*</h4>
					</div>
			";
	$content .= drupal_render($include_form);
		
	//$content .= drupal_render(module_load_include('inc', 'astrocentro_br_app', '/landing_includes/test'));
	
	$content .= "
				</div>
			</div>
		</section>



	<div id='lp_footer' class='col-xs-12 col-lg-12 col-lg-offset-0 text-center'>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_5.png' alt='' />
			<span>A maior</span>
			<h6>VARIEDADE</h6>
			<span>de esotéricos</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_1.png' alt='' />
			<span>Profissionais</span>
			<h6>EXPERIENTES</h6>
			<span>98% satisfação</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_2.png' alt='' />
			<span>Consultas</span>
			<h6>SIGILOSAS</h6>
			<span>fone, chat e email</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_3.png' alt='' />
			<span>Dados</span>
			<h6>PROTEGIDOS</h6>
			<span>criptografados</span>
		</div>

		<div class='col-lg-2 col-xs-12 clearfix'>
			<img src='" . path_to_theme() . "/images/commom/icon_4.png' alt='' />
			<span>Pacotes</span>
			<h6>ECONOMICOS</h6>
			<span>disponiveis</span>
		</div>
		
	</div><!--endfooter!-->
	<div class='clearfix'></div>
	
	<p><small>* Campos obrigatórios.</small></p>
	<p><small>A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/".date('Y')." e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone ".$_SESSION['campaign_phone_display'].". A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	return $content;

}
function astrocentro_br_app_lp1p1own_confirmation_page(){
	
$content = "
	
	<div id='landing_page' class='row row-offset-0 confirmation'>
	

		<div id='lp_header' class='col-lg-12'>
			<img src='" . path_to_theme() . "/images/commom/logo-astrocentro-v2.png' alt='Astrocentro, consultorio esotérico 24 horas' class='img-responsive img-center' />
		</div>
		
		<section id='".$_SESSION['landing']."' class='row row-offset-0'>";
	if ( !$detect->isMobile()) {
		$content .="
			<div id='promo' class='col-xs-12 hidden-xs hidden-md hidden-sm col-lg-8 text-center p1'>
				<div class='titles'>
					<h1>RECEBA DIARIAMENTE O HORÓSCOPO DO ASTROCENTRO PELO CELULAR</h1>
						<div id='conditions' class='hidden-xs'>
							<h5>Mande um <span>SMS</span><br/>com seu signo para <span>77477</span></h5>
							<img src='" . path_to_theme() . "/images/commom/celular.png' alt='visa' class='img-responsive center-block' />
							<p>Tim: R$0,31 + impostos/msg até 3 msg/dia – Oi e Vivo: R$0,99 + impostos/dia<br/>Claro: R$ 1,40/dia **</p>
							<p><small>** Clube Jet Horóscopo Astrocentro. Receba dicas diárias sobre o seu signo e um conteúdo para download! Serviço disponível para os usuários das operadoras Vivo a um valor de R$ 0,99 + impostos por dia com renovação automática diária; Oi a um valor de R$ 0,99 + tributos por dia com renovação automática; TIM a um valor de R$ 0,31 + impostos por mensagem, até 3 mensagens por dia com renovação automática e Claro a um valor de R$ 1,40 por dia com renovação automática. Ao assinar, você também recebe 1 download toda semana. Você paga apenas o valor do tráfego de acordo com a tabela de sua operadora. Para cancelar, envie SAIR para 77477. Em caso de dúvida, envie um e-mail para <a href='mailto:info@jetmobile.com.br'>info@jetmobile.com.br</a> informando a sua Operadora e o número do seu celular com o DDD ou ligue para 11 4872-9854 <a href='http://horoscopo2.jetmobile.com.br/file/TermoseCondicoes.pdf' target='_blank' title='arquivo PDF'>Veja nossos Termos e Condições</a>.</small></p>
							<div class='clearfix'></div>
						</div>
						
						<div class='clearfix'></div>
				</div>
			</div>";
		}
		$content .="	
			<div id='lp_confirmation' class='col-lg-4 col-xs-12 bg-blue text-center'>
				<h1>" . $_SESSION['confirmation_msg'] . "</h1>
				<p>" . $_SESSION['paragraphe_msg'] . "</p>

				<div>
			<a href='tel:+".$_SESSION['campaign_phone_call']."'>
					<h5>QUER SE CONSULTAR AGORA</h5>
					<h4>LIGUE PARA ASTROCENTRO</h4>
					<h4>".$_SESSION['campaign_phone_display']."</h4>
			</a>
				</div>
			</div>
		</section>



	<div id='lp_footer' class='col-xs-12 col-md-12 col-md-offset-0 text-center'>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_5.png' alt='' />
			<span>A maior</span>
			<h6>VARIEDADE</h6>
			<span>de esotéricos</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_1.png' alt='' />
			<span>Profissionais</span>
			<h6>EXPERIENTES</h6>
			<span>98% satisfação</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_2.png' alt='' />
			<span>Consultas</span>
			<h6>SIGILOSAS</h6>
			<span>fone, chat e email</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_3.png' alt='' />
			<span>Dados</span>
			<h6>PROTEGIDOS</h6>
			<span>criptografados</span>
		</div>

		<div class='col-lg-2 col-xs-12 clearfix'>
			<img src='" . path_to_theme() . "/images/commom/icon_4.png' alt='' />
			<span>Pacotes</span>
			<h6>ECONOMICOS</h6>
			<span>disponiveis</span>
		</div>
		
	</div><!--endfooter!-->
	<div class='clearfix'></div>
	
	<p><small>* Campos obrigatórios.</small></p>
	<p><small>A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/".date('Y')." e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone ".$_SESSION['campaign_phone_display'].". A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	
	if ($_SESSION['tracking']){
		$content .="
		
			<!-- Google Code for Leads - Classica Conversion Page -->
			<script type='text/javascript'>
			/* <![CDATA[ */
			var google_conversion_id = 1006044158;
			var google_conversion_language = 'en';
			var google_conversion_format = '2';
			var google_conversion_color = 'ffffff';
			var google_conversion_label = 'ca8DCPrKyQgQ_ofc3wM';
			var google_remarketing_only = false;
			/* ]]> */
			</script>
			<script type='text/javascript' src='//www.googleadservices.com/pagead/conversion.js'>
			</script>
			<noscript>
			<div style='display:inline;'>
			<img height='1' width='1' style='border-style:none;' alt='' src='//www.googleadservices.com/pagead/conversion/1006044158/?label=ca8DCPrKyQgQ_ofc3wM&amp;guid=ON&amp;script=0'/>
			</div>
			</noscript>
		
		";
	} else {
		$content .= "<!-- No tracking tag -->";
	}
	
	return $content;

}

//******************************** Facebook 02 // 1 por R$1
function astrocentro_br_app_lp2p1own_page(){
	drupal_session_start();
	
	$_SESSION['landing'] = 'lp2';
	$_SESSION['promo'] = 'p1';
	$include_form = drupal_get_form('astrocentro_br_app_form_lp1p1own');
	$_SESSION['campaign_type'] = 'prospect_owngoogle';
	$_SESSION['partner'] = 'own';
	
	$_SESSION['campaign_phone_display'] = '(11) 3958-7453';
	
	$_SESSION['campaign_phone_call'] = '0055'.$_SESSION['campaign_phone_display'];
	$_SESSION['campaign_phone_call'] = str_replace (' ', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace ('(', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace (')', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace ('-', '', $_SESSION['campaign_phone_call']);
	

	$content = "
	
	<div id='landing_page' class='row row-offset-0'>
	
		<div id='lp_header' class='col-lg-12 col-xs-12 col-md-offset-0'>";
	
	$content .= "
		
			<img src='" . path_to_theme() . "/images/commom/logo-astrocentro-v2.png' alt='Astrocentro, consultorio esotérico 24 horas' class='img-responsive img-center' />
		</div>
		
		<section id='".$_SESSION['landing']."' class='row row-offset-0'>
			<div id='promo' class='col-xs-12 col-sm-6 col-md-8 col-lg-8 col-md-offset-0 text-center ".$_SESSION['promo']."'>
				<div class='titles'>";
					if ( !$detect->isMobile()) {
						$content .="<h1 class='offer-title'>NOSSOS VIDENTES REVELAM<br/>SEU FUTURO POR TELEFONE</h1>
									<ul class='list-unstyled'>
										<li>Os esotéricos do Astrocentro tem previsões<br />surpreendentes para você.</li>
										<li>Pergunte o que quiser em uma consulta<br />sigilosa e segura.</li>
									</ul>
									<img src='" . path_to_theme() . "/images/".$_SESSION['landing']."/".$_SESSION['promo']."/pastille-p1.png' alt='' class='img-responsive' id='pastille' />
									";
					} else {
						$content .="<h1 class='offer-title'>Vidência por telefone</h1>
									<img src='" . path_to_theme() . "/images/".$_SESSION['landing']."/".$_SESSION['promo']."/pastille-p1.png' alt='' class='img-responsive' id='pastille' />";
					}
	$content .="	
					<div id='conditions'>
						<h5>OFERTA EXCLUSIVA PARA<br />PORTADORES DE CARTÕES DE CRÉDITO</h5>
						<div class='creditcards'>
							<img src='" . path_to_theme() . "/images/commom/visa.png' alt='visa' class='img-responsive' />
							<img src='" . path_to_theme() . "/images/commom/mastercard.png' alt='mastercard' class='img-responsive' />
							<img src='" . path_to_theme() . "/images/commom/diners.png' alt='diners' class='img-responsive' />
						</div>
						<div class='clearfix'></div>
						<ul class='list-unstyled'>
							<li><span class='glyphicon glyphicon-ok'></span> DADOS 100% PROTEGIDOS</li>
							<li><span class='glyphicon glyphicon-ok'></span> VOCÊ DESLIGA QUANDO QUISER</li>
							<li><span class='glyphicon glyphicon-ok'></span> PAGAMENTO É EFETUADO SOMENTE<br />&nbsp;&nbsp;&nbsp;&nbsp;NO INÍCIO DA CONSULTA</li>
						</ul>
					</div>
					
					<div class='clearfix'></div>

				</div>
			</div>
			
			<div id='captation' class='col-xs-12 col-sm-6 col-md-4 col-lg-4 col-md-offset-0 bg-blue ".$_SESSION['promo']."'>
				<div class='col-xs-12'>
					<div class='titles-top text-center hidden-xs'>
						<h5>Sim eu quero aproveitar</h5>
						<h4>uma consulta de<br />R$1,00 por minuto*</h4>
					</div>
			";
	$content .= drupal_render($include_form);
	
	$content .= "
				</div>
			</div>
		</section>



	<div id='lp_footer' class='col-xs-12 col-lg-12 col-lg-offset-0 text-center'>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_5.png' alt='' />
			<span>A maior</span>
			<h6>VARIEDADE</h6>
			<span>de esotéricos</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_1.png' alt='' />
			<span>Profissionais</span>
			<h6>EXPERIENTES</h6>
			<span>98% satisfação</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_2.png' alt='' />
			<span>Consultas</span>
			<h6>SIGILOSAS</h6>
			<span>fone, chat e email</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_3.png' alt='' />
			<span>Dados</span>
			<h6>PROTEGIDOS</h6>
			<span>criptografados</span>
		</div>

		<div class='col-lg-2 col-xs-12 clearfix'>
			<img src='" . path_to_theme() . "/images/commom/icon_4.png' alt='' />
			<span>Pacotes</span>
			<h6>ECONOMICOS</h6>
			<span>disponiveis</span>
		</div>
		
	</div><!--endfooter!-->
	<div class='clearfix'></div>
	
	<p><small>* Campos obrigatórios.</small></p>
	<p><small>A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/".date('Y')." e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone ".$_SESSION['campaign_phone_display'].". A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	return $content;

}
function astrocentro_br_app_lp2p1own_confirmation_page(){
	
$content = "
	
	<div id='landing_page' class='row row-offset-0 confirmation'>
	

		<div id='lp_header' class='col-lg-12'>
			<img src='" . path_to_theme() . "/images/commom/logo-astrocentro-v2.png' alt='Astrocentro, consultorio esotérico 24 horas' class='img-responsive img-center' />
		</div>
		
		<section id='".$_SESSION['landing']."' class='row row-offset-0'>";
	if ( !$detect->isMobile()) {
		$content .="
			<div id='promo' class='col-xs-12 hidden-xs hidden-md hidden-sm col-lg-8 text-center p1'>
				<div class='titles'>
					<h1>RECEBA DIARIAMENTE O HORÓSCOPO DO ASTROCENTRO PELO CELULAR</h1>
						<div id='conditions' class='hidden-xs'>
							<h5>Mande um <span>SMS</span><br/>com seu signo para <span>77477</span></h5>
							<img src='" . path_to_theme() . "/images/commom/celular.png' alt='visa' class='img-responsive center-block' />
							<p>Tim: R$0,31 + impostos/msg até 3 msg/dia – Oi e Vivo: R$0,99 + impostos/dia<br/>Claro: R$ 1,40/dia **</p>
							<p><small>** Clube Jet Horóscopo Astrocentro. Receba dicas diárias sobre o seu signo e um conteúdo para download! Serviço disponível para os usuários das operadoras Vivo a um valor de R$ 0,99 + impostos por dia com renovação automática diária; Oi a um valor de R$ 0,99 + tributos por dia com renovação automática; TIM a um valor de R$ 0,31 + impostos por mensagem, até 3 mensagens por dia com renovação automática e Claro a um valor de R$ 1,40 por dia com renovação automática. Ao assinar, você também recebe 1 download toda semana. Você paga apenas o valor do tráfego de acordo com a tabela de sua operadora. Para cancelar, envie SAIR para 77477. Em caso de dúvida, envie um e-mail para <a href='mailto:info@jetmobile.com.br'>info@jetmobile.com.br</a> informando a sua Operadora e o número do seu celular com o DDD ou ligue para 11 4872-9854 <a href='http://horoscopo2.jetmobile.com.br/file/TermoseCondicoes.pdf' target='_blank' title='arquivo PDF'>Veja nossos Termos e Condições</a>.</small></p>
							<div class='clearfix'></div>
						</div>
						
						<div class='clearfix'></div>
				</div>
			</div>";
		}
		$content .="	
			<div id='lp_confirmation' class='col-lg-4 col-xs-12 bg-purple text-center'>
				<h1>" . $_SESSION['confirmation_msg'] . "</h1>
				<p>" . $_SESSION['paragraphe_msg'] . "</p>

				<div>
			<a href='tel:+".$_SESSION['campaign_phone_call']."'>
					<h5>QUER SE CONSULTAR AGORA</h5>
					<h4>LIGUE PARA ASTROCENTRO</h4>
					<h4>".$_SESSION['campaign_phone_display']."</h4>
			</a>
				</div>
			</div>
		</section>



	<div id='lp_footer' class='col-xs-12 col-md-12 col-md-offset-0 text-center'>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_5.png' alt='' />
			<span>A maior</span>
			<h6>VARIEDADE</h6>
			<span>de esotéricos</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_1.png' alt='' />
			<span>Profissionais</span>
			<h6>EXPERIENTES</h6>
			<span>98% satisfação</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_2.png' alt='' />
			<span>Consultas</span>
			<h6>SIGILOSAS</h6>
			<span>fone, chat e email</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_3.png' alt='' />
			<span>Dados</span>
			<h6>PROTEGIDOS</h6>
			<span>criptografados</span>
		</div>

		<div class='col-lg-2 col-xs-12 clearfix'>
			<img src='" . path_to_theme() . "/images/commom/icon_4.png' alt='' />
			<span>Pacotes</span>
			<h6>ECONOMICOS</h6>
			<span>disponiveis</span>
		</div>
		
	</div><!--endfooter!-->
	<div class='clearfix'></div>
	
	<p><small>* Campos obrigatórios.</small></p>
	<p><small>A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/".date('Y')." e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone ".$_SESSION['campaign_phone_display'].". A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	
	if ($_SESSION['tracking']){
		$content .="
		
			<!-- Google Code for Leads - Classica Conversion Page -->
			<script type='text/javascript'>
			/* <![CDATA[ */
			var google_conversion_id = 1006044158;
			var google_conversion_language = 'en';
			var google_conversion_format = '2';
			var google_conversion_color = 'ffffff';
			var google_conversion_label = 'ca8DCPrKyQgQ_ofc3wM';
			var google_remarketing_only = false;
			/* ]]> */
			</script>
			<script type='text/javascript' src='//www.googleadservices.com/pagead/conversion.js'>
			</script>
			<noscript>
			<div style='display:inline;'>
			<img height='1' width='1' style='border-style:none;' alt='' src='//www.googleadservices.com/pagead/conversion/1006044158/?label=ca8DCPrKyQgQ_ofc3wM&amp;guid=ON&amp;script=0'/>
			</div>
			</noscript>
		
		";
	} else {
		$content .= "<!-- No tracking tag -->";
	}
	
	return $content;
	
	$_SESSION = array();
	session_destroy();
}

//******************************** Facebook 03 // 1 por R$1
function astrocentro_br_app_lp3p1own_page(){
	drupal_session_start();
	
	$_SESSION['landing'] = 'lp3';
	$_SESSION['promo'] = 'p1';
	$include_form = drupal_get_form('astrocentro_br_app_form_lp1p1own');
	$_SESSION['campaign_type'] = 'prospect_owngoogle';
	$_SESSION['partner'] = 'own';
	
	$_SESSION['campaign_phone_display'] = '(11) 3958-7453';
	
	$_SESSION['campaign_phone_call'] = '0055'.$_SESSION['campaign_phone_display'];
	$_SESSION['campaign_phone_call'] = str_replace (' ', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace ('(', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace (')', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace ('-', '', $_SESSION['campaign_phone_call']);
	

	$content = "
	
	<div id='landing_page' class='row row-offset-0'>
	
		<div id='lp_header' class='col-lg-12 col-xs-12 col-md-offset-0'>";
	
	$content .= "
		
			<img src='" . path_to_theme() . "/images/commom/logo-astrocentro-v2.png' alt='Astrocentro, consultorio esotérico 24 horas' class='img-responsive img-center' />
		</div>
		
		<section id='".$_SESSION['landing']."' class='row row-offset-0'>
			<div id='promo' class='col-xs-12 col-sm-6 col-md-8 col-lg-8 col-md-offset-0 text-center ".$_SESSION['promo']."'>
				<div class='titles'>";
					if ( !$detect->isMobile()) {
						$content .="<h1 class='offer-title'>NOSSOS VIDENTES REVELAM<br/>SEU FUTURO POR TELEFONE</h1>
									<ul class='list-unstyled'>
										<li>Os esotéricos do Astrocentro tem previsões<br />surpreendentes para você.</li>
										<li>Pergunte o que quiser em uma consulta<br />sigilosa e segura.</li>
									</ul>
									<img src='" . path_to_theme() . "/images/".$_SESSION['landing']."/".$_SESSION['promo']."/pastille-p1.png' alt='' class='img-responsive' id='pastille' />
									";
					} else {
						$content .="<h1 class='offer-title'>Vidência por telefone</h1>
									<img src='" . path_to_theme() . "/images/".$_SESSION['landing']."/".$_SESSION['promo']."/pastille-p1.png' alt='' class='img-responsive' id='pastille' />";
					}
	$content .="	
					<div id='conditions'>
						<h5>OFERTA EXCLUSIVA PARA<br />PORTADORES DE CARTÕES DE CRÉDITO</h5>
						<div class='creditcards'>
							<img src='" . path_to_theme() . "/images/commom/visa.png' alt='visa' class='img-responsive' />
							<img src='" . path_to_theme() . "/images/commom/mastercard.png' alt='mastercard' class='img-responsive' />
							<img src='" . path_to_theme() . "/images/commom/diners.png' alt='diners' class='img-responsive' />
						</div>
						<div class='clearfix'></div>
						<ul class='list-unstyled'>
							<li><span class='glyphicon glyphicon-ok'></span> DADOS 100% PROTEGIDOS</li>
							<li><span class='glyphicon glyphicon-ok'></span> VOCÊ DESLIGA QUANDO QUISER</li>
							<li><span class='glyphicon glyphicon-ok'></span> PAGAMENTO É EFETUADO SOMENTE<br />&nbsp;&nbsp;&nbsp;&nbsp;NO INÍCIO DA CONSULTA</li>
						</ul>
					</div>
					
					<div class='clearfix'></div>

				</div>
			</div>
			
			<div id='captation' class='col-xs-12 col-sm-6 col-md-4 col-lg-4 col-md-offset-0 bg-bluedark ".$_SESSION['promo']."'>
				<div class='col-xs-12'>
					<div class='titles-top text-center hidden-xs'>
						<h5>Sim eu quero aproveitar</h5>
						<h4>uma consulta de<br />R$1,00 por minuto*</h4>
					</div>
			";
	$content .= drupal_render($include_form);
	
	$content .= "
				</div>
			</div>
		</section>



	<div id='lp_footer' class='col-xs-12 col-lg-12 col-lg-offset-0 text-center'>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_5.png' alt='' />
			<span>A maior</span>
			<h6>VARIEDADE</h6>
			<span>de esotéricos</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_1.png' alt='' />
			<span>Profissionais</span>
			<h6>EXPERIENTES</h6>
			<span>98% satisfação</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_2.png' alt='' />
			<span>Consultas</span>
			<h6>SIGILOSAS</h6>
			<span>fone, chat e email</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_3.png' alt='' />
			<span>Dados</span>
			<h6>PROTEGIDOS</h6>
			<span>criptografados</span>
		</div>

		<div class='col-lg-2 col-xs-12 clearfix'>
			<img src='" . path_to_theme() . "/images/commom/icon_4.png' alt='' />
			<span>Pacotes</span>
			<h6>ECONOMICOS</h6>
			<span>disponiveis</span>
		</div>
		
	</div><!--endfooter!-->
	<div class='clearfix'></div>
	
	<p><small>* Campos obrigatórios.</small></p>
	<p><small>A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/".date('Y')." e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone ".$_SESSION['campaign_phone_display'].". A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	return $content;

}
function astrocentro_br_app_lp3p1own_confirmation_page(){
	
$content = "
	
	<div id='landing_page' class='row row-offset-0 confirmation'>
	

		<div id='lp_header' class='col-lg-12'>
			<img src='" . path_to_theme() . "/images/commom/logo-astrocentro-v2.png' alt='Astrocentro, consultorio esotérico 24 horas' class='img-responsive img-center' />
		</div>
		
		<section id='".$_SESSION['landing']."' class='row row-offset-0'>";
	if ( !$detect->isMobile()) {
		$content .="
			<div id='promo' class='col-xs-12 hidden-xs hidden-md hidden-sm col-lg-8 text-center p1'>
				<div class='titles'>
					<h1>RECEBA DIARIAMENTE O HORÓSCOPO DO ASTROCENTRO PELO CELULAR</h1>
						<div id='conditions' class='hidden-xs'>
							<h5>Mande um <span>SMS</span><br/>com seu signo para <span>77477</span></h5>
							<img src='" . path_to_theme() . "/images/commom/celular.png' alt='visa' class='img-responsive center-block' />
							<p>Tim: R$0,31 + impostos/msg até 3 msg/dia – Oi e Vivo: R$0,99 + impostos/dia<br/>Claro: R$ 1,40/dia **</p>
							<p><small>** Clube Jet Horóscopo Astrocentro. Receba dicas diárias sobre o seu signo e um conteúdo para download! Serviço disponível para os usuários das operadoras Vivo a um valor de R$ 0,99 + impostos por dia com renovação automática diária; Oi a um valor de R$ 0,99 + tributos por dia com renovação automática; TIM a um valor de R$ 0,31 + impostos por mensagem, até 3 mensagens por dia com renovação automática e Claro a um valor de R$ 1,40 por dia com renovação automática. Ao assinar, você também recebe 1 download toda semana. Você paga apenas o valor do tráfego de acordo com a tabela de sua operadora. Para cancelar, envie SAIR para 77477. Em caso de dúvida, envie um e-mail para <a href='mailto:info@jetmobile.com.br'>info@jetmobile.com.br</a> informando a sua Operadora e o número do seu celular com o DDD ou ligue para 11 4872-9854 <a href='http://horoscopo2.jetmobile.com.br/file/TermoseCondicoes.pdf' target='_blank' title='arquivo PDF'>Veja nossos Termos e Condições</a>.</small></p>
							<div class='clearfix'></div>
						</div>
						
						<div class='clearfix'></div>
				</div>
			</div>";
		}
		$content .="	
			<div id='lp_confirmation' class='col-lg-4 col-xs-12 bg-bluedark text-center'>
				<h1>" . $_SESSION['confirmation_msg'] . "</h1>
				<p>" . $_SESSION['paragraphe_msg'] . "</p>

				<div>
			<a href='tel:+".$_SESSION['campaign_phone_call']."'>
					<h5>QUER SE CONSULTAR AGORA</h5>
					<h4>LIGUE PARA ASTROCENTRO</h4>
					<h4>".$_SESSION['campaign_phone_display']."</h4>
			</a>
				</div>
			</div>
		</section>



	<div id='lp_footer' class='col-xs-12 col-md-12 col-md-offset-0 text-center'>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_5.png' alt='' />
			<span>A maior</span>
			<h6>VARIEDADE</h6>
			<span>de esotéricos</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_1.png' alt='' />
			<span>Profissionais</span>
			<h6>EXPERIENTES</h6>
			<span>98% satisfação</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_2.png' alt='' />
			<span>Consultas</span>
			<h6>SIGILOSAS</h6>
			<span>fone, chat e email</span>
		</div>

		<div class='col-lg-2 col-xs-6'>
			<img src='" . path_to_theme() . "/images/commom/icon_3.png' alt='' />
			<span>Dados</span>
			<h6>PROTEGIDOS</h6>
			<span>criptografados</span>
		</div>

		<div class='col-lg-2 col-xs-12 clearfix'>
			<img src='" . path_to_theme() . "/images/commom/icon_4.png' alt='' />
			<span>Pacotes</span>
			<h6>ECONOMICOS</h6>
			<span>disponiveis</span>
		</div>
		
	</div><!--endfooter!-->
	<div class='clearfix'></div>
	
	<p><small>* Campos obrigatórios.</small></p>
	<p><small>A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/".date('Y')." e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone ".$_SESSION['campaign_phone_display'].". A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	
	if ($_SESSION['tracking']){
		$content .="
		
			<!-- Google Code for Leads - Classica Conversion Page -->
			<script type='text/javascript'>
			/* <![CDATA[ */
			var google_conversion_id = 1006044158;
			var google_conversion_language = 'en';
			var google_conversion_format = '2';
			var google_conversion_color = 'ffffff';
			var google_conversion_label = 'ca8DCPrKyQgQ_ofc3wM';
			var google_remarketing_only = false;
			/* ]]> */
			</script>
			<script type='text/javascript' src='//www.googleadservices.com/pagead/conversion.js'>
			</script>
			<noscript>
			<div style='display:inline;'>
			<img height='1' width='1' style='border-style:none;' alt='' src='//www.googleadservices.com/pagead/conversion/1006044158/?label=ca8DCPrKyQgQ_ofc3wM&amp;guid=ON&amp;script=0'/>
			</div>
			</noscript>
		
		";
	} else {
		$content .= "<!-- No tracking tag -->";
	}
	
	return $content;
	
	$_SESSION = array();
	session_destroy();
}