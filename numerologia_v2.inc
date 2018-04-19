<?php

function astrocentro_br_app_numerologia(){
	
	$detect = mobile_detect_get_object();
	$path = drupal_get_path('theme', 'astrocentro_br_v2');

	if ( $detect->isMobile() ) {
		$heightiframe = 5000;
	} else {
		$heightiframe = 3000;
	}
	
	// Metatags
	$page_keywords = array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
        	'name' => 'keywords',
          	'content' => 'Numerologia - Astrocentro',
        )
	);
    drupal_add_html_head($page_keywords, 'page_keywords');
	
    $page_description = array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
        	'name' => 'description',
          	'content' => 'Numerologia na Astrocentro',
        )
	);
    drupal_add_html_head($page_description, 'page_description');
	
	$content = "
			<style>
				#breadcrumbs{
					display:none;
				}
				h1{
					color: #a52a89;
				    margin: 0 0 20px 15px;
				}
				@media only screen and (max-width : 480px) {
					h1{
				    	margin: 20px auto;
				    	text-align: center;
					}
				}
				.numerologia-wrapper{
				    width: 100%;
				    height: 100%;
				    padding: 0px;
				    margin: 0px;
				    overflow: hidden;
				    font-size: 10px;
				    color: #6e6e6e;
				    background-color: #fff;
				}
				#numerologia-iframe{
				    width: 100%;
				    background-color: #fff;
				}
			</style>

			<h1>Numerologia Online</h1>

			<div class=\"numerologia-wrapper\">
				<iframe id=\"numerologia-iframe\" src=\"http://www.astrocentro.com.br/jogos/numerologia/index.php?tracker_id=v2_15012\"  noresize=\"noresize\" width=\"100%\" height=\"{$heightiframe}\" scrolling=\"no\" ></iframe>
			</div>
	";
	
	return $content;
}
