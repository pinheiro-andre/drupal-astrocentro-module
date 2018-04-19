<?php

function astrocentro_br_app_tarot_do_amor_page(){

	$path = drupal_get_path('theme', 'astrocentro_br_v2');
	drupal_add_css($path . '/css/tarot-do-amor.css');
	drupal_add_js(drupal_get_path('theme', 'astrocentro_br_v2') . '/js/tarot-do-amor.js');
	
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
			<h1 id='page-title' class='title'>Tarot do Amor</h1>
			<p>Descubra no jogo de Tarot do Amor respostas imediatas para as suas dúvidas sobre relacionamentos.</p>
			<p>Receba orientações sobre o seu futuro amoroso com nosso jogo de Tarot, online e gratuito.</p>";
	
	$content .=  "
				<div id='popup_form' class='popup_block white-popup mfp-with-anim mfp-hide'>
					<h2 style='text-align:center; color:#CB00B1;'>Cadastro Astrocentro</h2>
					<p>Você precisa de um cadastro ativo para fazer uma consulta com um tarólogo do Astrocento.<br/>Complete os campos abaixo com seus dados para começar!</br /><a href='http://astrocentro.com.br/consultas/?wl=140&tracker_id=v2_7861'>Você já é cliente?</a></p>
					<iframe src=\"https://br222.hostgator.com.br/~viden718/projects/astrocentro-v2/index--prod.php?tracker_id=v2_7861\" noresize=\"noresize\" width=\"100%\" height=\"400\" scrolling=\"no\" style=\"border:none; margin-top:20px;\"></iframe>
				</div>";
	
	$content .= "
        	<div id='tarot-do-amor'>
				<h3 class='title-game'>Quais são as perspectivas da minha vida amorosa?</h3>
				<p>Por favor, concentre-se em sua pergunta por alguns instantes. Em seguida, escolha uma carta.</p>
			
            	<ul id='index_cards'>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                	<li><a href='#tirage' class='mychoice' data-effect='mfp-zoom-out'></a></li>
                </ul>
				
				<div id='readingcards'>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/0.jpg' />
						<h4>O MAGO</h4>
						<p>Período que aponta para um potencial criativo.<br>Você vai entrar num período de reconciliação ou de harmonia no seu romance. Aproveita deste momento sem tristeza e sem rotina.</p>
						<p>Quer fazer uma consulta de Tarot com um dos tarológos do Astrocentro? Deixe seu contato</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/1.jpg' />
						<h4>A PAPISA</h4>
						<p>Período de brilho e sucesso.<br>Esta carta simboliza o equilíbrio dos seus sentimentos. Os seus desejos serão protegidos e você vai ultrapassar as fraquezas.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/2.jpg' />
						<h4>A IMPERATRIZ</h4>
						<p>Ela representa a colheita dos nossos anseios mais íntimos.<br>Esta carta simboliza a realização pessoal. Anúncio de um período de ternura e de compreensão. Ela pode significar uma união forte, um casamento ou um filho.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/3.jpg' />
						<h4>O IMPERADOR</h4>
						<p>Simboliza o poder, a riqueza.<br>Possibilidade de conhecer alguém de dotes elevados. Indica o casamento com alguém de boa situação financeira e de bom carácter.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/4.jpg' />
						<h4>O PAPA</h4>
						<p>Poder espiritual, autoridade, dever moral.<br>Esta carta simboliza o possível retorno de alguém do passado ou o casamento com alguém de certa experiência na vida.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/5.jpg' />
						<h4>OS ENAMORADOS</h4>
						<p>Livre-arbítrio; visão para resolver problemas, renúncia aos prazeres. Momento de escolha.<br>Você vai atravessar um momento de escolha. Deverá confiar em sua própria voz interior. É possível que o seu (sua) namorado(a) não seja a pessoa de quem você ' realmente.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/6.jpg' />
						<h4>O CARRO</h4>
						<p>Equilíbrio, sucesso, triunfo.<br>Seus desejos poderão se realizar. Tenha fé. Esta carta anuncia uma aproximação amorosa.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/7.jpg' />
						<h4>A JUSTIÇA</h4>
						<p>É a reação de equilibrio entre o direito e o dever. <br>Você vai viver um amor sem cobrança. Você deve ter cuidado do não provocar brigas.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/8.jpg' />
						<h4>O EREMITA</h4>
						<p>Ele pede que andemos mais devagar em nossa vida, analisando tudo que estiver em nosso alcance. <br>Você tem saudades da pessoa amada. Você vai atraversar um período de solidão mas é para sua evolução afectiva.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/9.jpg' />
						<h4>A RODA DA FORTUNA</h4>
						<p>Mudanças estão para acontecer em sua vida que serão de repente. <br>Aproveite dos momentos com o seu amor. Viva com intensidade o dia de hoje! Esta carta pode anunciar um casamento e uma boa situação financeira.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/10.jpg' />
						<h4>A FORÇA</h4>
						<p>Inteligência, sucesso, magnetismo sexual.<br>Você vai conhecer uma nova situação sentimental. Você vai encontrar uma pessoa com muito entusiasmo pela vida que mudará seu modo de viver.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/11.jpg' />
						<h4>O ENFORCADO</h4>
						<p>Idealismo exagerado, sacrificio, acomodação, possibilidade de escolha errada.<br>Cuidado com traição e abandono. Poderá haver uma separação que resultará em crescimento interior para os dois.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/12.jpg' />
						<h4>A MORTE</h4>
						<p>Transformação radical, possibilidade de mudanças, de país de cidade ou de casa. Novas perspectivas.<br>Esta carta promete novidades no amor. Você vai conhecer uma renovação da sua situação amorosa.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/13.jpg' />
						<h4>A TEMPERANZA</h4>
						<p>Representa a serenidade e eficiência <br>Período de união, de convivência harmoniosa. Você vai conhecer um amor sereno. No futuro, você terá a possibilidade de um bom casamento com uma pessoa altamente espiritualizada.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/14.jpg' />
						<h4>O DIABO</h4>
						<p>Força misteriosa, sedução<br>Procure ver se este relacionamento não é só paixão e se poderá trazer dor mais tarde ou sofrimento. Pode também significar que o casamento marcado pode não se realizar.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/15.jpg' />
						<h4>A TORRE</h4>
						<p>Dificuldades gerais, destruição, orgulho desmedido<br>Rompimento que poderá ser inivitavel, você não sinte o amor como antigamente.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/16.jpg' />
						<h4>A ESTRELA</h4>
						<p>Esperança, uma grande sorte por vir.<br>Perído de muita paz e tranquilidade no Romance. Pode significar que numa relação amorosa que foi interrompida existe a possibilidade de reatar.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/17.jpg' />
						<h4>A LUA</h4>
						<p>Advertência, forças ocultas, alerta.<br>Esta carta anuncia momentos de magia e de serenidade com o seu amor.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/18.jpg' />
						<h4>O SOL</h4>
						<p>Realização, êxito. <br>Esta carta promete um reencontro. No futuro você vai conhecer um casamento feliz e triunfo.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/19.jpg' />
						<h4>O JUGALMENTO</h4>
						<p>Momento especial de reavaliação da vida.<br>Está para reaparecer um amor antigo que você julgava terminado.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/20.jpg' />
						<h4>O MUNDO</h4>
						<p>Deste momento em diante tudo na sua vida será realizações com unicamente bons acontecimentos<br>Possibilidade de encontro amoroso em pouco tempo. No futuro você vai conhecer um casamento prospero e feliz.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
					<div id='tirage' class='caption mfp-hide'>
						<img src='/{$path}/images/cards-tarot/21.jpg' />
						<h4>O LOUCO</h4>
						<p>Quando esta carta aparece numa consulta marca um tempo de instabilidade na vida <br>Prepare-se, esta carta anuncia a chegada de uma nova época, feliz e de plena harmonia com a pessoa amada.</p>
						<p class='talk'>
							<a href='#popup_form' class='butao medium bordeaux'><span><i class='fa fa-phone'></i>
								Quer fazer uma consulta de Tarot<br/>com um dos tarológos do Astrocentro?
							</span></a>
						</p>
						<div class='clearfix'></div>
					</div>
				</div>
				
			</div>
			<p class='notice'>Através do Tarot é possível descobrir as novidades sobre o futuro amoroso, profissional e familiar.</p>
			<p>O Tarot do amor é um oráculo poderoso que te guia ao autoconhecimento e promove o bem-estar, ao te trazer tranquilidade para tomar as decisões corretas.</p>
			<p>Não tenha mais dúvidas sobre o relacionamento, esclareça tudo agora com o jogo do Tarot do amor.</p>
			<p class='notice'><small>* (oferta válida para novos clientes do Astrocentro na sua primeira consulta de 10 minutos pagando com cartão de crédito)</small></p>
	";
	
		
	
	return $content;
}

function astrocentro_br_app_tarot_do_amor_step3_page(){
	
	$path = drupal_get_path('theme', 'astrocentro_br_v2');
	drupal_add_css($path . '/css/tarot-do-amor.css');

	if ((isset($_GET["wl"])) || (isset($_COOKIE["wl"]))) {
		$telephone_display = '(11) 4933-0754';
		$telephone_call = '+551149330754';
	} else {
		$telephone_display = '(11) 3957-1012';
		$telephone_call = '+551139571012';
	}
	
	$content ="
	<div class='final-step3'>
		<p>Um consultor do Astrocentro vai te ligar no horário comercial para agendar sua consulta.<br />Até breve!</p>
		<p>Quer se consultar agora?</p>
		<p style='margin-bottom:40px;'>Ligue para Astrocentro: <strong><a href='tel:".$telephone_call."'>".$telephone_display."</a></strong></p>
		
		<p><a href='/oraculos/tarot-do-amor-gratis' class='butao large bordeaux'><span><i class='fa fa-repeat'></i> Fazer nova leitura</span></a></p>
	</div>
	";
	
	return $content;
}