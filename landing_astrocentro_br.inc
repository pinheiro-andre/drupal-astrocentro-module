<?php
//init mobile detect
$detect = mobile_detect_get_object();

//******************************** Landing page Own Google Adwords 01 // nouveau webservice // version mobile bootstrap
function astrocentro_br_app_lp1owngoogle_page(){

	if ($detect->isMobile()) {
		$include_form = drupal_get_form('astrocentro_br_app_form_lp1owngoogle_mobile');
	}

	else {
		$include_form = drupal_get_form('astrocentro_br_app_form_lp1owngoogle');
	}
	
	

	$content = "
	
	<div id='landing_page' class='row row-offset-0'>
	
		<div id='lp_header' class='col-lg-12 col-xs-12 col-md-offset-0'>
			<img src='" . path_to_theme() . "/images/commom/logo-astrocentro-v2.png' alt='Astrocentro, consultorio esotérico 24 horas' class='img-responsive img-center' />
		</div>
		
		<section class='row row-offset-0'>
			<div id='promo' class='col-xs-12 col-lg-8 col-md-offset-0 text-center'>
				<div class='titles'>
					<h1>TAROT POR TELEFONE</h1>
					<ul class='list-unstyled'>
						<li>Os melhores astrólogos, videntes e tarólogos.</li>
						<li>24h por dia por telefone. Pergunte o que quiser.</li>
						<li>Atendimento na hora ou agendado. 100% confidencial.</li>
					</ul>
					<h2>CONSULTA <span>10 MIN<em class='color-yellow'>**</em> = R$1,00</span></h2>
					<h3>no cartão de crédito</h3>
				</div>
			</div>
			
			<div id='captation' class='col-xs-12 col-lg-4 col-md-offset-0 bg-blue'>
				<div class='col-xs-12'>
					<div class='titles-top text-center hidden-xs hidden-sm hidden-md'>
						<h5>Sim eu quero aproveitar</h5>
						<h4>UMA CONSULTA DE<br />10 MIN POR R$ 1,00</h4>
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
	<p><small><em class='color-yellow'>**</em> A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3230-1299). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	return $content;

}
function astrocentro_br_app_form_lp1owngoogle($form, &$form_state){

	$active = array(0 => t('Mulher'), 1 => t('Homem'));

	$form['civility'] = array(
		'#type' => 'radios',
		'#default_value' => 0, 
		'#options' => $active,
		'#description' => "",
		'#title' => ""
	);

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

	$form['lastname'] = array(
		'#title' => "Sobrenome",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t(''),
            'placeholder' => t('Digite seu sobrenome'),
			'autocomplete' => 'off',
			'tabindex' => '2',
        )
	);

	$days = array_combine(range(1, 31), range(1, 31));
	$days = array("" => "Dia") + $days;
	$form['birth_day'] = array(
		'#title' => "Data de nascimento",
		'#type' => 'select',
		'#options' => $days,
        '#attributes' => array('tabindex' => '3'),
	);

	$months = array_combine(range(1, 12), range(1, 12));
	$months = array("" => "Mês") + $months;
	$form['birth_month'] = array(
		'#title' => "",
		'#type' => 'select',
		'#options' => $months,
        '#attributes' => array('tabindex' => '4'),
	);

	$years = array_combine(range(1920, date("Y")), range(1920, date("Y")));
	$years = array("" => "Ano") + $years;
	$form['birth_year'] = array(
		'#title' => "",
		'#type' => 'select',
		'#options' => $years,
        '#attributes' => array('tabindex' => '5'),
	);
	
	$form['email'] = array(
		'#title' => "Email",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu email'),
			'autocomplete' => 'off',
			'tabindex' => '6',
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
			'tabindex' => '7',
        )
	);
	$form['phone2'] = array(
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu celular'),
			'autocomplete' => 'off',
			'size' => 9,
			'tabindex' => '8',
        )
	);	
	 $form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'CADASTRAR',
		'#attributes' => array(
			'tabindex' => '8',
        )
	);

	return $form;
}
function astrocentro_br_app_form_lp1owngoogle_mobile($form, &$form_state){

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
	$form['phone1'] = array(
		'#title' => "Telefone celular",
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t('DDD'),
			'autocomplete' => 'off',
			'size' => 2,
			'maxlength' => 2,
			'tabindex' => '7',
        )
	);
	$form['phone2'] = array(
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu celular'),
			'autocomplete' => 'off',
			'size' => 9,
			'tabindex' => '8',
        )
	);	

	$form['age'] = array(
		'#title' => "Mais de 18 anos?",
		'#required' => true,
		'#type' => 'checkbox',
        '#attributes' => array(
			'tabindex' => '4',
		)
	);
	
	 $form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'CADASTRAR',
		'#attributes' => array(
			'tabindex' => '5',
        )
	);

	return $form;
}
function astrocentro_br_app_form_lp1owngoogle_validate($form, &$form_state){
		
		// Validate form field and set error message
		/*if(!valid_email_address($form_state['values']['email']) || empty($form_state['values']['email']))
			form_set_error('astrocentro_br_app_form_lp_mediastay][email', 'Digite seu email.');

		if(empty($form_state['values']['firstname']))
			form_set_error('astrocentro_br_app_form_lp_mediastay][' . LANGUAGE_NONE . '][0][firstname', t('Digite seu nome'));
			
		if(empty($form_state['values']['lastname']))
			form_set_error('astrocentro_br_app_form_lp_mediastay][' . LANGUAGE_NONE . '][0][lastname', t('Digite seu sobrenome'));*/
}
function astrocentro_br_app_form_lp1owngoogle_submit($form, &$form_state){
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
		
		$telephone = $form_state['values']['phone1'].$form_state['values']['phone2'];
		$telephone = str_replace (' ', '', $telephone);
		$telephone = str_replace ('-', '', $telephone);
		$telephone = str_replace ('(', '', $telephone);
		$telephone = str_replace (')', '', $telephone);
		
		$birth_date = $form_state['values']["birth_day"].'-'.$form_state['values']["birth_month"].'-'.$form_state['values']["birth_year"];
		$birth_date_ws = date_create($birth_date);
		
		$age_requirement = 19;
		
		$email = $form_state['values']["email"];
		if (strnatcmp(phpversion(),'5.3') <= 0){ 
			$create_login_prospect = split("@",$email);
			$login_prospect = $create_login_prospect[0];
		}else{ 
			$login_prospect = strstr($email, '@', true);
		}
		
		$login_prospect = substr($login_prospect, 0, 16);
		
$subscription = array();
$subscription[] = ASTROCENTRO_BR_COM_WS_OWNGOOGLE_API_KEY;
$subscription[] = $login_prospect;
$subscription[] = $email;
$subscription[] = $login_prospect;
$subscription[] = $form_state['values']["firstname"];
$subscription[] = "0055".$telephone;
$subscription[] = "por";
$subscription[] = "bra";
$subscription[] = "1";
$subscription[] = 'v2_8262';
$subscription[] = 'v2_8262';
$subscription[] = "hdk_prospect";
$subscription[] = $form_state['values']["civility"];
$subscription[] = $form_state['values']["lastname"];
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = date_format($birth_date_ws, 'Y-m-d');
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = "1270";
$subscription[] = "owngoogle_lp";

		$data_s = '?method=create_generic_prospect_v1&args[]='.implode('&args[]=', $subscription);

watchdog("astrocentro_br_webservice_prospect_owngoogle1", "call {$ws}{$data_s}");

		$datetime2 = new DateTime(date('Y-m-d'));
		
		$timestamp_from = (int) $birth_date_ws->format('U');
		$timestamp_to = (int) $datetime2->format('U');
		$difference = (int) round(($timestamp_to - $timestamp_from)/(60*60*24*365));
		
		if($difference >= $age_requirement){
		
			$result = drupal_http_request($ws.$data_s, array('method' => "get"));
		
			//check if the lead is already inserted on DB
			$where2check = $result->data;
			$lead_already_db = strpos($where2check, 'Problema encontrado');
			
			variable_del('lead_status');
			variable_del('lead_status_message');
			
			if ($lead_already_db === false) {
				$confirmation_msg = variable_set('lead_status', 'PARABÉNS OFERTA GARANTIDA!');
				$paragraphe_msg = variable_set('lead_status_message', 'Um consultor do Astrocentro vai ligar no horário comercial para agendar sua consulta. Até breve!');
				$form_state['redirect'] = 'lp1owngoogle-c';
			}else{
				$confirmation_msg = variable_set('lead_status', 'OCORREU UM ERRO TÉCNICO');
				$paragraphe_msg = variable_set('lead_status_message', 'Ligue para nós para garantir sua oferta. Até breve!');
				$form_state['redirect'] = 'lp1owngoogle-c';
			}
			
		}else{
			$confirmation_msg = variable_set('lead_status', 'OFERTA VÁLIDA PARA MAIORES DE 18 ANOS');
			$paragraphe_msg = variable_set('lead_status_message', '');
			$form_state['redirect'] = 'lp1owngoogle-c';
		}
		
		// reset form
		/*$form_state['input'] = array();
		$form_state['rebuild'] = TRUE;*/
		
		/*debug*/
		global $user;
		if($user->uid == 1){
			echo "<pre>";var_dump($ws.$data_s);echo "</pre>";
			echo "<pre>";var_dump($result);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($telephone);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($birth_date);echo "</pre>";
			echo "<pre>";var_dump($birth_date_ws);echo "</pre>";
			echo "<pre>";var_dump($difference);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($login_prospect);echo "</pre>";
			echo "<pre>";var_dump($confirmation_msg);echo "</pre>";
			die();
		}
	}
}
function astrocentro_br_app_form_lp1owngoogle_mobile_submit($form, &$form_state){
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
		
		$telephone = $form_state['values']['phone1'].$form_state['values']['phone2'];
		$telephone = str_replace (' ', '', $telephone);
		$telephone = str_replace ('-', '', $telephone);
		$telephone = str_replace ('(', '', $telephone);
		$telephone = str_replace (')', '', $telephone);
		
		$email = $form_state['values']["email"];
		if (strnatcmp(phpversion(),'5.3') <= 0){ 
			$create_login_prospect = split("@",$email);
			$login_prospect = $create_login_prospect[0];
		}else{ 
			$login_prospect = strstr($email, '@', true);
		}
		
		$login_prospect = substr($login_prospect, 0, 16);
		
		$family = "owngoogle_lp";
		
$subscription = array();
$subscription[] = ASTROCENTRO_BR_COM_WS_OWNGOOGLE_API_KEY;
$subscription[] = $login_prospect;
$subscription[] = $email;
$subscription[] = $login_prospect;
$subscription[] = $form_state['values']["firstname"];
$subscription[] = "0055".$telephone;
$subscription[] = "por";
$subscription[] = "bra";
$subscription[] = "1";
$subscription[] = 'v2_7899';
$subscription[] = '';
$subscription[] = "hdk_prospect";
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = '';
$subscription[] = "1270";
$subscription[] = $family;

		$data_s = '?method=create_generic_prospect_v1&args[]='.implode('&args[]=', $subscription);

watchdog("astrocentro_br_webservice_prospect_owngoogle1_mobile_form", "call {$ws}{$data_s}");
			
		$result = drupal_http_request($ws.$data_s, array('method' => "get"));
			
		//check if the lead is already inserted on DB
		$where2check = $result->data;
		$lead_already_db = strpos($where2check, 'Problema encontrado');
			
			variable_del('lead_status');
			variable_del('lead_status_message');
			
			if ($lead_already_db === false) {
				$confirmation_msg = variable_set('lead_status', 'PARABÉNS OFERTA GARANTIDA!');
				$paragraphe_msg = variable_set('lead_status_message', 'Um consultor do Astrocentro vai ligar no horário comercial para agendar sua consulta. Até breve!');
				$form_state['redirect'] = 'lp1owngoogle-c';
			}else{
				$confirmation_msg = variable_set('lead_status', 'OCORREU UM ERRO TÉCNICO');
				$paragraphe_msg = variable_set('lead_status_message', 'Ligue para nós para garantir sua oferta. Até breve!');
				$form_state['redirect'] = 'lp1owngoogle-c';
			}
		
		/*debug*/
		global $user;
		if($user->uid == 1){
			echo "<pre>";var_dump($ws.$data_s);echo "</pre>";
			echo "<pre>";var_dump($result);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($login_prospect);echo "</pre>";
			echo "<pre>";var_dump($confirmation_msg);echo "</pre>";
			die();
		}
	}
}
function astrocentro_br_app_lp1owngoogle_ok_page(){

$confirmation_msg = variable_get('lead_status','');
$paragraphe_msg = variable_get('lead_status_message','');

$content = "
	
	<div id='landing_page' class='row row-offset-0'>
	
		<div id='lp_header' class='col-lg-12'>
			<img src='" . path_to_theme() . "/images/commom/logo-astrocentro-v2.png' alt='Astrocentro, consultorio esotérico 24 horas' class='img-responsive img-center' />
		</div>
		
		<section class='row row-offset-0'>
			<div id='promo' class='col-xs-12 hidden-xs hidden-md hidden-sm col-lg-8 text-center'>
				<div class='titles'>
					<h1>TAROT POR TELEFONE</h1>
					<ul class='list-unstyled'>
						<li>Os melhores astrólogos, videntes e tarólogos.</li>
						<li>24h por dia por telefone. Pergunte o que quiser.</li>
						<li>Atendimento na hora ou agendado. 100% confidencial.</li>
					</ul>
					<h2>CONSULTA <span>10 MIN<em class='color-yellow'>**</em> = R$1,00</span></h2>
					<h3>no cartão de crédito</h3>
				</div>
			</div>
			
			<div id='lp_confirmation' class='col-lg-4 col-xs-12 bg-blue text-center'>
				<h1>" . $confirmation_msg . "</h1>
				<p>" . $paragraphe_msg . "</p>

				<div>
			<a href='tel:+551132301299'>
					<h5>QUER SE CONSULTAR AGORA</h5>
					<h4>LIGUE PARA ASTROCENTRO</h4>
					<h4>(11) 3230-1299</h4>
			</a>
				</div>
			</div>
			
			<div id='promo' class='col-xs-12 col-lg-8 hidden-md hidden-sm hidden-lg text-center'>
				<div class='titles'>
					<h1>TAROT POR TELEFONE</h1>
					<ul class='list-unstyled'>
						<li>Os melhores astrólogos, videntes e tarólogos.</li>
						<li>24h por dia por telefone. Pergunte o que quiser.</li>
						<li>Atendimento na hora ou agendado. 100% confidencial.</li>
					</ul>
					<h2>CONSULTA <span>10 MIN* = R$1,00</span></h2>
					<h3>no cartão de crédito</h3>
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
	<p><small><em class='color-yellow'>**</em> A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3230-1299). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	
	$content.="<!-- Google Code for Leads Conversion Page -->
<script type='text/javascript'>
/* <![CDATA[ */
var google_conversion_id = 1006044158;
var google_conversion_language = 'en';
var google_conversion_format = '3';
var google_conversion_color = 'ffffff';
var google_conversion_label = 'TUFhCNKNuAYQ_ofc3wM';
var google_conversion_value = 0;
var google_remarketing_only = false;
/* ]]> */
</script>
<script type='text/javascript' src='//www.googleadservices.com/pagead/conversion.js'>
</script>
<noscript>
<div style='display:inline;'>
<img height='1' width='1' style='border-style:none;' alt='' src='//www.googleadservices.com/pagead/conversion/1006044158/?value=0&amp;label=TUFhCNKNuAYQ_ofc3wM&amp;guid=ON&amp;script=0'/>
</div>
</noscript>";
	
	return $content;

}


