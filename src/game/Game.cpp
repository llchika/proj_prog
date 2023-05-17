#include <Game.h>

#include <Collision.h>
#include <Entity.h>
#include <vector>
#include <Hearth.h>


Game::Game(unsigned int width, unsigned int height): count(0), count_kill(0) {
	// 1 - Initialization of SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		exit(3);
	}

	m_gameState=GameState::INIT;

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
        while (m_gameState==GameState::INIT) {
            m_frameStart=SDL_GetTicks();

            handleEvent();
			render();

        }
		while (m_gameState==GameState::PLAY) {
			m_frameStart=SDL_GetTicks();


            //surement gourmand, si c'est trop lent changer de place
            std::vector<Entity*> allCollide = Collision::allCollide(m_hero, m_hero->getPosition());
            for (Entity* e : allCollide) {
                //type id name without the fist char
                std::string typeName = typeid(*e).name();
                typeName = typeName.substr(1, typeName.length() - 1);
                if(typeName == "Ennemy") {
                    //manque invulnerabilite tempo
                    //std::cout << "Ennemy" << std::endl;
                    m_hero->setHealth(m_hero->getHealth()-1);
                    
                }
                if(typeName == "Mouse") {
                    //std::cout << "mouse" << std::endl;            
                }
                //game over
                if(m_hero->getHealth()<=0) {
                    m_gameState=GameState::DEAD;
                }

            }

            std::vector<Entity*> allCollide2 = Collision::allCollide(m_mouse, m_mouse->getPosition());
            for (Entity* e : allCollide2) {
                std::string typeName = typeid(*e).name();
                typeName = typeName.substr(1, typeName.length() - 1);
                if(typeName == "Ennemy") {
                    count_kill++;
                    Ennemy * tmp=dynamic_cast<Ennemy*>(e);
                    auto it = std::find_if( m_ennemies.begin(), m_ennemies.end(),
                        [&]( Ennemy *f ) { return ( f==tmp ); } );

                    if (it!= m_ennemies.end()) {
                        m_ennemies.erase(it);
                    }

                    if (count_kill==50) {
                        (*m_map).cave=true;
                        m_map->loadMap("ressources/maps/map_lvl2.csv");
                    }
                    if (count_kill%50==0) {
                        m_hero->MAXHEALTH+=1;
                    }
                    if (count_kill%50==0) {
                        if (m_hero->getHealth()<m_hero->MAXHEALTH) {
                            m_hero->setHealth(m_hero->getHealth());
                        }
                    }
                }
                //augment health
                if(typeName == "Item" && m_hero->getHealth()<m_hero->getMaxHealth()) {
                    Hearth * tmp=dynamic_cast<Hearth*>(e);
                    auto it = std::find_if( m_items.begin(), m_items.end(),
                        [&]( Hearth *f ) { return ( f==tmp ); } );

                    if (it!= m_items.end()) {
                        m_items.erase(it);
                    }
                    m_hero->setHealth(m_hero->getHealth()+1);      
                }
            }

			
			handleEvent();
			update();
			render();

			m_frameTime = SDL_GetTicks() - m_frameStart;
			if (_frameDelay > m_frameTime) {
				SDL_Delay(_frameDelay - m_frameTime);
			}

            if(count%30==0){
                spawnEnnemy();
            }


		}
        while (m_gameState==GameState::DEAD) {
            m_frameStart=SDL_GetTicks();

            handleEvent();
			render();
        }
	}
}

void Game::handleEvent() {
    SDL_Event event;
    m_hero->modif_dir(Hero::sens::NONE);
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            std::cout << "Exit signal detected" << ::std::endl;
            m_gameState = GameState::EXIT;
        }
        if (event.type == SDL_MOUSEMOTION)
        {
            //get mouse position to put the mouse on the map
            m_mouse->update(Vector2<int>(event.motion.y/32,event.motion.x/32));

        }
        else if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            switch(event.key.keysym.sym) {
            case 'q':
                std::cout << "Exit signal detected" << ::std::endl;
                m_gameState = GameState::EXIT;
                break;
            case 'e':
                if (m_gameState==GameState::INIT) {
                    std::cout << "Lancement du jeu" << ::std::endl;
                    m_gameState = GameState::PLAY;
                }
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
    }
}

