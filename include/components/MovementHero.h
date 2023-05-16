#ifndef _MovementHero_H
#define _MovementHero_H

#include "./Movements.h"

class MovementHero : public Movements{
private:
    Vector2<int> m_direction;
    SDL_Event m_event;
    Collider m_collider;
public:
    MovementHero(Vector2<int>& position, Collider & collider,float speed);

    virtual ~MovementHero();

    void update() override;

    
};

#endif