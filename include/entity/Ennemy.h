#ifndef _Ennemy_H
#define _EnnemyH

#include <string>
#include <Entity.h>

class Ennemy : public Entity {
public:

private:
    int m_speed;

public:

    Ennemy(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name);
    virtual ~Ennemy();

    void update(Vector2<int> const& target);

};

#endif