void Game::update() {
	++count;
	m_hero->update();
    for (unsigned int i=0;i<m_ennemies.size();i++){
        m_ennemies[i]->update(Vector2<int>(m_hero->getPosition()));
    }
    for (unsigned int i=0;i<m_items.size();i++){
        m_items[i]->update();
    }
}

void Game::render() {
    if (m_gameState==GameState::PLAY) {
        m_map->drawMap(m_hero->getCamera());
        m_hero->render();
        

        for(unsigned int i=0;i<m_ennemies.size();i++){
            m_ennemies[i]->render();
        }
        for(unsigned int i=0;i<m_items.size();i++){
            m_items[i]->render();
        }
        m_mouse->render();

        if (m_map->isCave()) {
            SDL_Rect Rect;

            Rect.x=0;
            Rect.y=0;
            Rect.w=JeuESIR::screenWidth;
            Rect.h=JeuESIR::screenHeight;

            SDL_RenderCopy(static_cast<SDL_Renderer*>(Renderer::getInstance()->getSdlRenderer()), m_map->getSombre(), &Rect, &Rect);
        }
    } else if (m_gameState==GameState::INIT) {
            SDL_Rect Rect;

            Rect.x=0;
            Rect.y=0;
            Rect.w=JeuESIR::screenWidth;
            Rect.h=JeuESIR::screenHeight;

            SDL_RenderCopy(static_cast<SDL_Renderer*>(Renderer::getInstance()->getSdlRenderer()), m_map->getTitle(), &Rect, &Rect);
    } else if (m_gameState==GameState::DEAD) {
        SDL_Rect Rect;

        Rect.x=0;
        Rect.y=0;
        Rect.w=JeuESIR::screenWidth;
        Rect.h=JeuESIR::screenHeight;

        SDL_RenderCopy(static_cast<SDL_Renderer*>(Renderer::getInstance()->getSdlRenderer()), m_map->getEnd(), &Rect, &Rect);
    }
    
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
    //load ennemies
    for(int i=0;i<10;i+=2){
        m_ennemies.push_back(new Ennemy(m_map, "ressources/player/ennemy.png", Vector2<int>(i, 0), "SuperEnnemy"));
    }

    m_hero=new Hero(m_map, "ressources/player/fromage.png", Vector2<int>(10, 16), "Fromage");
    m_mouse=new Mouse(m_map, "ressources/player/fireball.png", Vector2<int>(10, 0), "SuperMouse");
}

/*
void Game::loadGameOver() {
    delete m_map;
    for (std::set<Entity*>::iterator it = Entity::m_entity.begin(); it != Entity::m_entity.end(); ++it)
    {
        (*it)->setStatus(Entity::Status::DESTROY);
    }
	m_map=new Map("ressources/maps/game_over.csv");
	
}*/

//remove the ennemy from the vector
void Game::removeEnnemy(Ennemy* ennemy){
    std::cout << "remove ennemy" << std::endl;
    static Ennemy* tmp;
    for(unsigned int i=0;i<m_ennemies.size();i++){
        tmp=m_ennemies[i];
        if(tmp==ennemy){
            m_ennemies.erase(m_ennemies.begin()+i);
            delete tmp;
        }
    }
}



void Game::spawnEnnemy() {
	//get random position in the screen but at more than 5 tiles m_hero
	int y = rand() % (JeuESIR::maxScreenCol-10) + 8;
    int x = rand() % (JeuESIR::maxScreenRow-10) + 8;

    //random between true and false
    bool target = rand() % 2;
    if(target){
        m_ennemies.push_back(new Ennemy(m_map, "ressources/player/ennemy.png", Vector2<int>(x, y), "SuperEnnemy", target));
    }
    else {
        m_ennemies.push_back(new Ennemy(m_map, "ressources/player/dumb.png", Vector2<int>(x, y), "DumbEnnemy",target));
    }
}