//******************************** Landing page Own Google Adwords 02 // nouveau webservice
function astrocentro_br_app_lp2owngoogle_page(){

	$include_form = drupal_get_form('astrocentro_br_app_form_lp2owngoogle');

	$content = "
	
	<style>

@font-face {
    font-family: 'Avant Garde CE';
    src: url('avant-garde-ce-1361851277.ttf');
}
@font-face {
    font-family: 'Avant Garde CE Bold';
    font-weight: bold;
    src: url('avant_garde_ce_gothic_demi.ttf');
}

div#lp_txt > p{font-family: 'Avant Garde CE', Helvetica, Arial, sans-serif; color:#ffffff; font-size:18px; text-align:center; line-height:24px; margin-top:65px;}
div#lp_txt > p strong{font-family: 'Avant Garde CE Bold', Helvetica, Arial, sans-serif; font-weight: bold;}

div#lp_btn {position:relative;}
div#lp_btn > p{font-family: 'Avant Garde CE', Helvetica, Arial, sans-serif;color:#d723e7; font-size:22px; position:absolute; bottom:30px; left:30px; width:190px;}
div#lp_btn > p strong{font-family: 'Avant Garde CE Bold', Helvetica, Arial, sans-serif;}
	
#lp_content{ background:url(" . path_to_theme() . "/images/lp2owngoogle/bg.jpg) center no-repeat ; height:569px; width:980px}
#lp_txt{ background:url(" . path_to_theme() . "/images/lp2owngoogle/promo.png) no-repeat ;margin:8px 0px 0px 60px;width:587px;float:left; height:300px;}

#lp_col_right{ background:url(" . path_to_theme() . "/images/lp2owngoogle/right.png) ; width:326px; height:595px; float:right; margin-top:-11px;}
#lp_btn{ background:url(" . path_to_theme() . "/images/lp2owngoogle/btn_1.png) no-repeat ; height:129px;  margin:22px 0 0 41px;}
	
	</style>
	<div id='landing_page'>
	

	<div id='lp_header'>   
		<div id='lp_logo'><a href='http://www.astrocentro.com.br'><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='Astrocentro, Os melhores esotéricos do Brasil' /></a></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'>
			<p>Os melhores astrólogos, videntes e tarólogos,<br /><strong>24h por dia por telefone.</strong> Pergunte o que quiser. Atendimento na hora ou agendado. <strong>100% confidencial.</strong></p>
		</div>

		<div id='lp_col_right'>
			<div id='lp_btn'><p>Uma consulta de <strong>10 min por R$ 1,00</strong></p></div>
			<div id='lp_form'>";
	$content .= drupal_render($include_form);
	$content .= "</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8426). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	return $content;

}
function astrocentro_br_app_form_lp2owngoogle($form, &$form_state){

	$active = array(0 => t('Mulher'), 1 => t('Homem'));

	$form['civility'] = array(
		'#type' => 'radios',
		'#default_value' => 0, 
		'#options' => $active,
		'#description' => "",
		'#title' => ""
	);

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

	$form['lastname'] = array(
		'#title' => "Sobrenome",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t(''),
            'placeholder' => t('Digite seu sobrenome'),
			'autocomplete' => 'off',
			'tabindex' => '2',
        )
	);

	$form['birthdate'] = array(
		'#title' => "Data de nascimento",
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array('tabindex' => '3'),
	);
	
	$form['email'] = array(
		'#title' => "Email",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu email'),
			'autocomplete' => 'off',
			'tabindex' => '4',
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
			'tabindex' => '5',
        )
	);
	$form['phone2'] = array(
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu celular'),
			'autocomplete' => 'off',
			'size' => 9,
			'tabindex' => '6',
        )
	);	

	$form['submit'] = array(
		'#type' => 'image_button',
		'#src' => path_to_theme() . "/images/lp2owngoogle/btn_2.png"
	);

	return $form;
}
function astrocentro_br_app_form_lp2owngoogle_validate($form, &$form_state){
	
		
		// Validate form field and set error message
		if(!valid_email_address($form_state['values']['email']) || empty($form_state['values']['email']))
			form_set_error('astrocentro_br_app_form_lp_mediastay][email', 'Digite seu email.');

		if(empty($form_state['values']['firstname']))
			form_set_error('astrocentro_br_app_form_lp_mediastay][' . LANGUAGE_NONE . '][0][firstname', t('Digite seu nome'));
			
		if(empty($form_state['values']['lastname']))
			form_set_error('astrocentro_br_app_form_lp_mediastay][' . LANGUAGE_NONE . '][0][lastname', t('Digite seu sobrenome'));
			
		if(empty($form_state['values']['phone1']))
			form_set_error('astrocentro_br_app_form_lp_mediastay][' . LANGUAGE_NONE . '][0][phone1', t('Digite seu DDD'));
		
		$phone_check = $form_state['values']['phone2'];
		if (strlen($phone_check) > 0) 
			$phone_check = str_replace (' ', '', $phone_check);
			$phone_check = str_replace ('-', '', $phone_check);
			$phone_check = str_replace ('(', '', $phone_check);
			$phone_check = str_replace (')', '', $phone_check);
			$phone_check = str_replace ('[', '', $phone_check);
			$phone_check = str_replace (']', '', $phone_check);
			$phone_check = str_replace ('{', '', $phone_check);
			$phone_check = str_replace ('}', '', $phone_check);
}
function astrocentro_br_app_form_lp2owngoogle_submit($form, &$form_state){
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
		
		
		$birth_date = $form_state['values']["birthdate"];
		$birth_date_n = str_replace('/', '-', $birth_date);
		$birth_date_m = new DateTime($birth_date_n);
		$age_requirement = 19;

		
		$email = $form_state['values']["email"];
		if (strnatcmp(phpversion(),'5.3') <= 0){ 
			$create_login_prospect = split("@",$email);
			$login_prospect = $create_login_prospect[0];
		}else{ 
			$login_prospect = strstr($email, '@', true);
		}
		
		$login_prospect = substr($login_prospect, 0, 16);
		
		$family = "owngoogle_lp";
		
$subscription = array();
$subscription[] = ASTROCENTRO_BR_COM_WS_OWNGOOGLE_API_KEY; // API Key
$subscription[] = $login_prospect; //login
$subscription[] = $email; //email
$subscription[] = $login_prospect; // password
$subscription[] = $form_state['values']["firstname"]; //firstname
$subscription[] = "0055".$form_state["values"]["phone1"].$form_state["values"]["phone2"]; //phonenumber
$subscription[] = "por"; //t9n
$subscription[] = "bra"; //i18n
$subscription[] = "1"; //population
$subscription[] = ''; //tracker_id string $tracker_id context tracker_id (optional, default value )
$subscription[] = ''; //tracker_id_params string $tracker_id_params context tracker_id_params (optional, default value )
$subscription[] = "hdk_prospect"; //factory_channel string $factory_channel factory channel (optional, default value hdk_prospect)
$subscription[] = $form_state['values']["civility"]; //ln1_gender inetger $ln1_gender gender (optional, default value NULL)
$subscription[] = $form_state['values']["lastname"]; //ln1_lastname string $ln1_lastname last name (optional, default value )
$subscription[] = ''; //ln2 string $ln2 address (optional, default value )
$subscription[] = ''; //ln3 string $ln3 address (optional, default value )
$subscription[] = ''; //ln4 string $ln4 address (optional, default value )
$subscription[] = ''; //ln6_zip string $ln6_zip zip (optional, default value )
$subscription[] = ''; //ln6_city string $ln6_city city (optional, default value )
$subscription[] = ''; //ln7_country string $ln7_country country (optional, default value )
$subscription[] = date_format($birth_date_n, 'Y-m-d'); //birthdate string $birthdate birth date (optional, default value )
$subscription[] = ''; //mobile_phonenumber string $mobile_phonenumber mobile phonenumber (optional, default value)
$subscription[] = ''; //bof_user_keyid integer $bof_user_keyid bof user keyid (optional, default value )
$subscription[] = ''; //json_data string $json_data json_data (optional, default value )
$subscription[] = "1270"; //root_directory_keyid integer $root_directory_keyid root directory keyid (optional, default value )
$subscription[] = $family; //family string $family family (optional, default value ) // here the campaign_type

//$data_s ="?method=create_generic_prospect_v1&args[]=".$subscription[0]."&args[]=".$subscription[1]."&args[]=".$subscription[2]."&args[]=".$subscription[3]."&args[]=".$subscription[4]."&args[]=".$subscription[5]."&args[]=".$subscription[6]."&args[]=".$subscription[7]."&args[]=".$subscription[8]."&args[]=".$subscription[9]."&args[]=".$subscription[10]."&args[]=".$subscription[11]."&args[]=".$subscription[12]."&args[]=".$subscription[13]."&args[]=".$subscription[14]."&args[]=".$subscription[15]."&args[]=".$subscription[16]."&args[]=".$subscription[17]."&args[]=".$subscription[18]."&args[]=".$subscription[19]."&args[]=".$subscription[20]."&args[]=".$subscription[21]."&args[]=".$subscription[22]."&args[]=".$subscription[23]."&args[]=".$subscription[24]."&args[]=".$subscription[25];

		$data_s = '?method=create_generic_prospect_v1&args[]='.implode('&args[]=', $subscription);

watchdog("astrocentro_br_webservice_prospect_owngoogle2", "call {$ws}{$data_s}");

		$datetime2 = new DateTime(date('Y-m-d'));
		//$difference = $birth_date_m->diff($datetime2); //doesn't work on pre-prod environment
		
		$timestamp_from = (int) $birth_date_m->format('U');
		$timestamp_to = (int) $datetime2->format('U');
		$difference = (int) round(($timestamp_to - $timestamp_from)/(60*60*24*365));
		
		if($difference >= $age_requirement){
		
			$result = drupal_http_request($ws.$data_s, array('method' => "get"));
		
			//check if the lead is already inserted on DB
			$where2check = $result->data;
			$lead_already_db = strpos($where2check, 'Problema encontrado');
			
			if ($lead_already_db === false) {
					$test_already_db1 = "nouveau lead";
					$form_state['redirect'] = 'lp2owngoogle-c';
			}else{
					$test_already_db2 = "deja en base";
					$form_state['redirect'] = 'lp2owngoogle-c18';
			}
			
		} else {
		
			$file_name = path_to_theme(). "/csv/lp2owngoogle-18ans.csv";
			if (file_exists($file_name))  {
				$fp = fopen($file_name, 'a');
				foreach ($subscription['json_data'] as $line) {
					fputcsv($fp, explode('\n', $line), ';', '"');
					
				}
			fclose($fp);
			
			$form_state['redirect'] = 'lp2owngoogle-c18'; //-18
			}else{
				$form_state['redirect'] = 'lp2owngoogle-c18'; //-18
			}
		}
		
		
		// reset form
		$form_state['input'] = array();
		$form_state['rebuild'] = TRUE;
		
		//debug
		/* */ global $user;
		if($user->uid == 1){
			echo "<pre>";var_dump($ws.$data_s);echo "</pre>";
			echo "<pre>";var_dump($result);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($birth_date_n);echo "</pre>";
			echo "<pre>";var_dump($birth_date_m);echo "</pre>";
			echo "<pre>";var_dump($difference);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($login_prospect);echo "</pre>";
			echo "<pre>";var_dump($test_already_db1);echo "</pre>";
			echo "<pre>";var_dump($test_already_db2);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($file_name);echo "</pre>";
			echo "<pre>";var_dump(file_exists($file_name));echo "</pre>";
			echo "<pre>";var_dump($fp);echo "</pre>";
			die();
		}
		
		/* if($result->code == "200")
			$form_state['redirect'] = 'lp2owngoogle-c'; */
	}
}
function astrocentro_br_app_lp2owngoogle_ok_page(){

	$content = "
	
	<style>

@font-face {
    font-family: 'Avant Garde CE';
    src: url('avant-garde-ce-1361851277.ttf');
}
@font-face {
    font-family: 'Avant Garde CE Bold';
    font-weight: bold;
    src: url('avant_garde_ce_gothic_demi.ttf');
}

div#lp_txt > p{font-family: 'Avant Garde CE', Helvetica, Arial, sans-serif; color:#ffffff; font-size:18px; text-align:center; line-height:24px; margin-top:65px;}
div#lp_txt > p strong{font-family: 'Avant Garde CE Bold', Helvetica, Arial, sans-serif; font-weight: bold;}

#lp_content{ background:url(" . path_to_theme() . "/images/lp2owngoogle/bg.jpg) center no-repeat ; height:569px; width:980px}
#lp_txt{ background:url(" . path_to_theme() . "/images/lp2owngoogle/promo.png) no-repeat ;margin:8px 0px 0px 60px;width:587px;float:left; height:300px;}

#lp_col_right{ background:url(" . path_to_theme() . "/images/lp2owngoogle/right.png) ; width:326px; height:595px; float:right; margin-top:-11px;}

#lp_confirmation{margin-top:84px; width:340px; background: url(" . path_to_theme() . "/images/lp2owngoogle/txt_confirmation.png) top center no-repeat; height:231px; position:relative;}
	
	</style>
	
	<div id='landing_page'>

	<div id='lp_header'>   
		<div id='lp_logo'><a href='http://www.astrocentro.com.br' ><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='' /></a></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'>
			<p>Os melhores astrólogos, videntes e tarólogos,<br /><strong>24h por dia por telefone.</strong> Pergunte o que quiser. Atendimento na hora ou agendado. <strong>100% confidencial.</strong></p>
		</div>

		<div id='lp_col_right'>
			<div id='lp_confirmation'>

				<h1>PARABÉNS OFERTA GARANTIDA!</h1>

				<h2>Um consultor do Astrocentro vai ligar-lhe no horário comercial para agendar sua consulta. Até breve!</h2>
				
				<img src='" . path_to_theme() . "/images/lp1owngoogle/ligaragora.png' />

			</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8426). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	
	$content.="<!-- Google Code for Leads Conversion Page -->
<script type='text/javascript'>
/* <![CDATA[ */
var google_conversion_id = 1006044158;
var google_conversion_language = 'en';
var google_conversion_format = '3';
var google_conversion_color = 'ffffff';
var google_conversion_label = 'TUFhCNKNuAYQ_ofc3wM';
var google_conversion_value = 0;
var google_remarketing_only = false;
/* ]]> */
</script>
<script type='text/javascript' src='//www.googleadservices.com/pagead/conversion.js'>
</script>
<noscript>
<div style='display:inline;'>
<img height='1' width='1' style='border-style:none;' alt='' src='//www.googleadservices.com/pagead/conversion/1006044158/?value=0&amp;label=TUFhCNKNuAYQ_ofc3wM&amp;guid=ON&amp;script=0'/>
</div>
</noscript>";
	
	return $content;

}
function astrocentro_br_app_lp2owngoogle_ok18_page(){

	$content = "
	
	<style>

@font-face {
    font-family: 'Avant Garde CE';
    src: url('avant-garde-ce-1361851277.ttf');
}
@font-face {
    font-family: 'Avant Garde CE Bold';
    font-weight: bold;
    src: url('avant_garde_ce_gothic_demi.ttf');
}

div#lp_txt > p{font-family: 'Avant Garde CE', Helvetica, Arial, sans-serif; color:#ffffff; font-size:18px; text-align:center; line-height:24px; margin-top:65px;}
div#lp_txt > p strong{font-family: 'Avant Garde CE Bold', Helvetica, Arial, sans-serif; font-weight: bold;}

#lp_content{ background:url(" . path_to_theme() . "/images/lp2owngoogle/bg.jpg) center no-repeat ; height:569px; width:980px}
#lp_txt{ background:url(" . path_to_theme() . "/images/lp2owngoogle/promo.png) no-repeat ;margin:8px 0px 0px 60px;width:587px;float:left; height:300px;}

#lp_col_right{ background:url(" . path_to_theme() . "/images/lp2owngoogle/right.png) ; width:326px; height:595px; float:right; margin-top:-11px;}

#lp_confirmation{margin-top:84px; width:340px; background: url(" . path_to_theme() . "/images/lp2owngoogle/txt_confirmation.png) top center no-repeat; height:231px; position:relative;}
	
	</style>
	
	<div id='landing_page'>

	<div id='lp_header'>   
		<div id='lp_logo'><a href='http://www.astrocentro.com.br' ><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='' /></a></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'>
			<p>Os melhores astrólogos, videntes e tarólogos,<br /><strong>24h por dia por telefone.</strong> Pergunte o que quiser. Atendimento na hora ou agendado. <strong>100% confidencial.</strong></p>
		</div>

		<div id='lp_col_right'>
			<div id='lp_confirmation'>

				<h1>PARABÉNS OFERTA GARANTIDA!</h1>

				<h2>Um consultor do Astrocentro vai ligar-lhe no horário comercial para agendar sua consulta. Até breve!</h2>
				
				<img src='" . path_to_theme() . "/images/lp1owngoogle/ligaragora.png' />

			</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8426). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	
	return $content;

}


