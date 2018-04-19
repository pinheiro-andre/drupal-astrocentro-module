<?php


function astrocentro_br_app_midia_page(){
	

	$path = drupal_get_path('theme', 'astrocentro_br_v2');
	drupal_add_css($path . '/css/midia.css');

	
	// Metatags
	$page_keywords = array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
        	'name' => 'keywords',
          	'content' => 'tarot do amor, jogar tarot do amor, cartas tarot do amor, amor atraves das cartas, amor baralho cigano, amor tarot online, amor tarot web, amor taror site',
        )
	);
    drupal_add_html_head($page_keywords, 'page_keywords');
	
    $page_description = array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
        	'name' => 'description',
          	'content' => 'Saiba como será o seu futuro amoroso. Tire uma das cartas de nosso Tarot do Amor Online!',
        )
	);
    drupal_add_html_head($page_description, 'page_description');
		
	$content = "
			<h1 id='page-title' class='title'>Mídia</h1>
			
			<img src='/{$path}/images/celi-midia.jpg'>
			
			<p>Previsões sobre o futuro, sua vida amorosa, trabalho, sorte, dinheiro e família, feitas por videntes experientes, você encontra aqui no Astrocentro.</p>
			<p>Nossa taróloga <strong>Celi Coutinho</strong> faz leitura de tarot para encontrar as respostas para suas maiores dúvidas.</p>
			<p><strong>Toda sexta-feira, às 19h, na Rádio Mundial</strong>, a esotérica e taróloga Celi Coutinho apresenta o programa Seu Destino na Linha no qual atende os ouvintes e <strong>faz previsões sobre o futuro</strong>.</p>
			
			<section id='midia-playlist'>
				
			</section>
	";
	
	$content .= "


<script type='text/javascript' src='/{$path}/js/jquery-jplayer/jquery.jplayer.js'></script>
<script type='text/javascript' src='/{$path}/js/ttw-music-player-min.js'></script>
<script type='text/javascript' src='/{$path}/media/midia-audio-playlist.js'></script>

<script type='text/javascript'>
	var $ = jQuery.noConflict();
	
	$(document).ready(function(){
		var description = '';

		$('body section#midia-playlist').ttwMusicPlayer(myPlaylist, {
			autoPlay:false, 
			description:description,
			jPlayer:{
				swfPath:'/{$path}/js/jquery-jplayer/' //You need to override the default swf path any time the directory structure changes
			}
		});
	});
</script>
	";
	
	return $content;
}
