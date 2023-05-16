#ifndef _Mouse_H
#define _Mouse_H

#include <string>
#include <Entity.h>

class Mouse : public Entity {
public:
private:
public:
    /// <summary>
    /// Constructeur de Hero
    /// </summary>
    /// <param name="map">Carte</param>
    /// <param name="textureSheet">Texture du h�ro</param>
    /// <param name="position">Position initiale du h�ro</param>
    /// <param name="name">Nom du h�ro</param>
    Mouse(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name);
    virtual ~Mouse();

    /// <summary>
    /// Fonction permettant de mettre � jour les caract�ristiques du h�ro.
    /// </summary>
    void update(Vector2<int> mousePose);
};

#endif