//******************************** Landing page Own Google Adwords 03 // ancien webservice
function astrocentro_br_app_lp3owngoogle_page(){

	$include_form = drupal_get_form('astrocentro_br_app_form_lp3owngoogle');

	$content = "
	
	<style>

@font-face {
    font-family: 'Avant Garde CE';
    src: url('avant-garde-ce-1361851277.ttf');
}
@font-face {
    font-family: 'Avant Garde CE Bold';
    font-weight: bold;
    src: url('avant_garde_ce_gothic_demi.ttf');
}

div#lp_txt > p{font-family: 'Avant Garde CE', Helvetica, Arial, sans-serif; color:#ffffff; font-size:18px; text-align:center; line-height:24px; margin-top:70px;}
div#lp_txt > p strong{font-family: 'Avant Garde CE Bold', Helvetica, Arial, sans-serif; font-weight: bold;}

div#lp_btn {position:relative;}
div#lp_btn > p{font-family: 'Avant Garde CE', Helvetica, Arial, sans-serif; color:#000000; font-size:20px; position:absolute; top:15px; left:15px; }
div#lp_btn > span {display:none;}

#lp_content{ background:url(" . path_to_theme() . "/images/lp3owngoogle/bg.jpg) 0 0 no-repeat ; height:569px; width:980px}
#lp_txt{ background:url(" . path_to_theme() . "/images/lp3owngoogle/promo.gif) top center no-repeat ;margin:8px 0px 0px 60px;width:587px;float:left; height:141px;}

#lp_col_right{ background:url(" . path_to_theme() . "/images/lp3owngoogle/right.png) ; width:326px; height:595px; float:right; margin-top:-11px;}
#lp_btn{ background:url(" . path_to_theme() . "/images/lp3owngoogle/btn_1.png) no-repeat ; height:129px;  margin:22px 0 0 41px;}
	
	</style>
	
	<div id='landing_page'>

	<div id='lp_header'>   
		<div id='lp_logo'><a href='http://www.astrocentro.com.br'><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='Astrocentro, Os melhores esotéricos do Brasil' /></a></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'>
			<p>Os melhores astrólogos, videntes e tarólogos,<br /><strong>24h por dia por telefone.</strong> Pergunte o que quiser. Atendimento na hora ou agendado. <strong>100% confidencial.</strong></p>
		</div>

		<div id='lp_col_right'>
			<div id='lp_btn'>
				<p>Sim eu quero aproveitar</p>
				<span>Uma consulta de 10 min por R$ 1,00</span>
			</div>
			<div id='lp_form'>";
	$content .= drupal_render($include_form);
	$content .= "</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8426). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	return $content;

}
function astrocentro_br_app_form_lp3owngoogle($form, &$form_state){

	$active = array(0 => t('Mulher'), 1 => t('Homem'));

	$form['civility'] = array(
		'#type' => 'radios',
		'#default_value' => 0, 
		'#options' => $active,
		'#description' => "",
		'#title' => ""
	);

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

	$form['lastname'] = array(
		'#title' => "Sobrenome",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t(''),
            'placeholder' => t('Digite seu sobrenome'),
			'autocomplete' => 'off',
			'tabindex' => '2',
        )
	);

	$form['birthdate'] = array(
		'#title' => "Data de nascimento",
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array('tabindex' => '3'),
	);
	
	$form['email'] = array(
		'#title' => "Email",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu email'),
			'autocomplete' => 'off',
			'tabindex' => '4',
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
			'tabindex' => '5',
        )
	);
	$form['phone2'] = array(
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu celular'),
			'autocomplete' => 'off',
			'size' => 9,
			//'maxlength' => 9,
			'tabindex' => '6',
        )
	);	

	$form['submit'] = array(
		'#type' => 'image_button',
		'#src' => path_to_theme() . "/images/lp3owngoogle/btn_2.png"
	);

	return $form;
}
function astrocentro_br_app_form_lp3owngoogle_validate($form, &$form_state){
	
		
		// Validate form field and set error message
		if(!valid_email_address($form_state['values']['email']) || empty($form_state['values']['email']))
			form_set_error('astrocentro_br_app_form_lp3owngoogle][email', 'Digite seu email.');

		if(empty($form_state['values']['firstname']))
			form_set_error('astrocentro_br_app_form_lp3owngoogle][' . LANGUAGE_NONE . '][0][firstname', t('Digite seu nome'));
			
		if(empty($form_state['values']['lastname']))
			form_set_error('astrocentro_br_app_form_lp3owngoogle][' . LANGUAGE_NONE . '][0][lastname', t('Digite seu sobrenome'));
			
		if(empty($form_state['values']['phone1']))
			form_set_error('astrocentro_br_app_form_lp3owngoogle][' . LANGUAGE_NONE . '][0][phone1', t('Digite seu DDD'));
		
		$phone_check = $form_state['values']['phone2'];
		if (strlen($phone_check) > 0) 
			$phone_check = str_replace (' ', '', $phone_check);
			$phone_check = str_replace ('-', '', $phone_check);
			$phone_check = str_replace ('(', '', $phone_check);
			$phone_check = str_replace (')', '', $phone_check);
			$phone_check = str_replace ('[', '', $phone_check);
			$phone_check = str_replace (']', '', $phone_check);
			$phone_check = str_replace ('{', '', $phone_check);
			$phone_check = str_replace ('}', '', $phone_check);
			}
function astrocentro_br_app_form_lp3owngoogle_submit($form, &$form_state){
	if(!form_get_errors()){
	
		switch(WENGO_ENV){
			case 'prod':
				$ws = "http://ws.wengo.fr/yatesvi/server.php";
				break;
			case 'preprod':
				$ws = "http://ws.wengo.fr.geekic.com/yatesvi/server.php";
				break;
			default:
				$ws = "http://ws.wengo.fr.center.localdev4/yatesvi/server.php";
				break;
		}
		
		$date_today = date("Y-m-d");
		$date_campaign = date("Y-m-d", time() + 86400);
		$date_end_campaign = date("Y-m-d", time() + 345600);
		
		$birth_date = $form_state['values']["birthdate"];
		$birth_date_n = str_replace('/', '-', $birth_date);
		$birth_date_m = new DateTime($birth_date_n);
		$age_requirement = 19;

		$subscription = array();
		$subscription['t9n'] = 'por'; // t9n
		$subscription['date_start'] = $date_today; // 
		$subscription['date_end'] = $date_end_campaign; // date du jour + 4 jours
		$subscription['hour_start'] = '13:00'; // 
		$subscription['hour_end'] = '23:59'; // 
		$subscription['campaign_name'] = 'Affiliation_AppelsSortants_OwnGoogle_3_'.$date_today; // nom campagne
		$subscription['campaign_type'] = 'prospect_owngoogle'; // type
		$subscription['extension_from'] = '00551132301299'; // extension_from
		$subscription['extension_to'] = '0055'.$form_state['values']["phone1"].$form_state['values']["phone2"]; // client
		$subscription['json_data'] = array(
			'date_crea'=> $date_today,
			'civility'=> $form_state['values']["civility"],
			'firstname'=> $form_state['values']["firstname"],
			'lastname'=> $form_state['values']["lastname"],
			'email'=> $form_state['values']["email"],
			'birthdate'=> $birth_date_n,
		);
		$subscription['directory_keyid'] = '1270'; // catégorie
		$subscription['operator'] = NULL; // opérateur
		$data_s = "?method=add_hdk_outbound_call_v1&args[0]=".ASTROCENTRO_BR_COM_WS_OWNGOOGLE_API_KEY."&args[1]=".json_encode($subscription);

		$datetime2 = new DateTime(date('Y-m-d'));
		//$difference = $birth_date_m->diff($datetime2); //doesn't work on pre-prod environment
		
		$timestamp_from = (int) $birth_date_m->format('U');
		$timestamp_to = (int) $datetime2->format('U');
		$difference = (int) round(($timestamp_to - $timestamp_from)/(60*60*24*365));
		
		
		if($difference >= $age_requirement){
			$result = drupal_http_request($ws.$data_s, array('method' => "get"));
		
			//check if the lead is already inserted on DB
			$where2check = $result->data;
			$lead_already_db = strpos($where2check, 'fails":1');
			
			if ($lead_already_db === false) {
					$test_already_db1 = "nouveau lead";
					$form_state['redirect'] = 'lp3owngoogle-c';
			}else{
					$test_already_db2 = "deja en base";
					$form_state['redirect'] = 'lp3owngoogle-c18';
			}
			
		}else{
			$form_state['redirect'] = 'lp3owngoogle-c18'; //-18
		}
		
		//debug
		/* global $user;
		if($user->uid == 1){
			var_dump($ws.$data_s);
			var_dump($result);
			var_dump($birth_date_n);
			var_dump($difference);
			var_dump($leads_under_18_file);
			var_dump($subscription);
			die();
		} */
		
		/* if($result->code == "200")
			$form_state['redirect'] = 'lp3owngoogle-c'; */
	}
}
function astrocentro_br_app_lp3owngoogle_ok_page(){

	$content = "
	
	<style>
#lp_content{ background:url(" . path_to_theme() . "/images/lp3owngoogle/bg.jpg) 0 0 no-repeat ; height:569px; width:980px}
#lp_txt{ background:url(" . path_to_theme() . "/images/lp3owngoogle/promo.png) top center no-repeat ;margin:8px 0px 0px 60px;width:587px;float:left; height:300px;}

#lp_col_right{ background:url(" . path_to_theme() . "/images/lp3owngoogle/right.png) ; width:326px; height:595px; float:right; margin-top:-11px;}

#lp_confirmation{margin-top:84px; width:340px; background: url(" . path_to_theme() . "/images/lp3owngoogle/txt_confirmation.png) top center no-repeat; height:231px; position:relative;}
	
	</style>
	
	<div id='landing_page'>

	<div id='lp_header'>   
		<div id='lp_logo'><a href='http://www.astrocentro.com.br' ><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='Astrocentro, Os melhores esotéricos do Brasil' /></a></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'></div>

		<div id='lp_col_right'>
			<div id='lp_confirmation'>

				<h1>PARABÉNS OFERTA GARANTIDA!</h1>

				<h2>Um consultor do Astrocentro vai ligar-lhe no horário comercial para agendar sua consulta. Até breve!</h2>
				
				<img src='" . path_to_theme() . "/images/lp1owngoogle/ligaragora.png' />

			</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8426). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	
	$content.="<!-- Google Code for Leads Conversion Page -->
<script type='text/javascript'>
/* <![CDATA[ */
var google_conversion_id = 1006044158;
var google_conversion_language = 'en';
var google_conversion_format = '3';
var google_conversion_color = 'ffffff';
var google_conversion_label = 'TUFhCNKNuAYQ_ofc3wM';
var google_conversion_value = 0;
var google_remarketing_only = false;
/* ]]> */
</script>
<script type='text/javascript' src='//www.googleadservices.com/pagead/conversion.js'>
</script>
<noscript>
<div style='display:inline;'>
<img height='1' width='1' style='border-style:none;' alt='' src='//www.googleadservices.com/pagead/conversion/1006044158/?value=0&amp;label=TUFhCNKNuAYQ_ofc3wM&amp;guid=ON&amp;script=0'/>
</div>
</noscript>";
	
	return $content;

}
function astrocentro_br_app_lp3owngoogle_ok18_page(){

	$content = "
	
	<style>
#lp_content{ background:url(" . path_to_theme() . "/images/lp3owngoogle/bg.jpg) 0 0 no-repeat ; height:569px; width:980px}
#lp_txt{ background:url(" . path_to_theme() . "/images/lp3owngoogle/promo.png) top center no-repeat ;margin:8px 0px 0px 60px;width:587px;float:left; height:300px;}

#lp_col_right{ background:url(" . path_to_theme() . "/images/lp3owngoogle/right.png) ; width:326px; height:595px; float:right; margin-top:-11px;}

#lp_confirmation{margin-top:84px; width:340px; background: url(" . path_to_theme() . "/images/lp3owngoogle/txt_confirmation.png) top center no-repeat; height:231px; position:relative;}
	
	</style>
	
	<div id='landing_page'>

	<div id='lp_header'>   
		<div id='lp_logo'><a href='http://www.astrocentro.com.br' ><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='Astrocentro, Os melhores esotéricos do Brasil' /></a></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'></div>

		<div id='lp_col_right'>
			<div id='lp_confirmation'>

				<h1>PARABÉNS OFERTA GARANTIDA!</h1>

				<h2>Um consultor do Astrocentro vai ligar-lhe no horário comercial para agendar sua consulta. Até breve!</h2>
				
				<img src='" . path_to_theme() . "/images/lp1owngoogle/ligaragora.png' />

			</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8426). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	
	return $content;

}


