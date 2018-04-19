<?php
session_start ();

function astrocentro_br_app_chat_form($form, &$form_state) {
	$form['livechat-email'] = array(
		'#type' => 'textfield',
		'#required' => TRUE,
		'#title' => "Email",
        '#attributes' => array(
            'placeholder' => t('Digite seu email'),
			'autocomplete' => 'off',
			'tabindex' => '1',
        )
	);

	$form['livechat-birthdate'] = array(
		'#title' => "Data de nascimento",
		'#type' => 'textfield',
		'#default_value' => '',
		//'#required' => true,
        '#attributes' => array(
			'tabindex' => '2',
            'placeholder' => t('Digite sua data de nascimento'),
			'autocomplete' => 'off',
		),
	);

	$form['livechat-comment'] = array(
		'#type' => 'textarea',
		'#required' => TRUE,
		'#title' => "Pergunta",
        '#attributes' => array(
            'placeholder' => t('Digite sua pergunta'),
			'autocomplete' => 'off',
			'tabindex' => '3',
        )
	);

	$form['submit'] = array(
		'#type' => 'image_button',
		'#src' => path_to_theme() . "/images/btn_confirmar.png"
	);;

	return $form;
}
function astrocentro_br_app_chat_form_submit($form, &$form_state) {
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
		
		/*CoverItLive settings*/
		$token_cil = '96266743288db3f9c3c20f7eaadc85aa';
		$event_code_cil = 'e84135d412';
		$email = $form_state['values']['livechat-email'];
		$birthdate = $form_state['values']['livechat-birthdate'];
		$comment = $form_state['values']['livechat-comment'];
		
		$live_chat_event = array(
			'token' => $token_cil,
			'event_code' => $event_code_cil,
			'comment' => $comment,
			'guest_name' => $email,
		);
		
		$data_cil = json_encode($live_chat_event);
		
		$options = array(
			'method' => 'POST',
			'data' => drupal_http_build_query($live_chat_event),
			'timeout' => 4,
			'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
		);
		
		$result_cil = drupal_http_request('https://api.coveritlive.com/remote/2/comment/create', $options);
		
		if (strnatcmp(phpversion(),'5.3') <= 0){ 
			$create_login_prospect = split("@",$email);
			$login_prospect = $create_login_prospect[0];
		}else{ 
			$login_prospect = strstr($email, '@', true);
		}
		
		$subscription = array();
		$subscription[] = ASTROCENTRO_BR_COM_WS_WENGO_API_KEY; // API Key
		$subscription[] = urlencode($login_prospect); //login
		$subscription[] = urlencode($email);
		$subscription[] = null; // password
		$subscription[] = null;
		$subscription[] = null;
		$subscription[] = "por";
		$subscription[] = "bra";
		$subscription[] = "1";
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = "hdk_prospect";
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = urlencode($birthdate);
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = "1270";
		$subscription[] = "live-chat-event-test";
		
		$data_s ="?method=create_generic_prospect_v1&args[0]=".$subscription[0]."&args[1]=".$subscription[1]."&args[2]=".$subscription[2]."&args[3]=".$subscription[3]."&args[4]=".$subscription[4]."&args[5]=".$subscription[5]."&args[6]=".$subscription[6]."&args[7]=".$subscription[7]."&args[8]=".$subscription[8]."&args[9]=".$subscription[9]."&args[10]=".$subscription[10]."&args[11]=".$subscription[11]."&args[12]=".$subscription[12]."&args[13]=".$subscription[13]."&args[14]=".$subscription[14]."&args[15]=".$subscription[15]."&args[16]=".$subscription[16]."&args[17]=".$subscription[17]."&args[18]=".$subscription[18]."&args[19]=".$subscription[19]."&args[20]=".$subscription[20]."&args[21]=".$subscription[21]."&args[22]=".$subscription[22]."&args[23]=".$subscription[23]."&args[24]=".$subscription[24]."&args[25]=".$subscription[25] ;
		
		$r = drupal_http_request($ws.$data_s, array(
			'method' => "get",
		));
		
	watchdog("astrocentro_br_prospect_livechatevent_form", "call {$ws}{$data_s}");
		
		$where2check = $r->data;
		$pos_already = strpos($where2check, "account already exists");
		$pos_ok = strpos($where2check, "hdk_prospect_keyid");
		
		if ($pos_already === false) {
			//echo "NOK";
		} else {
			drupal_set_message("Esse email já está cadastrado");
		}
		
		if ($pos_ok === false) {
			//echo "OK";
		} else {
			drupal_set_message("Sua subscrição foi confirmada");
			
			
			$_SESSION['email-chat'] = $email;
            $_SESSION['birthdate-chat'] = $birthdate;
			
			
		}
	}
}

