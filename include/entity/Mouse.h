#ifndef _Mouse_H
#define _Mouse_H

#include <string>
#include <Entity.h>

class Mouse : public Entity {
public:
private:
public:
    /// <summary>
    /// Constructeur
    Mouse(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name);
    virtual ~Mouse();

    /// <summary>
    /// Fonction permettant de mettre à jour la position de la souris et son affichage.
    void update(Vector2<int> mousePose);
};

#endif