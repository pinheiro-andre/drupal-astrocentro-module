<?php

function lead_form($form, &$form_state) {
	
	//$form['#attributes'] = array('target' => '_self');
	
	$form['name'] = array(
		'#type' => 'textfield',
		'#default_value' => empty($form_state['values']['name']) ? '' : $form_state['values']['name'],
		'#required' => TRUE,
		'#title' => "Nome",
		'#attributes' => array(
			'autocomplete' => 'off',
			'tabindex' => '1',
			'size' => '50',
		),
	);
	$form['mail'] = array(
		'#type' => 'textfield',
		'#default_value' => empty($form_state['values']['mail']) ? '' : $form_state['values']['mail'],
		'#required' => TRUE,
		'#title' => "Email",
		'#attributes' => array(
			'autocomplete' => 'off',
			'tabindex' => '2',
			'size' => '5',
		),
	);
	$form['ddd'] = array(
		'#type' => 'textfield',
		'#default_value' => empty($form_state['values']['ddd']) ? '' : $form_state['values']['ddd'],
		'#required' => TRUE,
		'#title' => "DDD",
		'#attributes' => array(
			'autocomplete' => 'off',
			'tabindex' => '3',
			'size' => '2',
			'maxlength' => '2',
		),
	);
	$form['phone'] = array(
		'#type' => 'textfield',
		'#default_value' => empty($form_state['values']['phone']) ? '' : $form_state['values']['phone'],
		'#required' => TRUE,
		'#title' => "Celular",
		'#attributes' => array(
			'autocomplete' => 'off',
			'tabindex' => '4',
			'size' => '30',
			'maxlength' => '11',
		),
	);
	
	 $form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'ME LIGUE!',
		'#attributes' => array(
			'tabindex' => '5',
			'class' => array(
				'btn-lg',
				'btn-block'
			),
        )
	);

  return $form;
}

function lead_form_submit($form, $form_state) {
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
		
		$name = $form_state['values']['name'];
		$email = $form_state['values']['mail'];
		
		$denied = explode(",","ç,æ,œ,á,é,í,ó,ú,à,è,ì,ò,ù,ä,ë,ï,ö,ü,ÿ,â,ê,î,ô,û,å,e,i,ø,u,ã,õ,Ç,Æ,Œ,Á,É,Í,Ó,Ú,À,È,Ì,Ò,Ù,Ä,Ë,Ï,Ö,Ü,Ÿ,Â,Ê,Î,Ô,Û,Å,E,I,Ø,U,Ã,Õ,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,±");
		$authorized = explode(",","c,ae,oe,a,e,i,o,u,a,e,i,o,u,a,e,i,o,u,y,a,e,i,o,u,a,e,i,o,u,a,o,C,AE,OE,A,E,I,O,U,A,E,I,O,U,A,E,I,O,U,Y,A,E,I,O,U,A,E,I,O,U,A,O,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,+");
			
		$name = str_replace($denied, $authorized, $name);
		$email = str_replace($denied, $authorized, $email);

		$telephone = $form_state['values']['ddd'].$form_state['values']['phone'];
		$telephone = str_replace (' ', '', $telephone);
		$telephone = str_replace ('-', '', $telephone);
		$telephone = str_replace ('(', '', $telephone);
		$telephone = str_replace (')', '', $telephone);
		
		$family = "blog_lp";
		
		$subscription = array();
		$subscription[] = ASTROCENTRO_BR_COM_WS_WENGO_API_KEY; // API Key
		$subscription[] = NULL; //login
		$subscription[] = urlencode($email); //email
		$subscription[] = NULL; //password
		$subscription[] = urlencode($name);
		$subscription[] = "0055".$telephone;
		$subscription[] = "por";
		$subscription[] = "bra";
		$subscription[] = "1"; //population
		$subscription[] = "v2_9488"; //tracker
		$subscription[] = NULL;
		$subscription[] = "hdk_prospect";
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = NULL;
		$subscription[] = "1270";
		$subscription[] = $family;
		
		$data_s = '?method=create_generic_prospect_v1&args[]='.implode('&args[]=', $subscription);
		watchdog("iframe_lead_form", "call {$ws}{$data_s}");
		
		$r = drupal_http_request($ws.$data_s, array(
			'method' => "get",
		));
		$check = json_decode( $r->data, true );
		
		if ( $check["status_code"] == "0" ) {
			$_SESSION['confirmation_msg'] = '
				<p><strong>Vamos te ligar em breve.</strong></p>
				<p>Veja os esotéricos disponíveis</strong> e peça para falar com seu favorito ao receber nossa ligação.</p>
				<p><a href="http://astrocentro.com.br/tarot-videncia/?payload[page]=consultas-por-telefone&tracker_id=v2_9681" class="btn btn-default" target="_parent">Escolher<br>meu esotérico</a></p>';
			$_SESSION['class'] = 'text-success';
		}else if( $check["status_details"]["trusted_errdesc"] == "email already exist" ){
			$_SESSION['confirmation_msg'] = '
				<p>Esse email já está cadastrado.</p>
				<p><input class="btn btn-default" type="button" value="Tente novamente" onClick="window.location.reload()"></p>';
			$_SESSION['class'] = 'text-warning';
		}else{
			$_SESSION['confirmation_msg'] = '
				<p>Houve um problema técnico.</p>
				<p><input class="btn btn-default" type="button" value="Tente novamente" onClick="window.location.reload()"></p>';
			$_SESSION['class'] = 'text-danger';
		}
		
		$form_state['no_cache'] = TRUE;
		
		//debug
		global $user;
		if($user->uid == 1){
			echo "<pre>";var_dump($ws.$data_s);echo "</pre>";
			echo "<pre>";var_dump($r);echo "</pre>";
			echo "<pre>";var_dump($check);echo "</pre>";
			echo "<pre>";var_dump($check["status_code"]);echo "</pre>";
			echo "<pre>";var_dump("0055".$telephone);echo "</pre>";
			
			die();
		}
	}
	
}

