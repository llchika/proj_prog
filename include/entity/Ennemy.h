#ifndef _Ennemy_H
#define _EnnemyH

#include <string>
#include <Entity.h>

class Ennemy : public Entity {
public:

private:
    Vector2<int> m_target;
    int m_speed;

public:

    Ennemy(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name, Vector2 target);
    virtual ~Ennemy();

    void update();

};

#endif