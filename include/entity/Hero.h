#ifndef _Hero_H
#define _Hero_H

#include <string>
#include <Entity.h>

class Hero : public Entity {
public:
    enum class sens {UP, DOWN, RIGHT, LEFT};

private:
    Vector2<int> m_direction;
    int m_speed;

public:
    /// <summary>
    /// Constructeur de Hero
    /// </summary>
    /// <param name="map">Carte</param>
    /// <param name="textureSheet">Texture du h�ro</param>
    /// <param name="position">Position initiale du h�ro</param>
    /// <param name="name">Nom du h�ro</param>
    Hero(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name);
    virtual ~Hero();

    /// <summary>
    /// Fonction permettant de mettre � jour les caract�ristiques du h�ro.
    /// </summary>
    void update();

    void modif_dir(sens direction);
};

#endif