//******************************** Landing page Delas // ancien webservice
function astrocentro_br_app_lp_delas_page(){
	drupal_session_start();
	
	$_SESSION['campaign_phone_display'] = '(21) 3958-7182';
	
	$_SESSION['campaign_phone_call'] = '0055'.$_SESSION['campaign_phone_display'];
	$_SESSION['campaign_phone_call'] = str_replace (' ', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace ('(', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace (')', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace ('-', '', $_SESSION['campaign_phone_call']);

	$path = drupal_get_path('theme', 'astrocentro_br_mediastay');

	$include_form = drupal_get_form('astrocentro_br_app_form_lp_delas');

	$content = "
	<script type='text/javascript'>
	if (typeof jQuery == 'undefined') {
		alert('No Jquery loaded');
		var script = document.createElement('script');
		script.type = 'text/javascript';
		script.src = 'http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js';
		document.getElementsByTagName('head')[0].appendChild(script);
	}
	</script>
	
	<script type='text/javascript' src='/".$path."/js/jquery.maskedinput.min.js'></script>
	<script type='text/javascript' src='/".$path."/js/livevalidation_standalone.compressed.js'></script>
	
	<script type='text/javascript'>
		
		jQuery(function($){
		   jQuery('#edit-birthdate').mask('99/99/9999');
		});
		
		jQuery(document).ready(function ($) {
			
			var ddd = ['11', '12', '13', '14', '15', '16', '17', '18', '19', '21', '22', '24', '27', '28'];

			var txtElements = {};
			jQuery(':text').each(function(){
					idElement = $(this).attr('id'); 
					txtElements[idElement] = new LiveValidation( idElement );
					txtElements[idElement].add(Validate.Presence);
				});
				txtElements['edit-email'].add(Validate.Email);
				txtElements['edit-phone1'].add(Validate.Numericality, { minimum: 11 });
			 
			txtElements['edit-phone2'].add(Validate.Length, { minimum: 8 });
			txtElements['edit-phone2'].add(Validate.Numericality);
			txtElements['edit-birthdate'].add(Validate.Length, { minimum: 10, failureMessage: 'Data inválida' });
			
			//move focus to the end of input
			jQuery.fn.selectRange = function(start, end) {
				return this.each(function() {
					if (this.setSelectionRange) {
						this.focus();
						this.setSelectionRange(start, end);
					} else if (this.createTextRange) {
						var range = this.createTextRange();
						range.collapse(true);
						range.moveEnd('character', end);
						range.moveStart('character', start);
						range.select();
					}
				});
			};
			
			jQuery('#edit-phone1').blur(function() {
				var value = $( this ).val();
				if(jQuery.inArray(value, ddd) != -1){
					jQuery( '#edit-phone2' ).val('9');
					jQuery( '#edit-phone2' ).selectRange(1,2);
					jQuery( '#edit-phone2' ).attr('maxlength','9');
					jQuery( '#edit-phone2' ).attr('minlength','9');
					txtElements['edit-phone2'].add(Validate.Length, { minimum: 9 });
				}
				
				if(jQuery.inArray(value, ddd) == -1){
					jQuery( '#edit-phone2' ).val('');
					jQuery( '#edit-phone2' ).attr('maxlength','8');
					jQuery( '#edit-phone2' ).attr('minlength','8');
					txtElements['edit-phone2'].add(Validate.Length, { minimum: 8 });
				}
				
			});
		
		});
	</script>
	
	<div id='landing_page'>
	
	<div id='lp_content'>


		<div id='lp_txt'></div>

		<div id='lp_col_right'>
			<div id='lp_btn'></div>
			<div id='lp_form'>";
	$content .= drupal_render($include_form);
	$content .= "</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone ".$_SESSION['campaign_phone_display']."). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
</div><!--endlanding!-->

<script type='text/javascript'>
  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-35713232-2']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();
</script>
	
	";
	
	$url = file_get_contents('http://delas.ig.com.br/horoscopo/astrocentro_header_footer.html');
	$url = str_replace('<!-- FIM CONTEÚDO -->', $content, $url);
	$url = str_replace('<!-- REVER ESTA PARTE -->', '<link rel="stylesheet" type="text/css" href="/'.$path.'/css/style-delas.css"/>', $url);
	
	echo $url;
	
	//return $content;

	// return drupal_get_form('astrocentro_br_app_form_lp_mediastay');

}
function astrocentro_br_app_form_lp_delas($form, &$form_state){

	$active = array(0 => t('Mulher'), 1 => t('Homem'));

	$form['civility'] = array(
		'#type' => 'radios',
		'#default_value' => 0, 
		'#options' => $active,
		'#description' => "",
		'#title' => ""
	);

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

	$form['lastname'] = array(
		'#title' => "Sobrenome",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t(''),
            'placeholder' => t('Digite seu sobrenome'),
			'autocomplete' => 'off',
			'tabindex' => '2',
        )
	);
	

	$form['birthdate'] = array(
		'#title' => "Data de nascimento",
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array('tabindex' => '3'),
	);


	$form['email'] = array(
		'#title' => "Email",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu email'),
			'autocomplete' => 'off',
			'tabindex' => '4',
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
			'tabindex' => '5',
        )
	);
	$form['phone2'] = array(
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu celular'),
			'autocomplete' => 'off',
			'size' => 9,
			//'maxlength' => 9,
			'tabindex' => '6',
        )
	);	

	$form['submit'] = array(
		'#type' => 'image_button',
		'#src' => path_to_theme() . "/images/landing_mediastay/btn_2.png"
	);

	return $form;
}
function astrocentro_br_app_form_lp_delas_validate($form, &$form_state){
	
		
		// Validate form field and set error message
		
		if(!valid_email_address($form_state['values']['email']) || empty($form_state['values']['email']))
			form_set_error('astrocentro_br_app_form_lp_delas][email', 'Digite seu email.');

		if(empty($form_state['values']['firstname']))
			form_set_error('astrocentro_br_app_form_lp_delas][' . LANGUAGE_NONE . '][0][firstname', t('Digite seu nome'));
			
		if(empty($form_state['values']['lastname']))
			form_set_error('astrocentro_br_app_form_lp_delas][' . LANGUAGE_NONE . '][0][lastname', t('Digite seu sobrenome'));
			
		if(empty($form_state['values']['phone1']))
			form_set_error('astrocentro_br_app_form_lp_delas][' . LANGUAGE_NONE . '][0][phone1', t('Digite seu DDD'));
		
		$phone_check = $form_state['values']['phone2'];
		if (strlen($phone_check) > 0) 
			$phone_check = str_replace (' ', '', $phone_check);
			$phone_check = str_replace ('-', '', $phone_check);
			$phone_check = str_replace ('(', '', $phone_check);
			$phone_check = str_replace (')', '', $phone_check);
			$phone_check = str_replace ('[', '', $phone_check);
			$phone_check = str_replace (']', '', $phone_check);
			$phone_check = str_replace ('{', '', $phone_check);
			$phone_check = str_replace ('}', '', $phone_check);
}
function astrocentro_br_app_form_lp_delas_submit($form, &$form_state){
	if(!form_get_errors()){
	
		switch(WENGO_ENV){
			case 'prod':
				$ws = "http://ws.wengo.fr/yatesvi/server.php";
				break;
			case 'preprod':
				$ws = "http://ws.wengo.fr.geekic.com/yatesvi/server.php";
				break;
			default:
				$ws = "http://ws.wengo.fr.center.localdev4/yatesvi/server.php";
				break;
		}
		
		$date_today = date("Y-m-d");
		$date_campaign = date("Y-m-d", time() + 86400);
		$date_end_campaign = date("Y-m-d", time() + 345600);
		
		$birth_date = $form_state['values']["birthdate"];
		$birth_date_n = str_replace('/', '-', $birth_date);
		$birth_date_m = new DateTime($birth_date_n);
		$age_requirement = 19;

		$subscription = array();
		$subscription['t9n'] = 'por'; // t9n
		$subscription['date_start'] = $date_today; // 
		$subscription['date_end'] = $date_end_campaign; // date du jour + 4 jours
		$subscription['hour_start'] = '13:00'; // 
		$subscription['hour_end'] = '23:59'; // 
		$subscription['campaign_name'] = 'Affiliation_AppelsSortants_Delas_'.$date_today; // nom campagne
		$subscription['campaign_type'] = 'prospect_ig_delas'; // type
		$subscription['extension_from'] = '00552139587182'; // extension_from
		$subscription['extension_to'] = '0055'.$form_state['values']["phone1"].$form_state['values']["phone2"]; // client
		$subscription['json_data'] = array(
			'date_crea'=> $date_today,
			'civility'=> $form_state['values']["civility"],
			'firstname'=> $form_state['values']["firstname"],
			'lastname'=> $form_state['values']["lastname"],
			'email'=> $form_state['values']["email"],
			'birthdate'=> $birth_date_n,
		);
		$subscription['directory_keyid'] = '1270';
		$subscription['operator'] = NULL;
		$data_s = "?method=add_hdk_outbound_call_v1&args[0]=".ASTROCENTRO_BR_COM_WS_IG_DELAS_API_KEY."&args[1]=".json_encode($subscription);

				
		$datetime2 = new DateTime(date('Y-m-d'));
		
		$timestamp_from = (int) $birth_date_m->format('U');
		$timestamp_to = (int) $datetime2->format('U');
		$difference = (int) round(($timestamp_to - $timestamp_from)/(60*60*24*365));
		
		
		if($difference >= $age_requirement){
			$result = drupal_http_request($ws.$data_s, array('method' => "get")); //+18
		
			//check if the lead is already inserted on DB
			$where2check = $result->data;
			$lead_already_db = strpos($where2check, 'fails":1');
			
			if ($lead_already_db === false) {
					$test_already_db1 = "nouveau lead";
					$form_state['redirect'] = 'previsoes2014delas-c';
			}else{
					$test_already_db2 = "deja en base";
					$form_state['redirect'] = 'previsoes2014delas-c18';
			}
			
		}else{
			$form_state['redirect'] = 'previsoes2014delas-c18';
		}
		
		/*debug
		global $user;
		if($user->uid == 1){
			echo "<pre>";var_dump($ws.$data_s);echo "</pre>";
			echo "<pre>";var_dump($result);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($birth_date_n);echo "</pre>";
			echo "<pre>";var_dump($birth_date_m);echo "</pre>";
			echo "<pre>";var_dump($difference);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($lead_id);echo "</pre>";
			echo "<pre>";var_dump($pixel_mdst);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($test_already_db1);echo "</pre>";
			echo "<pre>";var_dump($test_already_db2);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($file_name);echo "</pre>";
			echo "<pre>";var_dump(file_exists($file_name));echo "</pre>";
			echo "<pre>";var_dump($fp);echo "</pre>";
			die();
		}*/
		
		
	}else{
		echo "Houve um problema, tenta novamente. Obrigado";
		echo "</pre>"; print_r($ws.$data_s); echo "</pre>";
		watchdog("call webservice", "call {$ws}{$data_s}");
		watchdog("reponse webservice", $result->data);
	}
}
function astrocentro_br_app_lp_delas_ok_page(){
	
	$path = drupal_get_path('theme', 'astrocentro_br_mediastay');
	
	$content = "
	
	<div id='landing_page'>
	
	<div id='lp_content'>


		<div id='lp_txt'></div>

		<div id='lp_col_right'>
			<div id='lp_confirmation'>

				<h1>" . $_SESSION['confirmation_msg'] . "</h1>

				<h2>" . $_SESSION['paragraphe_msg'] . "</h2>
				
				<img src='" . path_to_theme() . "/images/delas/ligaragora.png' />

			</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->

		
	

<script type='text/javascript'>

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-35713232-2']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (21) 3958-7182). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
</div><!--endlanding!-->
	
	";
	
	$url = file_get_contents('http://delas.ig.com.br/horoscopo/astrocentro_header_footer.html');
	$url = str_replace('<!-- FIM CONTEÚDO -->', $content, $url);
	$url = str_replace('<!-- REVER ESTA PARTE -->', '<link rel="stylesheet" type="text/css" href="/'.$path.'/css/style-delas.css"/>', $url);
	
	echo $url;
}
function astrocentro_br_app_lp_delas_ok18_page(){

	
	$path = drupal_get_path('theme', 'astrocentro_br_mediastay');

	$content = "
	
	<div id='landing_page'>
	
	<div id='lp_content'>


		<div id='lp_txt'></div>

		<div id='lp_col_right'>
			<div id='lp_confirmation'>

				<h1>PARABÉNS OFERTA GARANTIDA!</h1>

				<h2>Um consultor do Astrocentro vai ligar-lhe no horário comercial para agendar sua consulta. Até breve!</h2>
				
				<img src='" . path_to_theme() . "/images/delas/ligaragora.png' />

			</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (21) 3958-7182). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
</div><!--endlanding!-->
	
	";
	
	$url = file_get_contents('http://delas.ig.com.br/horoscopo/astrocentro_header_footer.html');
	$url = str_replace('<!-- FIM CONTEÚDO -->', $content, $url);
	$url = str_replace('<!-- REVER ESTA PARTE -->', '<link rel="stylesheet" type="text/css" href="/'.$path.'/css/style-delas.css"/>', $url);
	
	echo $url;

}

//******************************** Landing page Content Ignition 01 // ancien webservice
function astrocentro_br_app_lp1contign_page(){

	$include_form = drupal_get_form('astrocentro_br_app_form_lp1contign');

	$content = "
	
	<div id='landing_page'>

	<div id='lp_header'>   
		<div id='lp_logo'><a href='http://www.astrocentro.com.br'><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='' /></a></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'></div>

		<div id='lp_col_right'>
			<div id='lp_btn'></div>
			<div id='lp_form'>";
	$content .= drupal_render($include_form);
	$content .= "</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8483). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	return $content;

}
function astrocentro_br_app_form_lp1contign($form, &$form_state){

	$active = array(0 => t('Mulher'), 1 => t('Homem'));

	$form['civility'] = array(
		'#type' => 'radios',
		'#default_value' => 0, 
		'#options' => $active,
		'#description' => "",
		'#title' => ""
	);

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

	$form['lastname'] = array(
		'#title' => "Sobrenome",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t(''),
            'placeholder' => t('Digite seu sobrenome'),
			'autocomplete' => 'off',
			'tabindex' => '2',
        )
	);

	$form['birthdate'] = array(
		'#title' => "Data de nascimento",
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array('tabindex' => '3'),
	);
	
	$form['email'] = array(
		'#title' => "Email",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu email'),
			'autocomplete' => 'off',
			'tabindex' => '4',
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
			'tabindex' => '5',
        )
	);
	$form['phone2'] = array(
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu celular'),
			'autocomplete' => 'off',
			'size' => 9,
			//'maxlength' => 9,
			'tabindex' => '6',
        )
	);	

	$form['submit'] = array(
		'#type' => 'image_button',
		'#src' => path_to_theme() . "/images/landing_mediastay/btn_2.png"
	);

	return $form;
}
function astrocentro_br_app_form_lp1contign_validate($form, &$form_state){
		
		// Validate form field and set error message
		if(!valid_email_address($form_state['values']['email']) || empty($form_state['values']['email']))
			form_set_error('astrocentro_br_app_form_lp1contign][email', 'Digite seu email.');

		if(empty($form_state['values']['firstname']))
			form_set_error('astrocentro_br_app_form_lp1contign][' . LANGUAGE_NONE . '][0][firstname', t('Digite seu nome'));
			
		if(empty($form_state['values']['lastname']))
			form_set_error('astrocentro_br_app_form_lp1contign][' . LANGUAGE_NONE . '][0][lastname', t('Digite seu sobrenome'));
			
		if(empty($form_state['values']['phone1']))
			form_set_error('astrocentro_br_app_form_lp1contign][' . LANGUAGE_NONE . '][0][phone1', t('Digite seu DDD'));
			
		
		$phone_check = $form_state['values']['phone2'];
		if (strlen($phone_check) > 0) 
			$phone_check = str_replace (' ', '', $phone_check);
			$phone_check = str_replace ('-', '', $phone_check);
			$phone_check = str_replace ('(', '', $phone_check);
			$phone_check = str_replace (')', '', $phone_check);
			$phone_check = str_replace ('[', '', $phone_check);
			$phone_check = str_replace (']', '', $phone_check);
			$phone_check = str_replace ('{', '', $phone_check);
			$phone_check = str_replace ('}', '', $phone_check);
}
function astrocentro_br_app_form_lp1contign_submit($form, &$form_state){
	if(!form_get_errors()){
	
		switch(WENGO_ENV){
			case 'prod':
				$ws = "http://ws.wengo.fr/yatesvi/server.php";
				break;
			case 'preprod':
				$ws = "http://ws.wengo.fr.geekic.com/yatesvi/server.php";
				break;
			default:
				$ws = "http://ws.wengo.fr.center.localdev4/yatesvi/server.php";
				break;
		}
		
		$date_today = date("Y-m-d");
		$date_campaign = date("Y-m-d", time() + 86400);
		$date_end_campaign = date("Y-m-d", time() + 345600);
		
		$lead_email = variable_set('email', ($form_state['values']['email']));
		
		$birth_date = $form_state['values']["birthdate"];
		$birth_date_n = str_replace('/', '-', $birth_date);
		$birth_date_m = new DateTime($birth_date_n);
		$age_requirement = 19;

		$subscription = array();
		$subscription['t9n'] = 'por'; // t9n
		$subscription['date_start'] = $date_today; // 
		$subscription['date_end'] = $date_end_campaign; // date du jour + 4 jours
		$subscription['hour_start'] = '13:00'; // 
		$subscription['hour_end'] = '23:59'; // 
		$subscription['campaign_name'] = 'Affiliation_AppelsSortants_ContentIgnition_1_'.$date_today; // nom campagne
		$subscription['campaign_type'] = 'prospect_contentignition'; // type
		$subscription['extension_from'] = '00551139588483'; // extension_from
		$subscription['extension_to'] = '0055'.$form_state['values']["phone1"].$form_state['values']["phone2"]; // client
		$subscription['json_data'] = array(
			'date_crea'=> $date_today,
			'civility'=> $form_state['values']["civility"],
			'firstname'=> $form_state['values']["firstname"],
			'lastname'=> $form_state['values']["lastname"],
			'email'=> $form_state['values']["email"],
			'birthdate'=> $birth_date_n,
		);
		$subscription['directory_keyid'] = '1270'; // catégorie
		$subscription['operator'] = NULL; // opérateur
		$data_s = "?method=add_hdk_outbound_call_v1&args[0]=".ASTROCENTRO_BR_COM_WS_CONTENTIGNITION_API_KEY."&args[1]=".json_encode($subscription);
	
		$datetime2 = new DateTime(date('Y-m-d'));
		
		$timestamp_from = (int) $birth_date_m->format('U');
		$timestamp_to = (int) $datetime2->format('U');
		$difference = (int) round(($timestamp_to - $timestamp_from)/(60*60*24*365));
		
		if($difference >= $age_requirement){
		
			$result = drupal_http_request($ws.$data_s, array('method' => "get"));
		
			//check if the lead is already inserted on DB
			$where2check = $result->data;
			$lead_already_db = strpos($where2check, 'fails":1');
			
			if ($lead_already_db === false) {
					$test_already_db1 = "nouveau lead";
					$form_state['redirect'] = 'lp1contign-c';
			}else{
					$test_already_db2 = "deja en base";
					$form_state['redirect'] = 'lp1contign-c18';
			}
			
		}else{
			$form_state['redirect'] = 'lp1contign-c18';
		}
		
		
		/*debug*/
		global $user;
		if($user->uid == 1){
			echo "<pre>";var_dump($ws.$data_s);echo "</pre>";
			echo "<pre>";var_dump($result);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($birth_date_n);echo "</pre>";
			echo "<pre>";var_dump($birth_date_m);echo "</pre>";
			echo "<pre>";var_dump($difference);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($test_already_db1);echo "</pre>";
			echo "<pre>";var_dump($test_already_db2);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($file_name);echo "</pre>";
			echo "<pre>";var_dump(file_exists($file_name));echo "</pre>";
			echo "<pre>";var_dump($fp);echo "</pre>";
			die();
		}
	}
}
function astrocentro_br_app_lp1contign_ok_page(){

	$lead_email = variable_get('email','');

	$content = "
	
	<div id='landing_page'>

	<div id='lp_header'>   
		<div id='lp_logo'><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='' /></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'></div>

		<div id='lp_col_right'>
			<div id='lp_confirmation'>

				<h1>PARABÉNS OFERTA GARANTIDA!</h1>

				<h2>Um consultor do Astrocentro vai ligar-lhe no horário comercial para agendar sua consulta. Até breve!</h2>
				
				<img src='" . path_to_theme() . "/images/lp1contign/ligaragora.png' />

			</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8483). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->

	<iframe src='http://tkb.cigplatform.com/clientconvdlsbr.php?chaid=1f8f6e70d7357cd36dda2c7661e1a71a&spid=e078011b18a2147860f0c78300467d94&arg=".$lead_email."&argmon=' frameborder='0' width='1' height='1'></iframe>
	
	";
	
	$content.="<!-- Google Code for Leads Conversion Page -->
