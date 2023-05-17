#ifndef _Hero_H
#define _Hero_H

#include <string>
#include <Entity.h>
#include <constantes.h>

class Hero : public Entity {
public:
    enum class sens {UP, DOWN, RIGHT, LEFT, NONE};

private:
    Vector2<int> m_direction;
    int m_speed;
	Vector2<int> m_pos_camera;
    int m_health;

public:
    int MAXHEALTH;
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
    virtual void update();

    /// <summary>
    /// Fonction permettant de deplacer le héros.
    void modif_dir(sens direction);

    /// <summary>
    /// Pour récupérer la position de la caméra.
    const Vector2<int> & getCamera() const {
        return m_pos_camera;
    }

    /// <summary>
    /// Pour récupérer la direction du héros.
    const Vector2<int> & getDirection() const {
        return m_direction;
    }

    /// <summary>
    /// Pour récupérer la santé du héros.
    int getHealth() const {
        return m_health;
    }

    /// <summary>
    /// Pour modifier la santé du héros.
    void setHealth(int health) {
        m_health = health;
    }
};

#endif