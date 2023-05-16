#ifndef _Living_H
#define _Living_H
//j'ai fais des trucs pas fou, jpense abandonner cette classe pour gagner du tps
#include <Entity.h>
#include <Map.h>
class Living {
private:
    int const MAXHEALTH;
    int m_health;
    Entity lifeBarMax;
    Entity lifeBarCurrent;

public:
    Living(int maxHealth, Map* map, const Vector2<int>& positionHolder);
    int getHealth() const;
    void setHealth(int health);

    void update();
};

#endif