<script type='text/javascript'>
/* <![CDATA[ */
var google_conversion_id = 1006044158;
var google_conversion_language = 'en';
var google_conversion_format = '3';
var google_conversion_color = 'ffffff';
var google_conversion_label = 'TUFhCNKNuAYQ_ofc3wM';
var google_conversion_value = 0;
var google_remarketing_only = false;
/* ]]> */
</script>
<script type='text/javascript' src='//www.googleadservices.com/pagead/conversion.js'>
</script>
<noscript>
<div style='display:inline;'>
<img height='1' width='1' style='border-style:none;' alt='' src='//www.googleadservices.com/pagead/conversion/1006044158/?value=0&amp;label=TUFhCNKNuAYQ_ofc3wM&amp;guid=ON&amp;script=0'/>
</div>
</noscript>";
	
	return $content;

}
function astrocentro_br_app_lp1contign_ok18_page(){

	$content = "
	
	<div id='landing_page'>

	<div id='lp_header'>   
		<div id='lp_logo'><a href='http://www.astrocentro.com.br' ><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='' /></a></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'></div>

		<div id='lp_col_right'>
			<div id='lp_confirmation'>

				<h1>PARABÉNS OFERTA GARANTIDA!</h1>

				<h2>Um consultor do Astrocentro vai ligar-lhe no horário comercial para agendar sua consulta. Até breve!</h2>
				
				<img src='" . path_to_theme() . "/images/lp1contign/ligaragora.png' />

			</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8483). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	
	return $content;

}


//******************************** Landing page Content Ignition 02 // ancien webservice
function astrocentro_br_app_lp2contign_page(){

	$include_form = drupal_get_form('astrocentro_br_app_form_lp2contign');

	$content = "
	
	<style>

@font-face {
    font-family: 'Avant Garde CE';
    src: url('avant-garde-ce-1361851277.ttf');
}
@font-face {
    font-family: 'Avant Garde CE Bold';
    font-weight: bold;
    src: url('avant_garde_ce_gothic_demi.ttf');
}

div#lp_txt > p{font-family: 'Avant Garde CE', Helvetica, Arial, sans-serif; color:#ffffff; font-size:18px; text-align:center; line-height:24px; margin-top:65px;}
div#lp_txt > p strong{font-family: 'Avant Garde CE Bold', Helvetica, Arial, sans-serif; font-weight: bold;}

div#lp_btn {position:relative;}
div#lp_btn > p{font-family: 'Avant Garde CE', Helvetica, Arial, sans-serif;color:#d723e7; font-size:22px; position:absolute; bottom:30px; left:30px; width:190px;}
div#lp_btn > p strong{font-family: 'Avant Garde CE Bold', Helvetica, Arial, sans-serif;}
	
#lp_content{ background:url(" . path_to_theme() . "/images/lp2owngoogle/bg.jpg) center no-repeat ; height:569px; width:980px}
#lp_txt{ background:url(" . path_to_theme() . "/images/lp2owngoogle/promo.png) no-repeat ;margin:8px 0px 0px 60px;width:587px;float:left; height:300px;}

#lp_col_right{ background:url(" . path_to_theme() . "/images/lp2owngoogle/right.png) ; width:326px; height:595px; float:right; margin-top:-11px;}
#lp_btn{ background:url(" . path_to_theme() . "/images/lp2owngoogle/btn_1.png) no-repeat ; height:129px;  margin:22px 0 0 41px;}
	
	</style>
	<div id='landing_page'>
	

	<div id='lp_header'>   
		<div id='lp_logo'><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='Astrocentro, Os melhores esotéricos do Brasil' /></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'>
			<p>Os melhores astrólogos, videntes e tarólogos,<br /><strong>24h por dia por telefone.</strong> Pergunte o que quiser. Atendimento na hora ou agendado. <strong>100% confidencial.</strong></p>
		</div>

		<div id='lp_col_right'>
			<div id='lp_btn'><p>Uma consulta de <strong>10 min por R$ 1,00</strong></p></div>
			<div id='lp_form'>";
	$content .= drupal_render($include_form);
	$content .= "</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8483). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	return $content;

}
function astrocentro_br_app_form_lp2contign($form, &$form_state){

	$active = array(0 => t('Mulher'), 1 => t('Homem'));

	$form['civility'] = array(
		'#type' => 'radios',
		'#default_value' => 0, 
		'#options' => $active,
		'#description' => "",
		'#title' => ""
	);

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

	$form['lastname'] = array(
		'#title' => "Sobrenome",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t(''),
            'placeholder' => t('Digite seu sobrenome'),
			'autocomplete' => 'off',
			'tabindex' => '2',
        )
	);

	$form['birthdate'] = array(
		'#title' => "Data de nascimento",
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array('tabindex' => '3'),
	);
	
	$form['email'] = array(
		'#title' => "Email",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu email'),
			'autocomplete' => 'off',
			'tabindex' => '4',
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
			'tabindex' => '5',
        )
	);
	$form['phone2'] = array(
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu celular'),
			'autocomplete' => 'off',
			'size' => 9,
			'tabindex' => '6',
        )
	);	

	$form['submit'] = array(
		'#type' => 'image_button',
		'#src' => path_to_theme() . "/images/lp2owngoogle/btn_2.png"
	);

	return $form;
}
function astrocentro_br_app_form_lp2contign_validate($form, &$form_state){
		
		// Validate form field and set error message
		if(!valid_email_address($form_state['values']['email']) || empty($form_state['values']['email']))
			form_set_error('astrocentro_br_app_form_lp2contign][email', 'Digite seu email.');

		if(empty($form_state['values']['firstname']))
			form_set_error('astrocentro_br_app_form_lp2contign][' . LANGUAGE_NONE . '][0][firstname', t('Digite seu nome'));
			
		if(empty($form_state['values']['lastname']))
			form_set_error('astrocentro_br_app_form_lp2contign][' . LANGUAGE_NONE . '][0][lastname', t('Digite seu sobrenome'));
			
		if(empty($form_state['values']['phone1']))
			form_set_error('astrocentro_br_app_form_lp2contign][' . LANGUAGE_NONE . '][0][phone1', t('Digite seu DDD'));
			
		
		$phone_check = $form_state['values']['phone2'];
		if (strlen($phone_check) > 0) 
			$phone_check = str_replace (' ', '', $phone_check);
			$phone_check = str_replace ('-', '', $phone_check);
			$phone_check = str_replace ('(', '', $phone_check);
			$phone_check = str_replace (')', '', $phone_check);
			$phone_check = str_replace ('[', '', $phone_check);
			$phone_check = str_replace (']', '', $phone_check);
			$phone_check = str_replace ('{', '', $phone_check);
			$phone_check = str_replace ('}', '', $phone_check);
}
function astrocentro_br_app_form_lp2contign_submit($form, &$form_state){
	if(!form_get_errors()){
	
		switch(WENGO_ENV){
			case 'prod':
				$ws = "http://ws.wengo.fr/yatesvi/server.php";
				break;
			case 'preprod':
				$ws = "http://ws.wengo.fr.geekic.com/yatesvi/server.php";
				break;
			default:
				$ws = "http://ws.wengo.fr.center.localdev4/yatesvi/server.php";
				break;
		}
		
		$date_today = date("Y-m-d");
		$date_campaign = date("Y-m-d", time() + 86400);
		$date_end_campaign = date("Y-m-d", time() + 345600);
		
		$lead_email = variable_set('email', ($form_state['values']['email']));
		
		$birth_date = $form_state['values']["birthdate"];
		$birth_date_n = str_replace('/', '-', $birth_date);
		$birth_date_m = new DateTime($birth_date_n);
		$age_requirement = 19;

		$subscription = array();
		$subscription['t9n'] = 'por'; // t9n
		$subscription['date_start'] = $date_today; // 
		$subscription['date_end'] = $date_end_campaign; // date du jour + 4 jours
		$subscription['hour_start'] = '13:00'; // 
		$subscription['hour_end'] = '23:59'; // 
		$subscription['campaign_name'] = 'Affiliation_AppelsSortants_ContentIgnition_2_'.$date_today; // nom campagne
		$subscription['campaign_type'] = 'prospect_contentignition'; // type
		$subscription['extension_from'] = '00551139588483'; // extension_from
		$subscription['extension_to'] = '0055'.$form_state['values']["phone1"].$form_state['values']["phone2"]; // client
		$subscription['json_data'] = array(
			'date_crea'=> $date_today,
			'civility'=> $form_state['values']["civility"],
			'firstname'=> $form_state['values']["firstname"],
			'lastname'=> $form_state['values']["lastname"],
			'email'=> $form_state['values']["email"],
			'birthdate'=> $birth_date_n,
		);
		$subscription['directory_keyid'] = '1270'; // catégorie
		$subscription['operator'] = NULL; // opérateur
		$data_s = "?method=add_hdk_outbound_call_v1&args[0]=".ASTROCENTRO_BR_COM_WS_CONTENTIGNITION_API_KEY."&args[1]=".json_encode($subscription);
	
		$datetime2 = new DateTime(date('Y-m-d'));
		
		$timestamp_from = (int) $birth_date_m->format('U');
		$timestamp_to = (int) $datetime2->format('U');
		$difference = (int) round(($timestamp_to - $timestamp_from)/(60*60*24*365));
		
		if($difference >= $age_requirement){
		
			$result = drupal_http_request($ws.$data_s, array('method' => "get"));
		
			//check if the lead is already inserted on DB
			$where2check = $result->data;
			$lead_already_db = strpos($where2check, 'fails":1');
			
			if ($lead_already_db === false) {
					$test_already_db1 = "nouveau lead";
					$form_state['redirect'] = 'lp2contign-c';
			}else{
					$test_already_db2 = "deja en base";
					$form_state['redirect'] = 'lp2contign-c18';
			}
			
		}else{
			$form_state['redirect'] = 'lp2contign-c18';
		}
		
		/*debug*/
		global $user;
		if($user->uid == 1){
			echo "<pre>";var_dump($ws.$data_s);echo "</pre>";
			echo "<pre>";var_dump($result);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($birth_date_n);echo "</pre>";
			echo "<pre>";var_dump($birth_date_m);echo "</pre>";
			echo "<pre>";var_dump($difference);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($test_already_db1);echo "</pre>";
			echo "<pre>";var_dump($test_already_db2);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($file_name);echo "</pre>";
			echo "<pre>";var_dump(file_exists($file_name));echo "</pre>";
			echo "<pre>";var_dump($fp);echo "</pre>";
			die();
		}
		
		/* if($result->code == "200")
			$form_state['redirect'] = 'lp2contign-c'; */
	}
}
function astrocentro_br_app_lp2contign_ok_page(){

	$lead_email = variable_get('email','');

	$content = "
	
	<style>

@font-face {
    font-family: 'Avant Garde CE';
    src: url('avant-garde-ce-1361851277.ttf');
}
@font-face {
    font-family: 'Avant Garde CE Bold';
    font-weight: bold;
    src: url('avant_garde_ce_gothic_demi.ttf');
}

div#lp_txt > p{font-family: 'Avant Garde CE', Helvetica, Arial, sans-serif; color:#ffffff; font-size:18px; text-align:center; line-height:24px; margin-top:65px;}
div#lp_txt > p strong{font-family: 'Avant Garde CE Bold', Helvetica, Arial, sans-serif; font-weight: bold;}

#lp_content{ background:url(" . path_to_theme() . "/images/lp2owngoogle/bg.jpg) center no-repeat !important; height:569px; width:980px}
#lp_txt{ background:url(" . path_to_theme() . "/images/lp2owngoogle/promo.png) no-repeat ;margin:8px 0px 0px 60px;width:587px;float:left; height:300px;}

#lp_col_right{ background:url(" . path_to_theme() . "/images/lp2owngoogle/right.png) !important; width:326px; height:595px; float:right; margin-top:-11px;}

#lp_confirmation{margin-top:84px; width:340px; background: url(" . path_to_theme() . "/images/lp2owngoogle/txt_confirmation.png) top center no-repeat !important; height:231px; position:relative;}
	
	</style>
	
	<div id='landing_page'>

	<div id='lp_header'>   
		<div id='lp_logo'><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='' /></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'>
			<p>Os melhores astrólogos, videntes e tarólogos,<br /><strong>24h por dia por telefone.</strong> Pergunte o que quiser. Atendimento na hora ou agendado. <strong>100% confidencial.</strong></p>
		</div>

		<div id='lp_col_right'>
			<div id='lp_confirmation'>

				<h1>PARABÉNS OFERTA GARANTIDA!</h1>

				<h2>Um consultor do Astrocentro vai ligar-lhe no horário comercial para agendar sua consulta. Até breve!</h2>
				
				<img src='" . path_to_theme() . "/images/lp1contign/ligaragora.png' />

			</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8483). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->

	<iframe src='http://tkb.cigplatform.com/clientconvdlsbr.php?chaid=1f8f6e70d7357cd36dda2c7661e1a71a&spid=e078011b18a2147860f0c78300467d94&arg=".$lead_email."&argmon=' frameborder='0' width='1' height='1'></iframe>
	
	";
	
	$content.="<!-- Google Code for Leads Conversion Page -->