function astrocentro_br_app_iframe_leads_page(){
	if( !isset($_SESSION) ){
		session_start();
	}
	$timeout = 5;
	 
	if(isset($_SESSION['timeout'])) {
		$duration = time() - (int)$_SESSION['timeout'];
		if($duration > $timeout) {
			session_destroy();
			session_start();
		}
	}
	$_SESSION['timeout'] = time();
	
	if (isset ($_SESSION['confirmation_msg']) ){
		$confirmation = $_SESSION['confirmation_msg'];
		$class = $_SESSION['class'];
		$hide = "hide";
	}else{
		$confirmation = null;
		$class = null;
		$hide = null;
	}
	
	$form = drupal_get_form('lead_form');

	$content = '
	
<style>
body{
	background-color:#f9f9f9;}
	
	.alert{
		display:none;}
	.succes{
		color:#3c763d;
		font-weight:700;}
	.warning{
		color:#8a6d3b;
		font-weight:700;}
	.error{
		color:#a94442;
		font-weight:400;}
		input.error{
			border-color:#a94442}
		label.error{
			display:none !important}
	.messages{
		text-align:left}
		.messages p{
			margin-bottom:10px;}
	.hide{
		display:none}
	
	.container{
		padding-right:0;
		padding-left:0;
		margin-right:0;
		margin-left:0;
		width:100%;}
		
			.row{
				margin-left:0 !important;
				margin-left:0 !important;}

			#formwrapper{
				width:188px;
				height:385px;
				
				background-color: #fff;
				border-color: #d4d4d4;
				border-image: none;
				border-style: solid;
				border-width: 1px 1px 1px 5px;
				margin: 0 0 10px;
				padding: 8px;
				color:#999999;}
				
				#formwrapper + p{
					margin:0}
				
					.text-success, .text-warning, .text-error{
						padding-top: 30px;
						margin-bottom:10px}
				
				#formwrapper hr{
					margin-top:5px;
					margin-bottom:5px;}
				
				#formwrapper .form-item-ddd{
					width:30%;
					float:left;}
					
				#formwrapper .form-item-phone{
					width:65%;
					float:right;}
					
				#formwrapper .form-control,
				#formwrapper .btn-lg{
					border-radius:2px !important;}
				#formwrapper .form-control{
					height:28px;
					padding:3px 6px;}
					
				#formwrapper .form-item-ddd .LV_validation_message,
				#formwrapper .form-item-phone .LV_validation_message{
					display:none;}
					
				#formwrapper .btn-default{
					background-color:#B83D83 !important;
					color:#fff;
					display: block;
					width: 100%;
					padding: 7px 16px;
					font-size: 16px;
					line-height: 1.33;}
					#formwrapper #edit-submit:hover{
						color:#B83D83;
						background-color:#fff !important;}
			
		.col-sm-12{
			padding-right:0 !important;
			padding-left:0 !important;}
			
		.footer{
			border:0 !important;}
	
</style>
	
<div class="container">
	<div class="row">';
		$content .= '<div id="formwrapper"><p class="'.$hide.'"><strong>Primeira vez aqui?<br>5 min. de consulta por telefone GRÁTIS</strong><br>Um esotérico te liga imediatamente<br>Experimente!</p><hr class="'.$hide.'"/>';
		$content .= '<div class="messages '.$class.'">'.$confirmation.'</div>';
		$content .= '<div class="'.$hide.'">' . drupal_render($form) . '</div>';
		$content .= '</div>';
		$content .='
	</div>
</div>
<script>
	document.domain = "astrocentro.com.br"
</script>

	';
	
	return $content;

}