function astrocentro_br_app_chat_onlycomment_form($form, &$form_state) {

	$form['livechat-comment'] = array(
		'#type' => 'textarea',
		'#required' => TRUE,
		'#title' => "Pergunta",
        '#attributes' => array(
            'placeholder' => t('Digite sua pergunta'),
			'autocomplete' => 'off',
			'tabindex' => '3',
        )
	);

	$form['submit'] = array(
		'#type' => 'image_button',
		'#src' => path_to_theme() . "/images/btn_confirmar.png"
	);;

	return $form;
}
function astrocentro_br_app_chat_onlycomment_form_submit($form, &$form_state) {
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
		
		/*CoverItLive settings*/
		$token_cil = '96266743288db3f9c3c20f7eaadc85aa';
		$event_code_cil = 'e84135d412';
		$comment = $form_state['values']['livechat-comment'];
		
		$live_chat_event = array(
			'token' => $token_cil,
			'event_code' => $event_code_cil,
			'comment' => $comment,
			'guest_name' => $_SESSION['email-chat'],
		);
		
		//$data_cil = json_encode($live_chat_event);
		
		$options = array(
			'method' => 'POST',
			'data' => drupal_http_build_query($live_chat_event),
			'timeout' => 4,
			'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
		);
		
		$result_cil = drupal_http_request('https://api.coveritlive.com/remote/2/comment/create', $options);
		
		/*
		global $user;
		if($user->uid == 1){
			echo "<pre>";var_dump($token_cil);echo "</pre>";
			echo "<pre>";var_dump($event_code_cil);echo "</pre>";
			echo "<pre>";echo "---------------------";echo "</pre>";
			echo "<pre>";var_dump($data_cil);echo "</pre>";
			echo "<pre>";echo "---------------------";echo "</pre>";
			echo "<pre>";var_dump($result_cil);echo "</pre>";
			echo "<pre>";echo "---------------------";echo "</pre>";
			echo "<pre>";var_dump($result_cil->data);echo "</pre>";
			echo "<pre>";echo "---------------------";echo "</pre>";
			
			die();
		}
		*/
	}
}