<script type='text/javascript'>
/* <![CDATA[ */
var google_conversion_id = 1006044158;
var google_conversion_language = 'en';
var google_conversion_format = '3';
var google_conversion_color = 'ffffff';
var google_conversion_label = 'TUFhCNKNuAYQ_ofc3wM';
var google_conversion_value = 0;
var google_remarketing_only = false;
/* ]]> */
</script>
<script type='text/javascript' src='//www.googleadservices.com/pagead/conversion.js'>
</script>
<noscript>
<div style='display:inline;'>
<img height='1' width='1' style='border-style:none;' alt='' src='//www.googleadservices.com/pagead/conversion/1006044158/?value=0&amp;label=TUFhCNKNuAYQ_ofc3wM&amp;guid=ON&amp;script=0'/>
</div>
</noscript>";
	
	return $content;

}
function astrocentro_br_app_lp2contign_ok18_page(){

	$content = "
	
	<style>

@font-face {
    font-family: 'Avant Garde CE';
    src: url('avant-garde-ce-1361851277.ttf');
}
@font-face {
    font-family: 'Avant Garde CE Bold';
    font-weight: bold;
    src: url('avant_garde_ce_gothic_demi.ttf');
}

div#lp_txt > p{font-family: 'Avant Garde CE', Helvetica, Arial, sans-serif; color:#ffffff; font-size:18px; text-align:center; line-height:24px; margin-top:65px;}
div#lp_txt > p strong{font-family: 'Avant Garde CE Bold', Helvetica, Arial, sans-serif; font-weight: bold;}

#lp_content{ background:url(" . path_to_theme() . "/images/lp2owngoogle/bg.jpg) center no-repeat ; height:569px; width:980px}
#lp_txt{ background:url(" . path_to_theme() . "/images/lp2owngoogle/promo.png) no-repeat ;margin:8px 0px 0px 60px;width:587px;float:left; height:300px;}

#lp_col_right{ background:url(" . path_to_theme() . "/images/lp2owngoogle/right.png) ; width:326px; height:595px; float:right; margin-top:-11px;}

#lp_confirmation{margin-top:84px; width:340px; background: url(" . path_to_theme() . "/images/lp2owngoogle/txt_confirmation.png) top center no-repeat; height:231px; position:relative;}
	
	</style>
	
	<div id='landing_page'>

	<div id='lp_header'>   
		<div id='lp_logo'><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='' /></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'>
			<p>Os melhores astrólogos, videntes e tarólogos,<br /><strong>24h por dia por telefone.</strong> Pergunte o que quiser. Atendimento na hora ou agendado. <strong>100% confidencial.</strong></p>
		</div>

		<div id='lp_col_right'>
			<div id='lp_confirmation'>

				<h1>PARABÉNS OFERTA GARANTIDA!</h1>

				<h2>Um consultor do Astrocentro vai ligar-lhe no horário comercial para agendar sua consulta. Até breve!</h2>
				
				<img src='" . path_to_theme() . "/images/lp1owngoogle/ligaragora.png' />

			</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8483). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	
	return $content;

}


//******************************** Landing page Content Ignition 03 // ancien webservice
function astrocentro_br_app_lp3contign_page(){

	$include_form = drupal_get_form('astrocentro_br_app_form_lp3contign');

	$content = "
	
	<style>

@font-face {
    font-family: 'Avant Garde CE';
    src: url('avant-garde-ce-1361851277.ttf');
}
@font-face {
    font-family: 'Avant Garde CE Bold';
    font-weight: bold;
    src: url('avant_garde_ce_gothic_demi.ttf');
}

div#lp_txt > p{font-family: 'Avant Garde CE', Helvetica, Arial, sans-serif; color:#ffffff; font-size:18px; text-align:center; line-height:24px; margin-top:70px;}
div#lp_txt > p strong{font-family: 'Avant Garde CE Bold', Helvetica, Arial, sans-serif; font-weight: bold;}

div#lp_btn {position:relative;}
div#lp_btn > p{font-family: 'Avant Garde CE', Helvetica, Arial, sans-serif; color:#000000; font-size:20px; position:absolute; top:15px; left:15px; }
div#lp_btn > span {display:none;}

#lp_content{ background:url(" . path_to_theme() . "/images/lp3owngoogle/bg.jpg) 0 0 no-repeat ; height:569px; width:980px}
#lp_txt{ background:url(" . path_to_theme() . "/images/lp3owngoogle/promo.gif) top center no-repeat ;margin:8px 0px 0px 60px;width:587px;float:left; height:141px;}

#lp_col_right{ background:url(" . path_to_theme() . "/images/lp3owngoogle/right.png) ; width:326px; height:595px; float:right; margin-top:-11px;}
#lp_btn{ background:url(" . path_to_theme() . "/images/lp3owngoogle/btn_1.png) no-repeat ; height:129px;  margin:22px 0 0 41px;}
	
	</style>
	
	<div id='landing_page'>

	<div id='lp_header'>   
		<div id='lp_logo'><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='Astrocentro, Os melhores esotéricos do Brasil' /></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'>
			<p>Os melhores astrólogos, videntes e tarólogos,<br /><strong>24h por dia por telefone.</strong> Pergunte o que quiser. Atendimento na hora ou agendado. <strong>100% confidencial.</strong></p>
		</div>

		<div id='lp_col_right'>
			<div id='lp_btn'>
				<p>Sim eu quero aproveitar</p>
				<span>Uma consulta de 10 min por R$ 1,00</span>
			</div>
			<div id='lp_form'>";
	$content .= drupal_render($include_form);
	$content .= "</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8483). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	return $content;

}
function astrocentro_br_app_form_lp3contign($form, &$form_state){

	$active = array(0 => t('Mulher'), 1 => t('Homem'));

	$form['civility'] = array(
		'#type' => 'radios',
		'#default_value' => 0, 
		'#options' => $active,
		'#description' => "",
		'#title' => ""
	);

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

	$form['lastname'] = array(
		'#title' => "Sobrenome",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t(''),
            'placeholder' => t('Digite seu sobrenome'),
			'autocomplete' => 'off',
			'tabindex' => '2',
        )
	);

	$form['birthdate'] = array(
		'#title' => "Data de nascimento",
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array('tabindex' => '3'),
	);
	
	$form['email'] = array(
		'#title' => "Email",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu email'),
			'autocomplete' => 'off',
			'tabindex' => '4',
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
			'tabindex' => '5',
        )
	);
	$form['phone2'] = array(
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu celular'),
			'autocomplete' => 'off',
			'size' => 9,
			//'maxlength' => 9,
			'tabindex' => '6',
        )
	);	

	$form['submit'] = array(
		'#type' => 'image_button',
		'#src' => path_to_theme() . "/images/lp3owngoogle/btn_2.png"
	);

	return $form;
}
function astrocentro_br_app_form_lp3contign_validate($form, &$form_state){
	
		
		// Validate form field and set error message
		if(!valid_email_address($form_state['values']['email']) || empty($form_state['values']['email']))
			form_set_error('astrocentro_br_app_form_lp3contign][email', 'Digite seu email.');

		if(empty($form_state['values']['firstname']))
			form_set_error('astrocentro_br_app_form_lp3contign][' . LANGUAGE_NONE . '][0][firstname', t('Digite seu nome'));
			
		if(empty($form_state['values']['lastname']))
			form_set_error('astrocentro_br_app_form_lp3contign][' . LANGUAGE_NONE . '][0][lastname', t('Digite seu sobrenome'));
			
		if(empty($form_state['values']['phone1']))
			form_set_error('astrocentro_br_app_form_lp3contign][' . LANGUAGE_NONE . '][0][phone1', t('Digite seu DDD'));
		
		$phone_check = $form_state['values']['phone2'];
		if (strlen($phone_check) > 0) 
			$phone_check = str_replace (' ', '', $phone_check);
			$phone_check = str_replace ('-', '', $phone_check);
			$phone_check = str_replace ('(', '', $phone_check);
			$phone_check = str_replace (')', '', $phone_check);
			$phone_check = str_replace ('[', '', $phone_check);
			$phone_check = str_replace (']', '', $phone_check);
			$phone_check = str_replace ('{', '', $phone_check);
			$phone_check = str_replace ('}', '', $phone_check);
			}
function astrocentro_br_app_form_lp3contign_submit($form, &$form_state){
	if(!form_get_errors()){
	
		switch(WENGO_ENV){
			case 'prod':
				$ws = "http://ws.wengo.fr/yatesvi/server.php";
				break;
			case 'preprod':
				$ws = "http://ws.wengo.fr.geekic.com/yatesvi/server.php";
				break;
			default:
				$ws = "http://ws.wengo.fr.center.localdev4/yatesvi/server.php";
				break;
		}
		
		$date_today = date("Y-m-d");
		$date_campaign = date("Y-m-d", time() + 86400);
		$date_end_campaign = date("Y-m-d", time() + 345600);
		
		$lead_email = variable_set('email', ($form_state['values']['email']));
		
		$birth_date = $form_state['values']["birthdate"];
		$birth_date_n = str_replace('/', '-', $birth_date);
		$birth_date_m = new DateTime($birth_date_n);
		$age_requirement = 19;

		$subscription = array();
		$subscription['t9n'] = 'por'; // t9n
		$subscription['date_start'] = $date_today; // 
		$subscription['date_end'] = $date_end_campaign; // date du jour + 4 jours
		$subscription['hour_start'] = '13:00'; // 
		$subscription['hour_end'] = '23:59'; // 
		$subscription['campaign_name'] = 'Affiliation_AppelsSortants_ContentIgnition_3_'.$date_today; // nom campagne
		$subscription['campaign_type'] = 'prospect_contentignition'; // type
		$subscription['extension_from'] = '00551139588483'; // extension_from
		$subscription['extension_to'] = '0055'.$form_state['values']["phone1"].$form_state['values']["phone2"]; // client
		$subscription['json_data'] = array(
			'date_crea'=> $date_today,
			'civility'=> $form_state['values']["civility"],
			'firstname'=> $form_state['values']["firstname"],
			'lastname'=> $form_state['values']["lastname"],
			'email'=> $form_state['values']["email"],
			'birthdate'=> $birth_date_n,
		);
		$subscription['directory_keyid'] = '1270'; // catégorie
		$subscription['operator'] = NULL; // opérateur
		$data_s = "?method=add_hdk_outbound_call_v1&args[0]=".ASTROCENTRO_BR_COM_WS_CONTENTIGNITION_API_KEY."&args[1]=".json_encode($subscription);
	
		$datetime2 = new DateTime(date('Y-m-d'));
		
		$timestamp_from = (int) $birth_date_m->format('U');
		$timestamp_to = (int) $datetime2->format('U');
		$difference = (int) round(($timestamp_to - $timestamp_from)/(60*60*24*365));
		
		if($difference >= $age_requirement){
		
			$result = drupal_http_request($ws.$data_s, array('method' => "get"));
		
			//check if the lead is already inserted on DB
			$where2check = $result->data;
			$lead_already_db = strpos($where2check, 'fails":1');
			
			if ($lead_already_db === false) {
					$test_already_db1 = "nouveau lead";
					$form_state['redirect'] = 'lp3contign-c';
			}else{
					$test_already_db2 = "deja en base";
					$form_state['redirect'] = 'lp3contign-c18';
			}
			
		}else{
			$form_state['redirect'] = 'lp3contign-c18';
		}
		
		/*debug*/
		global $user;
		if($user->uid == 1){
			echo "<pre>";var_dump($ws.$data_s);echo "</pre>";
			echo "<pre>";var_dump($result);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($birth_date_n);echo "</pre>";
			echo "<pre>";var_dump($birth_date_m);echo "</pre>";
			echo "<pre>";var_dump($difference);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($test_already_db1);echo "</pre>";
			echo "<pre>";var_dump($test_already_db2);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($file_name);echo "</pre>";
			echo "<pre>";var_dump(file_exists($file_name));echo "</pre>";
			echo "<pre>";var_dump($fp);echo "</pre>";
			die();
		}
		
		/* if($result->code == "200")
			$form_state['redirect'] = 'lp3contign-c'; */
	}
}
function astrocentro_br_app_lp3contign_ok_page(){

	$lead_email = variable_get('email','');

	$content = "
	
	<style>
#lp_content{ background:url(" . path_to_theme() . "/images/lp3owngoogle/bg.jpg) 0 0 no-repeat ; height:569px; width:980px}
#lp_txt{ background:url(" . path_to_theme() . "/images/lp3owngoogle/promo.png) top center no-repeat ;margin:8px 0px 0px 60px;width:587px;float:left; height:300px;}

#lp_col_right{ background:url(" . path_to_theme() . "/images/lp3owngoogle/right.png) ; width:326px; height:595px; float:right; margin-top:-11px;}

#lp_confirmation{margin-top:84px; width:340px; background: url(" . path_to_theme() . "/images/lp3owngoogle/txt_confirmation.png) top center no-repeat; height:231px; position:relative;}
	
	</style>
	
	<div id='landing_page'>

	<div id='lp_header'>   
		<div id='lp_logo'><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='Astrocentro, Os melhores esotéricos do Brasil' /></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'></div>

		<div id='lp_col_right'>
			<div id='lp_confirmation'>

				<h1>PARABÉNS OFERTA GARANTIDA!</h1>

				<h2>Um consultor do Astrocentro vai ligar-lhe no horário comercial para agendar sua consulta. Até breve!</h2>
				
				<img src='" . path_to_theme() . "/images/lp1contign/ligaragora.png' />

			</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8483). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->

	<iframe src='http://tkb.cigplatform.com/clientconvdlsbr.php?chaid=1f8f6e70d7357cd36dda2c7661e1a71a&spid=e078011b18a2147860f0c78300467d94&arg=".$lead_email."&argmon=' frameborder='0' width='1' height='1'></iframe>
	
	";
	
	$content.="<!-- Google Code for Leads Conversion Page -->
