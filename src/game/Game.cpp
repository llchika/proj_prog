#include <Game.h>

Game::Game(unsigned int width, unsigned int height): count(0) {
	// 1 - Initialization of SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		exit(3);
	}

	m_gameState = GameState::INIT;

	Renderer::initialize(width, height);

	loadMap();

	move[0]=0;
	move[1]=0;
}

Game::~Game() {
	delete m_map;
	//delete m_hero;
}

void Game::run() {
	SDL_Texture* ecran_titre=TextureManager::loadTexture("ressources/ecran_titre.png");
	SDL_Rect m_srcRect, m_destRect;
	
	m_srcRect.x=m_srcRect.y=0;
	m_srcRect.w=m_destRect.w=JeuESIR::screenWidth;
	m_srcRect.h=m_destRect.h=JeuESIR::screenHeight;
	m_destRect.x=JeuESIR::screenWidth;
	m_destRect.y=JeuESIR::screenHeight;

	TextureManager::draw(ecran_titre, m_srcRect, m_destRect);

	Renderer::getInstance()->flush();
	
	while (m_gameState==GameState::INIT) {
		startScreen();
		m_frameTime = SDL_GetTicks() - m_frameStart;
			if (_frameDelay > m_frameTime) {
				SDL_Delay(_frameDelay - m_frameTime);
		}
	}
	gameLoop();
	endGame();
}

void Game::gameLoop() {
	// Boucle principale
	while (m_gameState!=GameState::EXIT) {
		while (m_gameState==GameState::PLAY) {
			m_frameStart=SDL_GetTicks();
			
			handleEvent();
			update();
			render();

			m_frameTime = SDL_GetTicks() - m_frameStart;
			if (_frameDelay > m_frameTime) {
				SDL_Delay(_frameDelay - m_frameTime);
			}
		}
	}
}

void Game::startScreen() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				std::cout << "Exit signal detected" << ::std::endl;
				m_gameState=GameState::EXIT;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case 'q':
						std::cout << "Exit signal detected" << ::std::endl;
						m_gameState = GameState::EXIT;
						break;
					case 'e':
						std::cout << "Lancement du jeu" << ::std::endl;
						m_gameState = GameState::PLAY;
						break;
					default:
						break;
					}
			default:
				break;
		}
	}
}

void Game::handleEvent() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				std::cout << "Exit signal detected" << ::std::endl;
				m_gameState=GameState::EXIT;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case 'q':
						std::cout << "Exit signal detected" << ::std::endl;
						m_gameState = GameState::EXIT;
						break;
					case SDLK_RETURN:
						std::cout << "Enter" << ::std::endl;
						break;
					case SDLK_UP:
						m_hero->setPosition(m_hero->getPosition()+(Vector2<int>(0,1)));
						break;
					case SDLK_DOWN:
						m_hero->setPosition(m_hero->getPosition()+(Vector2<int>(0,-1)));
						break;
					case SDLK_RIGHT:
						m_hero->setPosition(m_hero->getPosition()+(Vector2<int>(1,0)));
						break;
					case SDLK_LEFT:
						m_hero->setPosition(m_hero->getPosition()+(Vector2<int>(-1,0)));
						break;
					case SDLK_SPACE:
						std::cout << "space down" << ::std::endl;
						break;
					default:
						break;
					}
			default:
				break;
		}
	}
}

void Game::update() {
	++count;
	m_hero->update();
}

void Game::render() {
	m_map->drawMap();
	m_hero->render();
	Renderer::getInstance()->flush();
}

void Game::endGame() {
	std::cout << "Shutting down renderer..." << std::endl;
	Renderer::finalize();
	std::cout << "Shutting down SDL" << std::endl;
	SDL_Quit();
}

void Game::loadMap(std::string filename) {
	m_map=new Map(filename);
	m_hero=new Hero(m_map, "ressources/player/p1_walk01.png", Vector2<int>(0, 0), "SuperHero");
}

