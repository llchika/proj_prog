#include <Game.h>

#include <Collision.h>
#include <Entity.h>
#include <vector>

Game::Game(unsigned int width, unsigned int height): count(0) {
	// 1 - Initialization of SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		exit(3);
	}

	m_gameState=GameState::PLAY;

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

void Game::handleEvent() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            std::cout << "Exit signal detected" << ::std::endl;
            m_gameState = GameState::EXIT;
        }
        else if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
                switch(event.key.keysym.sym) {
                case 'q':
                    std::cout << "Exit signal detected" << ::std::endl;
                    m_gameState = GameState::EXIT;
                    break;
                case 'e':
                    std::cout << "Lancement du jeu" << ::std::endl;
                    m_gameState = GameState::PLAY;
                    break;
                case SDLK_UP:
                    m_hero->modif_dir(Hero::sens::UP);
                    break;
                case SDLK_DOWN:
                    m_hero->modif_dir(Hero::sens::DOWN);
                    break;
                case SDLK_RIGHT:
                    m_hero->modif_dir(Hero::sens::RIGHT);
                    break;
                case SDLK_LEFT:
                    m_hero->modif_dir(Hero::sens::LEFT);
                    break;
                case SDLK_SPACE:
                    std::cout << "space down" << ::std::endl;
                    break;
                default:
                    break;
                }
        }
        else {
            m_hero->setPosition(m_hero->getPosition()+(Vector2<int>(0,0)));
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

