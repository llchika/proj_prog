#ifndef _Ennemy_H
#define _EnnemyH

#include <string>
#include <Entity.h>

class Ennemy : public Entity {
public:

private:
    int m_speed;
    int const MAXHEALTH;
    int m_health;

public:

    Ennemy(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name);
    virtual ~Ennemy();

    void update(Vector2<int> const& target);
    
    void setHealth(int health) {
        m_health = health;
    }

    int getHealth() const {
        return m_health;
    }
    

};

#endif