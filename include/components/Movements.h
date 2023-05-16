#ifndef _Movements_H
#define _Movements_H

#include <Vector2.h>
#include <Collider.h>
#include <vector>
#include <constantes.h>
#include <Entity.h>

class Movements {
private:
    unsigned int const SCREEN_WIDTH;
    unsigned int const SCREEN_HEIGHT;
    float m_speed;
    Vector2<int> & m_position;
    Collider & m_collider;
public:
    Movements(Vector2<int>& position, Collider& collider,float speed=1);

    Vector2<int> getPosition() const;
    void setPosition(Vector2<int> position);

    //gestion des collisions
    void move(Vector2<int> direction);

    virtual void update()=0;

    virtual void walkOnObject()=0;
};

#endif
