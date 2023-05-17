#ifndef _Obstacle_H
#define _Obstacle_H

#include <string>
#include <Entity.h>

class Obstacle : public Entity {
public:
private:
public:

    Obstacle(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name);
    virtual ~Obstacle();

    /// <summary>
    /// Fonction permettant de mettre � jour les caract�ristiques du h�ro.
    /// </summary>
    void update();
};

#endif