#include <MovementHero.h>

MovementHero::MovementHero(Vector2<int>& position, Collider& collider, float speed) : Movements(position, collider, speed) {}

MovementHero::~MovementHero() {}

void MovementHero::update(){
    if (m_event.type == SDL_KEYDOWN){
        if (m_event.key.repeat == 0){
            switch (m_event.key.keysym.sym){
            case SDLK_UP:
                m_direction = Vector2<int>(0, -1);
                break;
            case SDLK_DOWN:
                m_direction = Vector2<int>(0, 1);
                break;
            case SDLK_LEFT:
                m_direction = Vector2<int>(-1, 0);
                break;
            case SDLK_RIGHT:
                m_direction = Vector2<int>(1, 0);
                break;
            }
        }
        //diagonal movement
        if (m_event.type == SDL_KEYDOWN && m_event.key.repeat == 0){
            switch (m_event.key.keysym.sym){
            case SDLK_UP:
                if (m_event.key.keysym.sym == SDLK_LEFT){
                    m_direction = Vector2<int>(-1, -1);
                }
                if (m_event.key.keysym.sym == SDLK_RIGHT){
                    m_direction = Vector2<int>(1, -1);
                }
                break;
            case SDLK_DOWN:
                if (m_event.key.keysym.sym == SDLK_LEFT){
                    m_direction = Vector2<int>(-1, 1);
                }
                if (m_event.key.keysym.sym == SDLK_RIGHT){
                    m_direction = Vector2<int>(1, 1);
                }
                break;
            }
        }
    }
    else {
        m_direction = Vector2<int>(0, 0);
    }
    move(m_direction);
}
