<?php

function astrocentro_br_app_astrocentrotv_page(){
	
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
	

/*
echo "Playlist Name: ".$info["title"]['$t'].'<br/>';
echo "Number of Videos (".$nVideo."):<br/>";
*/


		
	$content = "
			
			<!-- <div class='group'>
				<a class='butao small pink filter' href='' onclick='return false;' data-filter='all'><span><i class='fa fa-youtube-play fa-lg'></i> Todos os vídeos</span></a>
				<a class='butao small bordeaux filter' href='' onclick='return false;' data-filter='.amor'><span><i class='fa fa-tag fa-lg'></i> Amor</span></a>
				<a class='butao small bordeaux filter' href='' onclick='return false;' data-filter='.dinheiro'><span><i class='fa fa-tag fa-lg'></i> Dinheiro</span></a>
				<a class='butao small bordeaux filter' href='' onclick='return false;' data-filter='.trabalho'><span><i class='fa fa-tag fa-lg'></i> Trabalho e empresa</span></a>
				<a class='butao small bordeaux filter' href='' onclick='return false;' data-filter='.sorte'><span><i class='fa fa-tag fa-lg'></i> Sorte e proteção</span></a>
				<a class='butao small bordeaux filter' href='' onclick='return false;' data-filter='.outros'><span><i class='fa fa-tag fa-lg'></i> Outras dúvidas</span></a>
			</div> --> 
			
			<!-- <p>introduction text? or banner?</p> --> 
			
			<form class='controls' id='Filters'>
				<fieldset>
					<div class='group'>
						<h4>Filtrar por tematica</h4>
						<select>
							<option value=''>Todos os vídeos</option>
							<option value='.Amor'>Amor</option>
							<option value='.Dinheiro'>Dinheiro</option>
							<option value='.Trabalho'>Trabalho e empresa</option>
							<option value='.Sorte'>Sorte e proteção</option>
							<option value='.Outras'>Outras dúvidas</option>
						</select>
					</div>
				
					<!-- <div class='group'>
						<h4>Filtar por data</h4>
						<a class='butao small bordeaux sort' data-sort='sort:asc' href='' onclick='return false;'><span>os mais antigos</span></a>
						<a class='butao small bordeaux sort' data-sort='sort:desc' href='' onclick='return false;'><span>os mais recentes</span></a>
					</div> --> 
					
					<!-- <div class='group'>
						<h4>Filtrar por videntes</h4>
						<select>
							<option value=''>Todos os videntes</option>
							<option value='.amor'>vidente 1</option>
							<option value='.dinheiro'>vidente 2</option>
							<option value='.trabalho'>vidente 3</option>
							<option value='.sorte'>vidente 4</option>
							<option value='.outras'>vidente 5</option>
						</select>
					</div> --> 
				</fieldset>
			</form>

			<div id='grid-videos' class='grid-videos'>";
				
/* Obtenir playlist youtube */
	$playlist_id = "Y2UREXLVn8yQl3-QBAZZVtKA--gBP5L6";
	$yt_api_key = "AI39si7nmVaOGMTu8xXEZXz4VOPi5ydqX8KNputyFpR6_ZuILQx5oq4vShObstDiTAmkTe-4bC9am2qitbmE43VmOaVid28RVw";
	$url = "https://gdata.youtube.com/feeds/api/playlists/".$playlist_id."?v=2&key=".$yt_api_key."&alt=json";
	$data = json_decode(file_get_contents($url),true);
	$info = $data["feed"];
	$video = $info["entry"];
	$nVideo = count($video);
				
	for($i=0;$i<$nVideo;$i++){
	
		$video_name = $video[$i]['title']['$t'];
		$video_link = $video[$i]['link'][0]['href'];
		$video_id = explode("?v=", $video_link);
		if (empty($video_id[1]))
			$video_id = explode("/v/", $link);

		$video_id = explode("&", $video_id[1]);
		$video_id = $video_id[0];
		
		$video_thumb = $video[$i]['media$group']['media$thumbnail'][1]['url'];
		$video_description = $video[$i]['media$group']['media$description']['$t'];
		$video_description = preg_replace('@((www|http://)[^ ]+)@', '<a href="\1">\1</a>', $video_description);
		$video_filter = substr($video[$i]['media$group']['media$description']['$t'], strpos($video[$i]['media$group']['media$description']['$t'], "Categoria: ") +11);
		$video_date_pre = $video[$i]['media$group']['yt$uploaded']['$t'];
		$video_date = date('ymd', strtotime($video_date_pre));
		$video_publication_date = date('d/m/y', strtotime($video_date_pre));
	
				
		$content .= "<div class='mix ".$video_filter."' data-sort='".$video_date."'>
						<div class='box-video'>
							<a href='#{$video_id}' class='open-popup-link youtube'>
								<div class='video-circle'><div class='video-arrow'></div></div>
								<img src='".$video_thumb."' />
							</a>
							
							<div id='".$video_id."' class='mfp-hide video-content'>
								<div class='js-video widescreen'>
									<iframe class='yt_players' id='player{$i}' width='640' height='360' src='//www.youtube.com/embed/{$video_id}?list=PL{$playlist_id}&rel=0&wmode=opaque&showinfo=0&controls=1&theme=light&enablejsapi=1&html5=1&autoplay=0;'
							frameborder='0' allowfullscreen></iframe>
								</div>
							</div>
						</div>
						<div class='box-caption'>
							<div class='box-title'>".$video_name."</div>
							<p>".$video_description."</p>
							
							<div class='box-caption-bottom'>
								<div class='time'>
									Publicado dia ".$video_publication_date."
								</div>
							</div>     
						</div>
					</div>";
	}
			
	$content .="
			  
			  <div class='gap'></div>
			</div>
			
			
	";
	
	return $content;
}
