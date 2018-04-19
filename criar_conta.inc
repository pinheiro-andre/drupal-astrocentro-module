<?php

function astrocentro_br_app_criar_conta_page(){
	

	$path = drupal_get_path('theme', 'astrocentro_br_v2');
	drupal_add_css($path . '/css/criar-conta.css');

	
	// Metatags
	$page_keywords = array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
        	'name' => 'keywords',
          	'content' => 'Tarot - Videncia - Os melhores especialistas em Tarot - Videncia respondem em directo, por telefone, a todas as suas perguntas.',
        )
	);
    drupal_add_html_head($page_keywords, 'page_keywords');
	
    $page_description = array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
        	'name' => 'description',
          	'content' => 'Saiba como criar uma conta na Astrocentro',
        )
	);
    drupal_add_html_head($page_description, 'page_description');
	
	$content = "
			<section class='tabs'>
				<input id='tab-1' type='radio' name='radio-set' class='tab-selector-1' checked='checked' />
				<label for='tab-1' class='tab-label-1'>Escolher seu esotérico</label>

				<input id='tab-2' type='radio' name='radio-set' class='tab-selector-2' />
				<label for='tab-2' class='tab-label-2'>Perfil dos esotéricos</label>

				<input id='tab-3' type='radio' name='radio-set' class='tab-selector-3' />
				<label for='tab-3' class='tab-label-3'>Consultar um esotérico</label>
			
				<div class='spacer'></div>
			
				<div class='content-tabs'>
					<div class='content-1'>
						<div class='video-content'>
							<div class='js-video widescreen'>
								<iframe class='yt_players' id='player0' width='640' height='360' src='http://www.youtube.com/embed/2ZSO5aIZlWU?rel=0&wmode=opaque&showinfo=0&controls=1&autohide=1&rel=0&showsearch=0&theme=light&enablejsapi=1&html5=1;'
					frameborder='0' allowfullscreen></iframe>
							</div>
						</div>
						
						<ul>
							<li>O Astrocentro lhe propõe <strong>diferentes maneiras de escolher seu esotérico</strong>.</li>
							<li>Na home você escolhe: os <strong>especialistas disponíveis</strong>, os esotéricos </strong>mais consultados</strong>, os tarólogos <strong>com melhor pontuação</strong> e os </strong>novos tarólogos</strong>.</li>
							<li>No menu horizontal <strong>por tipo de atendimento</strong>: <a href='http://astrocentro.com.br/tarot-videncia/' title='por telefone'>Telefone</a>, <a href='http://astrocentro.com.br/tarot-videncia/?payload[page]=consultas-por-email&wl=140' title='por email'>email</a> ou <a href='http://astrocentro.com.br/tarot-videncia/?payload[page]=sua-videncia-por-chat&wl=140' title='por chat'>chat</a>.</li>
							<li>No menu horizontal <strong>por especialidade</strong>: 
								<ul class='fa-ul'>
									<li><i class='fa-li fa fa-chevron-right'></i><a href='http://astrocentro.com.br/tarot-videncia/index.php?payload[idDirectory]=1270&payload[page]=especialidade-tarologia&wl=140' title='Tarólogos'>Tarólogos</a></li>
									<li><i class='fa-li fa fa-chevron-right'></i><a href='http://astrocentro.com.br/tarot-videncia/index.php?payload[idDirectory]=1270&payload[page]=especialidade-numerologia&wl=140' title='Numerólogos'>Numerólogos</a>,</li>
									<li><i class='fa-li fa fa-chevron-right'></i><a href='http://astrocentro.com.br/tarot-videncia/index.php?payload[idDirectory]=1270&payload[page]=especialidade-videncia&wl=140' title='Videntes'>Videntes</a></li>
									<li><i class='fa-li fa fa-chevron-right'></i><a href='http://astrocentro.com.br/tarot-videncia/index.php?payload[idDirectory]=1270&payload[page]=especialidade-astrologia&wl=140' title='Astrólogos'>Astrólogos</a></li>
								</ul>
							</li>
						</ul>
						
						<a class='butao small bordeaux' href='http://astrocentro.com.br/tarot-videncia/'><span><i class='fa fa-users fa-lg'></i> Quer consultar?</span></a>
						
					</div>
					<div class='content-2'>
						<div class='video-content'>
							<div class='js-video widescreen'>
								<iframe class='yt_players' id='player1' width='640' height='360' src='http://www.youtube.com/embed/CMbg5yLZyxw?rel=0&wmode=opaque&showinfo=0&controls=1&autohide=1&rel=0&showsearch=0&theme=light&enablejsapi=1&html5=1;'
						frameborder='0' allowfullscreen></iframe>
							</div>
						</div>
						
						<ul>
							<li>Descubra o <strong>perfil dos esotéricos</strong> do Astrocentro.</li>
							<li>A ficha do esotérico é composta por três blocos distintos:
								<ul>
									<li>O primeiro bloco <strong>apresenta o esotérico</strong>, sua foto, especialidades, experiência e resumo do perfil.</li>
									<li>O segundo apresenta seus diferentes <strong>canais de atendimento</strong>, os <strong>valores</strong> e a <strong>disponibilidade</strong>
								do especialista.</li>
									<li>O terceiro apresenta as <strong>disponibilidades semanais</strong> para agendamento, seu <strong>perfil completo</strong>, a <strong>pontuação</strong> e <strong>comentários dos clientes</strong>.</li>
								</ul>
							</li>
						</ul>
						
						<a class='butao small bordeaux' href='http://astrocentro.com.br/tarot-videncia/'><span><i class='fa fa-users fa-lg'></i> Quer consultar?</span></a>
					</div>
					<div class='content-3'>
						<div class='video-content'>
							<div class='js-video widescreen'>
								<iframe class='yt_players' id='player2' width='640' height='360' src='http://www.youtube.com/embed/oU4vVKqK7wo?rel=0&wmode=opaque&showinfo=0&controls=1&autohide=1&rel=0&showsearch=0&theme=light&enablejsapi=1&html5=1;'
						frameborder='0' allowfullscreen></iframe>
							</div>
						</div>
						
						<ol>
							<li>Para se cadastrar on line você precisa <strong>escolher seu esotérico</strong> e em seu perfil o canal de atendimento desejado.</li>
							<li>Insira seu email, senha, um nome de usuário e aceite as condições de uso.</li>
							<li>Informe o número do telefone, celular ou fixo, no formato internacional <em>(005511)</em>.</li>
							<li>Confira e valide o preço do serviço.</li>
							<li>Informe os dados do cartão de crédito (número do cartão, data de validade, código de de segurança e nome do titular).</li>
							<li>Sua consulta começará em seguida.</li>
						</ol>

						<a class='butao small bordeaux' href='http://astrocentro.com.br/tarot-videncia/'><span><i class='fa fa-users fa-lg'></i> Quer consultar?</span></a>
					</div>
				</div>
			</section>
	";
	
	$content .= "
		<!-- Handling videos playlist-->
		<script type='text/javascript'>

		
//load youtube iframe api
var tag = document.createElement('script');
tag.src = 'http://www.youtube.com/player_api';
var firstScriptTag = document.getElementsByTagName('script')[0];
firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);
		
		
		players = new Array();
		function onYouTubeIframeAPIReady() {
			var temp = jQuery('iframe.yt_players');
			for (var i = 0; i < temp.length; i++) {
				var t = new YT.Player(jQuery(temp[i]).attr('id'), {
					events: {
						'onStateChange': onPlayerStateChange
					}
				});
				players.push(t);
			}

		}
		onYouTubeIframeAPIReady();


		function onPlayerStateChange(event) {

			if (event.data == YT.PlayerState.PLAYING) {
				var temp = event.target.a.src;
				var tempPlayers = jQuery('iframe.yt_players');
				for (var i = 0; i < players.length; i++) {
					if (players[i].a.src != temp) players[i].stopVideo();

				}
			}
		}
		
		</script>
	";
	
		
	
	return $content;
}