<script type='text/javascript'>
/* <![CDATA[ */
var google_conversion_id = 1006044158;
var google_conversion_language = 'en';
var google_conversion_format = '3';
var google_conversion_color = 'ffffff';
var google_conversion_label = 'TUFhCNKNuAYQ_ofc3wM';
var google_conversion_value = 0;
var google_remarketing_only = false;
/* ]]> */
</script>
<script type='text/javascript' src='//www.googleadservices.com/pagead/conversion.js'>
</script>
<noscript>
<div style='display:inline;'>
<img height='1' width='1' style='border-style:none;' alt='' src='//www.googleadservices.com/pagead/conversion/1006044158/?value=0&amp;label=TUFhCNKNuAYQ_ofc3wM&amp;guid=ON&amp;script=0'/>
</div>
</noscript>";
	
	return $content;

}
function astrocentro_br_app_lp3contign_ok18_page(){

	$content = "
	
	<style>
#lp_content{ background:url(" . path_to_theme() . "/images/lp3owngoogle/bg.jpg) 0 0 no-repeat ; height:569px; width:980px}
#lp_txt{ background:url(" . path_to_theme() . "/images/lp3owngoogle/promo.png) top center no-repeat ;margin:8px 0px 0px 60px;width:587px;float:left; height:300px;}

#lp_col_right{ background:url(" . path_to_theme() . "/images/lp3owngoogle/right.png) ; width:326px; height:595px; float:right; margin-top:-11px;}

#lp_confirmation{margin-top:84px; width:340px; background: url(" . path_to_theme() . "/images/lp3owngoogle/txt_confirmation.png) top center no-repeat; height:231px; position:relative;}
	
	</style>
	
	<div id='landing_page'>

	<div id='lp_header'>   
		<div id='lp_logo'><img src='" . path_to_theme() . "/images/landing_mediastay/logo.png' alt='Astrocentro, Os melhores esotéricos do Brasil' /></div>
		<div id='lp_seperator'><img src='" . path_to_theme() . "/images/landing_mediastay/seperator.png' alt='' /></div>
		<div id='lp_top_txt'></div>
	</div>
	
	<div id='lp_content'>


		<div id='lp_txt'></div>

		<div id='lp_col_right'>
			<div id='lp_confirmation'>

				<h1>PARABÉNS OFERTA GARANTIDA!</h1>

				<h2>Um consultor do Astrocentro vai ligar-lhe no horário comercial para agendar sua consulta. Até breve!</h2>
				
				<img src='" . path_to_theme() . "/images/lp1contign/ligaragora.png' />

			</div>
		</div><!--endcol_right!-->



	</div><!--endcontent!-->
	<div id='lp_footer'>

		<div id='lp_box_1'>
			<div class='lp_box_text'>
				<span class='lp_boxtext_1'>A maior</span>
				<h4>VARIEDADE</h4>
				<span>de esotéricos</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_2'>
			<div class='lp_box_text'>
				<span>Profissionais</span>
				<h4>EXPERIENTES</h4>
				<span>98% satisfação</span>
			</div>
		</div><!--endbox!-->


		<div id='lp_box_3'>
			<div class='lp_box_text'>
				<span>Consultas</span>
				<h4>SIGILOSAS</h4>
				<span>fone, chat e email</span>
			</div>

		</div><!--endbox!-->


		<div id='lp_box_4'>
			<div class='lp_box_text'>
				<span>Dados</span>
				<h4>PROTEGIDOS</h4>
				<span>criptografados</span>
			</div>

		</div><!--endbox!-->

		<div id='lp_box_5'>
			<div class='lp_box_text'>
				<span>Pacotes</span>
				<h4>ECONOMICOS</h4>
				<span>disponiveis</span>
			</div>
		</div><!--endbox!-->
		
	</div><!--endfooter!-->
	<p><small>* A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3958-8483). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p style='margin-top:15px;'><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	
	return $content;

}


//******************************** Landing page Delas // nouveau webservice // version mobile bootstrap
function astrocentro_br_app_lpdelas_page_responsive(){
	drupal_session_start();
	
	$_SESSION['campaign_phone_display'] = '(21) 3958-7182';
	
	$_SESSION['campaign_phone_call'] = '0055'.$_SESSION['campaign_phone_display'];
	$_SESSION['campaign_phone_call'] = str_replace (' ', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace ('(', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace (')', '', $_SESSION['campaign_phone_call']);
	$_SESSION['campaign_phone_call'] = str_replace ('-', '', $_SESSION['campaign_phone_call']);
	
	$include_form = drupal_get_form('astrocentro_br_app_form_lpdelas');

	$content = "
	
	<div id='landing_page' class='row row-offset-0'>
	
		<div id='lp_header' class='col-lg-12 col-xs-12 col-md-offset-0'>
			<img src='" . path_to_theme() . "/images/delas/logo.png' alt='Delas, Astrocentro' class='img-responsive img-center delas' />
		</div>
		
		<section class='row row-offset-0'>
			<div id='promo' class='col-xs-12 col-lg-8 col-md-offset-0 text-center'>
				<div class='titles'>
					<h1>TAROT POR TELEFONE</h1>
					<ul class='list-unstyled'>
						<li>Os melhores astrólogos, videntes e tarólogos.</li>
						<li>24h por dia por telefone. Pergunte o que quiser.</li>
						<li>Atendimento na hora ou agendado. 100% confidencial.</li>
					</ul>
					<h2>CONSULTA <span>10 MIN<em class='color-yellow'>**</em> = R$1,00</span></h2>
					<h3>no cartão de crédito</h3>
				</div>
			</div>
			
			<div id='captation' class='col-xs-12 col-lg-4 col-md-offset-0 bg-blue'>
				<div class='col-xs-12'>
					<div class='titles-top text-center hidden-xs hidden-sm hidden-md'>
						<h5>Sim eu quero aproveitar</h5>
						<h4>UMA CONSULTA DE<br />10 MIN POR R$ 1,00</h4>
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
	<p><small><em class='color-yellow'>**</em> A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/".date('Y')." e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone ".$_SESSION['campaign_phone_display']."). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	return $content;

}
function astrocentro_br_app_form_lpdelas($form, &$form_state){


	$active = array(0 => t('Mulher'), 1 => t('Homem'));

	$form['civility'] = array(
		'#type' => 'radios',
		'#default_value' => 0, 
		'#options' => $active,
		'#description' => "",
		'#title' => ""
	);

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
	$form['age'] = array(
		'#title' => "Mais de 18 anos?",
		'#required' => true,
		'#type' => 'checkbox',
		'#attributes' => array(
			'tabindex' => '8',
		)
	);
	
	 $form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'CADASTRAR',
		'#attributes' => array(
			'tabindex' => '9',
        )
	);

	return $form;
}
function astrocentro_br_app_form_lpdelas_submit($form, &$form_state){
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
		
		if ( !$detect->isMobile() ) {
			$civility = $form_state['values']["civility"];
		}else{
			$civility = NULL;
		}
		$email = $form_state['values']["email"];
		$name = $form_state['values']["firstname"];
		
		$denied = explode(",","ç,æ,œ,á,é,í,ó,ú,à,è,ì,ò,ù,ä,ë,ï,ö,ü,ÿ,â,ê,î,ô,û,å,e,i,ø,u,ã,õ,Ç,Æ,Œ,Á,É,Í,Ó,Ú,À,È,Ì,Ò,Ù,Ä,Ë,Ï,Ö,Ü,Ÿ,Â,Ê,Î,Ô,Û,Å,E,I,Ø,U,Ã,Õ,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,±");
		$authorized = explode(",","c,ae,oe,a,e,i,o,u,a,e,i,o,u,a,e,i,o,u,y,a,e,i,o,u,a,e,i,o,u,a,o,C,AE,OE,A,E,I,O,U,A,E,I,O,U,A,E,I,O,U,Y,A,E,I,O,U,A,E,I,O,U,A,O,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,+");

		$email = str_replace($denied, $authorized, $email);
		$name = str_replace($denied, $authorized, $name);

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
			$birthdate_for_webservice = NULL;
		}
		
		$telephone = $form_state['values']['phone1'].$form_state['values']['phone2'];
		$telephone = str_replace (' ', '', $telephone);
		$telephone = str_replace ('-', '', $telephone);
		$telephone = str_replace ('(', '', $telephone);
		$telephone = str_replace (')', '', $telephone);
		
		$family = "igdelas_lp";
		
		$subscription = array();
		$subscription[] = ASTROCENTRO_BR_COM_WS_IG_DELAS_API_KEY; // API Key
		$subscription[] = NULL; //login
		$subscription[] = urlencode($email); //email
		$subscription[] = NULL; //password
		$subscription[] = urlencode($name);
		$subscription[] = "0055".$telephone;
		$subscription[] = "por";
		$subscription[] = "bra";
		$subscription[] = "1"; //population
		$subscription[] = NULL; //tracker_id
		$subscription[] = NULL;
		$subscription[] = "hdk_prospect";
		$subscription[] = $civility;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = $birthdate_for_webservice;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = "1270";
		$subscription[] = $family; //family string $family family (optional, default value ) // here the campaign_type
		
		$data_s = '?method=create_generic_prospect_v1&args[]='.implode('&args[]=', $subscription);
		watchdog("igdelas_landing", "call {$ws}{$data_s}");

		
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
		$form_state['redirect'] = 'previsoes2014delas-c';
		$form_state['no_cache'] = TRUE;
		
		//debug
		global $user;
		if($user->uid == 1){
			echo "<pre>";var_dump($ws.$data_s);echo "</pre>";
			echo "<pre>";var_dump($r);echo "</pre>";
			echo "<pre>";var_dump($check);echo "</pre>";
			echo "<pre>";var_dump("0055".$telephone);echo "</pre>";
			
			die();
		}

	}
}
function astrocentro_br_app_delas_page_responsive_ok(){

$content = "
	
	<div id='landing_page' class='row row-offset-0'>
	
		<div id='lp_header' class='col-lg-12'>
			<img src='" . path_to_theme() . "/images/delas/logo.png' alt='Delas, Astrocentro' class='img-responsive img-center delas' />
		</div>
		
		<section class='row row-offset-0'>
			<div id='promo' class='col-xs-12 hidden-xs hidden-md hidden-sm col-lg-8 text-center'>
				<div class='titles'>
					<h1>TAROT POR TELEFONE</h1>
					<ul class='list-unstyled'>
						<li>Os melhores astrólogos, videntes e tarólogos.</li>
						<li>24h por dia por telefone. Pergunte o que quiser.</li>
						<li>Atendimento na hora ou agendado. 100% confidencial.</li>
					</ul>
					<h2>CONSULTA <span>10 MIN* = R$1,00</span></h2>
					<h3>no cartão de crédito</h3>
				</div>
			</div>
			
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
			
			<div id='promo' class='col-xs-12 col-lg-8 hidden-md hidden-sm hidden-lg text-center'>
				<div class='titles'>
					<h1>TAROT POR TELEFONE</h1>
					<ul class='list-unstyled'>
						<li>Os melhores astrólogos, videntes e tarólogos.</li>
						<li>24h por dia por telefone. Pergunte o que quiser.</li>
						<li>Atendimento na hora ou agendado. 100% confidencial.</li>
					</ul>
					<h2>CONSULTA <span>10 MIN* = R$1,00</span></h2>
					<h3>no cartão de crédito</h3>
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
	<p><small><em class='color-yellow'>**</em> A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/".date('Y')." e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone ".$_SESSION['campaign_phone_display'].". A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
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
			var google_conversion_format = '3';
			var google_conversion_color = 'ffffff';
			var google_conversion_label = 'TUFhCNKNuAYQ_ofc3wM';
			var google_conversion_value = 0;
			var google_remarketing_only = false;
			/* ]]> */
			</script>
			<script type='text/javascript' src='//www.googleadservices.com/pagead/conversion.js'>
			</script>
			<noscript>
			<div style='display:inline;'>
			<img height='1' width='1' style='border-style:none;' alt='' src='//www.googleadservices.com/pagead/conversion/1006044158/?value=0&amp;label=TUFhCNKNuAYQ_ofc3wM&amp;guid=ON&amp;script=0'/>
			</div>
			</noscript>";
	} else {
		$content .= "<!-- No tracking tag -->";
	}
	
	$content .="<!-- Google Code for Leads Conversion Page -->";

	
	return $content;

}