function astrocentro_br_app_chat_page(){
	drupal_session_start();
	$inactive = 900; //30min
	
	if(isset($_SESSION['timeout']) ) {
		$session_life = time() - $_SESSION['start'];
		if($session_life > $inactive){
			session_destroy();
		}
	}
	$_SESSION['timeout'] = time();
	
	// Metatags
	$page_keywords = array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
        	'name' => 'keywords',
          	'content' => 'chat com um especialista',
        )
	);
    drupal_add_html_head($page_keywords, 'page_keywords');
    $page_description = array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
        	'name' => 'description',
          	'content' => 'Entre em contato com um especialista. Confira!',
        )
	);
    drupal_add_html_head($page_description, 'page_description');
    $title = "Participe ao evento com um especialista";	
	
	
	$content = "
	
		<style type= text/css>
			div[class$='form-item-livechat-email'],
			div[class$='form-item-livechat-birthdate'],
			form#astrocentro-br-app-chat-form div.form-textarea-wrapper {position:relative;}
			
			div[class$='form-item-livechat-email'] span.LV_validation_message,
			div[class$='form-item-livechat-birthdate'] span.LV_validation_message{right:-18px !important; top:-12px !important;}
			
			div[class$='form-item-livechat-comment'] span.LV_validation_message{top:-32px !important; right:0px !important;}
		</style>
	
		<script type='text/javascript'>
			jQuery(function($){
				var $ = jQuery.noConflict();
				
				var valBlocLiveChatEmail = new LiveValidation('edit-livechat-email');
				valBlocLiveChatEmail.add(Validate.Presence);
				valBlocLiveChatEmail.add(Validate.Email);
				
				var valBlocLiveChatBirth = new LiveValidation('edit-livechat-birthdate');
				valBlocLiveChatBirth.add(Validate.Presence);
				//valBlocLiveChatBirth.add(Validate.);
				
				var valBlocLiveChatComment = new LiveValidation('edit-livechat-comment');
				valBlocLiveChatComment.add(Validate.Presence);
				//valBlocLiveChatComment.add(Validate.);
				
				$('#edit-livechat-birthdate').mask('99/99/9999');
				});
		</script>
	";
	
	/*$content .= "
				<div class='live-chat-event'>
					<!-- <div id='cil-root-f76b2de823' class='cil-root'><span class='cil-config-data' title='{\"altcastCode\":\"f76b2de823\",\"server\":\"www.coveritlive.com\",\"geometry\":{\"width\":\"fit\",\"height\":550},\"configuration\":{\"newEntryLocation\":\"bottom\",\"pinsGrowSize\":\"on\",\"titlePage\":\"off\",\"skinOverride\":\"118\"}}'>&nbsp;</span></div><script type='text/javascript'>window.cilAsyncInit = function() {cilEmbedManager.init()};(function() {var e = document.createElement('script');e.async = true;var domain = (document.location.protocol == 'http:') ? '//cdnsl.coveritlive.com' : '//cdnslssl.coveritlive.com';e.src = document.location.protocol + domain + '/vw.js?v=' + Math.floor(Math.random()*10000000);e.id = 'cilScript-f76b2de823';document.getElementById('cil-root-f76b2de823').appendChild(e);}());</script> -->
					<div style='display:none;'>Live Blog test3</div><div id='cil-root-8385b5816b' class='cil-root'><span class='cil-config-data' title='{\"altcastCode\":\"8385b5816b\",\"server\":\"www.coveritlive.com\",\"geometry\":{\"width\":\"fit\",\"height\":550},\"configuration\":{\"newEntryLocation\":\"bottom\",\"commentLocation\":\"bottom\",\"replayContentOrder\":\"chronological\",\"pinsGrowSize\":\"on\",\"titlePage\":\"off\",\"skinOverride\":\"117\"}}'>&nbsp;</span></div><script type='text/javascript'>window.cilAsyncInit = function() {cilEmbedManager.init()};(function() {if (window.cilVwRand === undefined) { window.cilVwRand = Math.floor(Math.random()*10000000); }var e = document.createElement('script');e.async = true;var domain = (document.location.protocol == 'http:' || document.location.protocol == 'file:') ? 'http://cdnsl.coveritlive.com' : 'https://cdnslssl.coveritlive.com';e.src = domain + '/vw.js?v=' + window.cilVwRand;e.id = 'cilScript-8385b5816b';document.getElementById('cil-root-8385b5816b').appendChild(e);}());</script>
				</div>
	";*/
	
	$content .="
	
<div style='display:none;'>Live Blog Teste</div><div id='cil-root-stream-e84135d412' class='cil-root'><span class='cil-config-data' title='{\"altcastCode\":\"e84135d412\",\"server\":\"www.coveritlive.com\",\"geometry\":{\"width\":\"fit\",\"height\":550},\"configuration\":{\"newEntryLocation\":\"top\",\"commentLocation\":\"top\",\"replayContentOrder\":\"chronological\",\"pinsGrowSize\":\"on\",\"titlePage\":\"off\",\"embedType\":\"stream\",\"titleImage\":\"/templates/coveritlive/images/buildPage/LifestyleImage.jpg\"}}'>&nbsp;</span></div><script type='text/javascript'>window.cilAsyncInit = function() {cilEmbedManager.init()};(function() {if (window.cilVwRand === undefined) { window.cilVwRand = Math.floor(Math.random()*10000000); }var e = document.createElement('script');e.async = true;var domain = (document.location.protocol == 'http:' || document.location.protocol == 'file:') ? 'http://cdnsl.coveritlive.com' : 'https://cdnslssl.coveritlive.com';e.src = domain + '/vw.js?v=' + window.cilVwRand;e.id = 'cilScript-e84135d412';document.getElementById('cil-root-stream-e84135d412').appendChild(e);}());</script>
	
	";
	
	$form_within_ws =  drupal_get_form("astrocentro_br_app_chat_form");
	$form_without_ws =  drupal_get_form("astrocentro_br_app_chat_onlycomment_form");
	
	
	
	if(!empty($_SESSION['email-chat'])) {
			$content .=  "<div class='reactions'>".drupal_render($form_without_ws)."</div>";
		}else{
			$content .=  "<div class='reactions'>".drupal_render($form_within_ws)."</div>";
		}
	
	drupal_set_title($title);

	return $content;
	
	print ($_SESSION['email-chat']);
	print ($_SESSION['birthdate-chat']);
	}

