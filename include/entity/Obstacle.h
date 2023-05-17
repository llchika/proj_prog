#ifndef _Obstacle_H
#define _Obstacle_H

#include <string>
#include <Entity.h>

/**
* Classe représentant un obstacle
*/

class Obstacle : public Entity {
public:
    Obstacle(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name);
    virtual ~Obstacle();

    /**
     * Met à jour l'obstacle
    */
    void update();
};

#endif