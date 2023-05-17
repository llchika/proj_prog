#ifndef _Hero_H
#define _Hero_H

#include <string>
#include <Entity.h>
#include <constantes.h>

/**
* Personnage contrôlé par le joueur.
*/

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
    
    /**
     * Constructeur
    */
    Hero(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name);
    virtual ~Hero();

    /**
     * Met à jour le héros
    */
    virtual void update();

    /**
     * Calcule la nouvelle position du héros
    */
    void modif_dir(sens direction);

    /**
     * Récupère la position de la caméra
    */
    const Vector2<int> & getCamera() const {
        return m_pos_camera;
    }

    /**
     * Récupère la direction du héros
    */
    const Vector2<int> & getDirection() const {
        return m_direction;
    }

    /**
     * Récupère la vie du héros
    */
    int getHealth() const {
        return m_health;
    }

    /**
     * Change la vie du héros
    */
    void setHealth(int health) {
        m_health = health;
    }
};

#endif