#include <Game.h>

Game::Game(unsigned int width, unsigned int height): count(0)
{
	// 1 - Initialization of SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		exit(3);
	}

	m_gameState = GameState::PLAY;

	Renderer::initialize(width, height);

	loadMap();

	move[0] = 0;
	move[1] = 0;
}

Game::~Game()
{
	delete m_map;
	//delete m_hero;
}

void Game::run()
{
	gameLoop();
	endGame();
}

void Game::gameLoop()
{
	//// The main event loop
	while (m_gameState != GameState::EXIT)
	{
		m_frameStart = SDL_GetTicks();

		// 1 - We handle events 
		handleEvent();

		// 2 - We update the simulation
		update();
		
		// 3 - We render the scene
		render();

		//4 - We limit the frame rate
		m_frameTime = SDL_GetTicks() - m_frameStart;
		if (_frameDelay > m_frameTime) {
			SDL_Delay(_frameDelay - m_frameTime);
		}
	}
}

void Game::handleEvent()
{
	SDL_Event event;
	
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			std::cout << "Exit signal detected" << ::std::endl;
			m_gameState = GameState::EXIT;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case 'q':
				std::cout << "Exit signal detected" << ::std::endl;
				m_gameState = GameState::EXIT;
				break;
			case SDLK_RETURN:
				std::cout << "Enter" << ::std::endl;
				break;
			case SDLK_RIGHT:
				std::cout << "Right down" << ::std::endl;
				break;
			case SDLK_LEFT:
				std::cout << "Left down" << ::std::endl;
				break;
			case SDLK_UP:
				std::cout << "Up down" << ::std::endl;
				break;
			case SDLK_DOWN:
				std::cout << "Down down" << ::std::endl;
				break;
			case SDLK_SPACE:
				std::cout << "space down" << ::std::endl;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				std::cout << "Left up" << ::std::endl;
				break;
			case SDLK_RIGHT:
				std::cout << "Right up" << ::std::endl;
				break;
			case SDLK_UP:
				std::cout << "up up" << ::std::endl;
				break;
			case SDLK_DOWN:
				std::cout << "down up" << ::std::endl;
				break;
			case SDLK_SPACE:
				std::cout << "space up" << ::std::endl;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}

}

void Game::update()
{
	++count;
	std::cout << count << std::endl;

	m_hero->update();
}

void Game::render()
{
	m_map->drawMap();
	m_hero->render();
	Renderer::getInstance()->flush();
}

void Game::endGame()
{
	std::cout << "Shutting down renderer..." << std::endl;
	Renderer::finalize();
	std::cout << "Shutting down SDL" << std::endl;
	SDL_Quit();
}

void Game::loadMap(std::string filename)
{
	m_map = new Map(filename);

	m_hero = new Hero(m_map, "ressources/player/p1_walk01.png", Vector2<int>(0, 0), "SuperHero");

}