//******************************** Landing page Leads Blog // ancien webservice // version mobile bootstrap
function astrocentro_br_app_leadsblog_page_responsive(){

	if ($detect->isMobile()) {
		$include_form = drupal_get_form('astrocentro_br_app_form_leadsblog_mobile');
	}

	else {
		$include_form = drupal_get_form('astrocentro_br_app_form_leadsblog');
	}
	
	

	$content = "
	
	<div id='landing_page' class='row row-offset-0'>
	
		<div id='lp_header' class='col-lg-12 col-xs-12 col-md-offset-0'>
			<img src='" . path_to_theme() . "/images/commom/logo-astrocentro-v2.png' alt='Astrocentro' class='img-responsive img-center' />
		</div>
		
		<section class='row row-offset-0'>
			<div id='promo' class='col-xs-12 col-lg-8 col-md-offset-0 text-center'>
				<div class='titles'>
					<h1>TAROT POR TELEFONE</h1>
					<ul class='list-unstyled'>
						<li>Os melhores astrólogos, videntes e tarólogos.</li>
						<li>24h por dia por telefone. Pergunte o que quiser.</li>
						<li>Atendimento na hora ou agendado. 100% confidencial.</li>
					</ul>
					<h2>CONSULTA <span>10 MIN<em class='color-yellow'>**</em> = R$1,00</span></h2>
					<h3>no cartão de crédito</h3>
				</div>
			</div>
			
			<div id='captation' class='col-xs-12 col-lg-4 col-md-offset-0 bg-blue'>
				<div class='col-xs-12'>
					<div class='titles-top text-center hidden-xs hidden-sm hidden-md'>
						<h5>Sim eu quero aproveitar</h5>
						<h4>UMA CONSULTA DE<br />10 MIN POR R$ 1,00</h4>
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
	<p><small><em class='color-yellow'>**</em> A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 3957-1012). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	return $content;

}
function astrocentro_br_app_form_leadsblog($form, &$form_state){

	$active = array(0 => t('Mulher'), 1 => t('Homem'));

	$form['civility'] = array(
		'#type' => 'radios',
		'#default_value' => 0, 
		'#options' => $active,
		'#description' => "",
		'#title' => ""
	);

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

	$form['lastname'] = array(
		'#title' => "Sobrenome",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t(''),
            'placeholder' => t('Digite seu sobrenome'),
			'autocomplete' => 'off',
			'tabindex' => '2',
        )
	);

	$days = array_combine(range(1, 31), range(1, 31));
	$days = array("" => "Dia") + $days;
	$form['birth_day'] = array(
		'#title' => "Data de nascimento",
		'#type' => 'select',
		'#options' => $days,
        '#attributes' => array('tabindex' => '3'),
	);

	$months = array_combine(range(1, 12), range(1, 12));
	$months = array("" => "Mês") + $months;
	$form['birth_month'] = array(
		'#title' => "",
		'#type' => 'select',
		'#options' => $months,
        '#attributes' => array('tabindex' => '4'),
	);

	$years = array_combine(range(1920, date("Y")), range(1920, date("Y")));
	$years = array("" => "Ano") + $years;
	$form['birth_year'] = array(
		'#title' => "",
		'#type' => 'select',
		'#options' => $years,
        '#attributes' => array('tabindex' => '5'),
	);
	
	$form['email'] = array(
		'#title' => "Email",
		'#type' => 'textfield',
		'#required' => true,
		'#tree' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu email'),
			'autocomplete' => 'off',
			'tabindex' => '6',
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
			'tabindex' => '7',
        )
	);
	$form['phone2'] = array(
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu celular'),
			'autocomplete' => 'off',
			'size' => 9,
			'tabindex' => '8',
        )
	);	
	 $form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'CADASTRAR',
		'#attributes' => array(
			'tabindex' => '8',
        )
	);

	return $form;
}
function astrocentro_br_app_form_leadsblog_mobile($form, &$form_state){

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
	$form['phone1'] = array(
		'#title' => "Telefone celular",
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t('DDD'),
			'autocomplete' => 'off',
			'size' => 2,
			'maxlength' => 2,
			'tabindex' => '7',
        )
	);
	$form['phone2'] = array(
		'#type' => 'textfield',
		'#required' => true,
        '#attributes' => array(
            'placeholder' => t('Digite seu celular'),
			'autocomplete' => 'off',
			'size' => 9,
			'tabindex' => '8',
        )
	);	

	$form['age'] = array(
		'#title' => "Mais de 18 anos?",
		'#required' => true,
		'#type' => 'checkbox',
        '#attributes' => array(
			'tabindex' => '4',
		)
	);
	
	 $form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'CADASTRAR',
		'#attributes' => array(
			'tabindex' => '5',
        )
	);

	return $form;
}
function astrocentro_br_app_form_leadsblog_validate($form, &$form_state){
		
		// Validate form field and set error message
		/*if(!valid_email_address($form_state['values']['email']) || empty($form_state['values']['email']))
			form_set_error('astrocentro_br_app_form_leadsblog][email', 'Digite seu email.');

		if(empty($form_state['values']['firstname']))
			form_set_error('astrocentro_br_app_form_leadsblog][' . LANGUAGE_NONE . '][0][firstname', t('Digite seu nome'));
			
		if(empty($form_state['values']['lastname']))
			form_set_error('astrocentro_br_app_form_leadsblog][' . LANGUAGE_NONE . '][0][lastname', t('Digite seu sobrenome'));*/
}
function astrocentro_br_app_form_leadsblog_submit($form, &$form_state){
	if(!form_get_errors()){
	
		switch(WENGO_ENV){
			case 'prod':
				$ws = "http://ws.wengo.fr/yatesvi/server.php";
				break;
			case 'preprod':
				$ws = "http://ws.wengo.fr.geekic.com/yatesvi/server.php";
				break;
			default:
				$ws = "http://ws.wengo.fr.center.localdev4/yatesvi/server.php";
				break;
		}
		
		$date_today = date("Y-m-d");
		$date_campaign = date("Y-m-d", time() + 86400);
		$date_end_campaign = date("Y-m-d", time() + 345600);
		
		$civility = $form_state['values']["civility"];
		$firstname = $form_state['values']["firstname"];
		$lastname = $form_state['values']["lastname"];
		$email = $form_state['values']["email"];
		
		$telephone = $form_state['values']['phone1'].$form_state['values']['phone2'];
		$telephone = str_replace (' ', '', $telephone);
		$telephone = str_replace ('-', '', $telephone);
		$telephone = str_replace ('(', '', $telephone);
		$telephone = str_replace (')', '', $telephone);
		
		$birth_date = $form_state['values']["birth_day"].'-'.$form_state['values']["birth_month"].'-'.$form_state['values']["birth_year"];
		$birth_date_ws = date_create($birth_date);
		
		$denied = explode(",","ç,æ,œ,á,é,í,ó,ú,à,è,ì,ò,ù,ä,ë,ï,ö,ü,ÿ,â,ê,î,ô,û,å,e,i,ø,u,ã,õ");
		$authorized = explode(",","c,ae,oe,a,e,i,o,u,a,e,i,o,u,a,e,i,o,u,y,a,e,i,o,u,a,e,i,o,u,a,o");
		
		$email = str_replace($denied, $authorized, $email);
		$firstname = str_replace($denied, $authorized, $firstname);
		$lastname = str_replace($denied, $authorized, $lastname);

		$subscription = array();
		$subscription['t9n'] = 'por'; // t9n
		$subscription['date_start'] = $date_today; // 
		$subscription['date_end'] = $date_end_campaign; // date du jour + 4 jours
		$subscription['hour_start'] = '13:00'; // 
		$subscription['hour_end'] = '23:59'; // 
		$subscription['campaign_name'] = 'AppelsSortants_Leads_Blog_'.$date_today; // nom campagne
		$subscription['campaign_type'] = 'prospect_blog'; // type
		$subscription['extension_from'] = '00551139571012'; // extension_from
		$subscription['extension_to'] = '0055'.$telephone; // client
		$subscription['json_data'] = array(
			'date_crea'=> $date_today,
			'civility'=> $civility,
			'firstname'=> utf8_encode($firstname),
			'lastname'=> utf8_encode($lastname),
			'email'=> utf8_encode($email),
			'birthdate'=> date_format($birth_date_ws, 'Y-m-d'),
			'device'=> 'desktop',
		);
		$subscription['directory_keyid'] = '1270';
		$subscription['operator'] = NULL;
		$data_s = "?method=add_hdk_outbound_call_v1&args[0]=".ASTROCENTRO_BR_COM_WS_WENGO_API_KEY."&args[1]=".json_encode($subscription);

		$age_requirement = 19;
		
		$datetime2 = new DateTime(date('Y-m-d'));
		$timestamp_from = (int) $birth_date_ws->format('U');
		$timestamp_to = (int) $datetime2->format('U');
		$difference = (int) round(($timestamp_to - $timestamp_from)/(60*60*24*365));
		
		if($difference >= $age_requirement){
			$result = drupal_http_request($ws.$data_s, array('method' => "get")); //+18
		
			//check if the lead is already inserted on DB
			$where2check = $result->data;
			$lead_already_db = strpos($where2check, 'fails":1');
			
			variable_del('lead_status');
			variable_del('lead_status_message');
			
			if ($lead_already_db === false) {
				$confirmation_msg = variable_set('lead_status', 'PARABÉNS OFERTA GARANTIDA!');
				$paragraphe_msg = variable_set('lead_status_message', 'Um consultor do Astrocentro vai ligar no horário comercial para agendar sua consulta. Até breve!');
				
				$form_state['redirect'] = 'lp1leadsblog-c';
				
				$test_already_db = "nouveau lead";
			}else{
				$confirmation_msg = variable_set('lead_status', 'OCORREU UM ERRO TÉCNICO');
				$paragraphe_msg = variable_set('lead_status_message', 'Ligue para nós para garantir sua oferta. Até breve!');
				$form_state['redirect'] = 'lp1leadsblog-c';
				$test_already_db = "deja en base";
			}
			
		}else{
			$confirmation_msg = variable_set('lead_status', 'OFERTA VÁLIDA PARA MAIORES DE 18 ANOS');
			$paragraphe_msg = variable_set('lead_status_message', '');
			$form_state['redirect'] = 'lp1leadsblog-c';
		}
		
		/*debug*/
		global $user;
		if($user->uid == 1){
			echo "<pre>";var_dump($ws.$data_s);echo "</pre>";
			echo "<pre>";var_dump($result);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($birth_date_ws);echo "</pre>";
			echo "<pre>";var_dump(date_format($birth_date_ws, 'Y-m-d'));echo "</pre>";
			echo "<pre>";var_dump($difference);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($confirmation_msg);echo "</pre>";
			echo "<pre>";var_dump($paragraphe_msg);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($test_already_db);echo "</pre>";
			die();
		}


	}else{
		echo "Houve um problema, tenta novamente. Obrigado";
		echo "</pre>"; print_r($ws.$data_s); echo "</pre>";
		watchdog("call webservice", "call {$ws}{$data_s}");
		watchdog("reponse webservice", $result->data);
	}
}
function astrocentro_br_app_form_leadsblog_mobile_submit($form, &$form_state){
	if(!form_get_errors()){
	
		switch(WENGO_ENV){
			case 'prod':
				$ws = "http://ws.wengo.fr/yatesvi/server.php";
				break;
			case 'preprod':
				$ws = "http://ws.wengo.fr.geekic.com/yatesvi/server.php";
				break;
			default:
				$ws = "http://ws.wengo.fr.center.localdev4/yatesvi/server.php";
				break;
		}
		
		$date_today = date("Y-m-d");
		$date_end_campaign = date("Y-m-d", time() + 345600);
		
		$firstname = $form_state['values']["firstname"];
		$email = $form_state['values']["email"];
		
		$telephone = $form_state['values']['phone1'].$form_state['values']['phone2'];
		if (strlen($telephone) > 0) 
			$telephone = str_replace (' ', '', $telephone);
			$telephone = str_replace ('-', '', $telephone);
			$telephone = str_replace ('(', '', $telephone);
			$telephone = str_replace (')', '', $telephone);
		
		$denied = explode(",","ç,æ,œ,á,é,í,ó,ú,à,è,ì,ò,ù,ä,ë,ï,ö,ü,ÿ,â,ê,î,ô,û,å,e,i,ø,u,ã,õ");
		$authorized = explode(",","c,ae,oe,a,e,i,o,u,a,e,i,o,u,a,e,i,o,u,y,a,e,i,o,u,a,e,i,o,u,a,o");
		
		$email = str_replace($denied, $authorized, $email);
		$firstname = str_replace($denied, $authorized, $firstname);

		$subscription = array();
		$subscription['t9n'] = 'por'; // t9n
		$subscription['date_start'] = $date_today; // 
		$subscription['date_end'] = $date_end_campaign; // date du jour + 4 jours
		$subscription['hour_start'] = '13:00'; // 
		$subscription['hour_end'] = '23:59'; // 
		$subscription['campaign_name'] = 'Affiliation_AppelsSortants_LeadsBlog_mobile_'.$date_today; // nom campagne
		$subscription['campaign_type'] = 'prospect_blog'; // type
		$subscription['extension_from'] = '00551139571012'; // extension_from
		$subscription['extension_to'] = '0055'.$telephone; // client
		$subscription['json_data'] = array(
			'date_crea'=> $date_today,
			'firstname'=> utf8_encode($firstname),
			'email'=> utf8_encode($email),
			'device'=> 'mobile',
		);
		$subscription['directory_keyid'] = '1270';
		$subscription['operator'] = NULL;
		$data_s = "?method=add_hdk_outbound_call_v1&args[0]=".ASTROCENTRO_BR_COM_WS_WENGO_API_KEY."&args[1]=".json_encode($subscription);
		
		$result = drupal_http_request($ws.$data_s, array('method' => "get")); //+18
	
		//check if the lead is already inserted on DB
		$where2check = $result->data;
		$lead_already_db = strpos($where2check, 'fails":1');
			
		variable_del('lead_status');
		variable_del('lead_status_message');
		
		if ($lead_already_db === false) {
			$confirmation_msg = variable_set('lead_status', 'PARABÉNS OFERTA GARANTIDA!');
			$paragraphe_msg = variable_set('lead_status_message', 'Um consultor do Astrocentro vai ligar no horário comercial para agendar sua consulta. Até breve!');
			$form_state['redirect'] = 'lp1leadsblog-c';
			$test_already_db = "nouveau lead";
		}else{
			$confirmation_msg = variable_set('lead_status', 'OCORREU UM ERRO TÉCNICO');
			$paragraphe_msg = variable_set('lead_status_message', 'Ligue para nós para garantir sua oferta. Até breve!');
			$form_state['redirect'] = 'lp1leadsblog-c';
			$test_already_db = "deja en base";
		}
		
		/*debug*/
		global $user;
		if($user->uid == 1){
			echo "<pre>";var_dump($ws.$data_s);echo "</pre>";
			echo "<pre>";var_dump($result);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($confirmation_msg);echo "</pre>";
			echo "<pre>";var_dump($paragraphe_msg);echo "</pre>";
			echo "<pre>------------------</pre>";
			echo "<pre>";var_dump($test_already_db);echo "</pre>";
			die();
		}
		
		
	}else{
		echo "Houve um problema, tenta novamente. Obrigado";
		echo "</pre>"; print_r($ws.$data_s); echo "</pre>";
		watchdog("call webservice", "call {$ws}{$data_s}");
		watchdog("reponse webservice", $result->data);
	}
	
		
	if($result->code != "200"){
		$confirmation_msg = variable_set('lead_status', 'OCORREU UM ERRO TÉCNICO');
		$paragraphe_msg = variable_set('lead_status_message', 'Ligue para nós para garantir sua oferta. Até breve!');
		
		$form_state['redirect'] = 'lp1mdst-c';
		
		watchdog("call webservice", "call {$ws}{$data_s}");
		watchdog("reponse webservice", $result->data);
	}
}
function astrocentro_br_app_leadsblog_page_responsive_ok(){

$confirmation_msg = variable_get('lead_status','');
$paragraphe_msg = variable_get('lead_status_message','');

$content = "
	
	<div id='landing_page' class='row row-offset-0'>
	
		<div id='lp_header' class='col-lg-12'>
			<img src='" . path_to_theme() . "/images/commom/logo-astrocentro-v2.png' alt='Astrocentro' class='img-responsive img-center' />
		</div>
		
		<section class='row row-offset-0'>
			<div id='promo' class='col-xs-12 hidden-xs hidden-md hidden-sm col-lg-8 text-center'>
				<div class='titles'>
					<h1>TAROT POR TELEFONE</h1>
					<ul class='list-unstyled'>
						<li>Os melhores astrólogos, videntes e tarólogos.</li>
						<li>24h por dia por telefone. Pergunte o que quiser.</li>
						<li>Atendimento na hora ou agendado. 100% confidencial.</li>
					</ul>
					<h2>CONSULTA <span>10 MIN<em class='color-yellow'>**</em> = R$1,00</span></h2>
					<h3>no cartão de crédito</h3>
				</div>
			</div>
			
			<div id='lp_confirmation' class='col-lg-4 col-xs-12 bg-blue text-center'>
				<h1>" . $confirmation_msg . "</h1>
				<p>" . $paragraphe_msg . "</p>

				<div>
			<a href='tel:+551139571012'>
					<h5>QUER SE CONSULTAR AGORA</h5>
					<h4>LIGUE PARA ASTROCENTRO</h4>
					<h4>(11) 3957-1012</h4>
			</a>
				</div>
			</div>
			
			<div id='promo' class='col-xs-12 col-lg-8 hidden-md hidden-sm hidden-lg text-center'>
				<div class='titles'>
					<h1>TAROT POR TELEFONE</h1>
					<ul class='list-unstyled'>
						<li>Os melhores astrólogos, videntes e tarólogos.</li>
						<li>24h por dia por telefone. Pergunte o que quiser.</li>
						<li>Atendimento na hora ou agendado. 100% confidencial.</li>
					</ul>
					<h2>CONSULTA <span>10 MIN* = R$1,00</span></h2>
					<h3>no cartão de crédito</h3>
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
	<p><small><em class='color-yellow'>**</em> A promoção 'Sua consulta por R$ 1,00' é válida no território nacional de 13/05/2013 a 31/12/2014 e destinada a novos clientes em sua primeira consulta de até 10 minutos com pagamento para cartões de crédito (confirme as bandeiras no site ou pelo telefone (11) 4950-9150). A promoção sera cobrada a R$ 5,00 no depósito e a R$ 10,00 no boleto bancário por email. As ligações com duração superior a 10 minutos são cobradas, por minuto, a R$ 3,99 no cartão de crédito.</small></p>
	
	<p><small>Ao preencher os seus dados, você concorda que receberá um contato do Astrocentro para apresentação do produto. Garantimos total sigilo dos seus dados. <a href='http://tarot-videncia.astrocentro.com.br/?yawl[S]=wengopass.public.legal&yawl[K]=wengopass.public.legal&wl=140' style='color:blue;'>Aviso legal</a></small></p>
</div><!--endlanding!-->
	
	";
	
	$content.="<!-- Google Code for Leads Conversion Page -->
<script type='text/javascript'>
/* <![CDATA[ */
var google_conversion_id = 1006044158;
var google_conversion_language = 'en';
var google_conversion_format = '3';
var google_conversion_color = 'ffffff';
var google_conversion_label = 'TUFhCNKNuAYQ_ofc3wM';
var google_conversion_value = 0;
var google_remarketing_only = false;
/* ]]> */
</script>
<script type='text/javascript' src='//www.googleadservices.com/pagead/conversion.js'>
</script>
<noscript>
<div style='display:inline;'>
<img height='1' width='1' style='border-style:none;' alt='' src='//www.googleadservices.com/pagead/conversion/1006044158/?value=0&amp;label=TUFhCNKNuAYQ_ofc3wM&amp;guid=ON&amp;script=0'/>
</div>
</noscript>";
	
	return $content;

}
