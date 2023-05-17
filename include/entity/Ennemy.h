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
    float m_timer;
    bool m_target;

public:

    Ennemy(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name, bool m_target=true);
    virtual ~Ennemy();

    /// <summary>
    /// Fonction permettant de mettre à la position de l'ennemi et son affichage.
    void update(Vector2<int> const& target);
    
    /// <summary>
    /// Mise à jour de la santé de l'ennemi.
    void setHealth(int health) {
        m_health = health;
    }

    /// <summary>
    /// Récupération de la santé de l'ennemi.
    int getHealth() const {
        return m_health;
    }

    /// <summary>
    /// Mise à jour du timer de l'ennemi. (utilisé pour ses déplacements)
    void setTimer(float timer) {
        m_timer = timer;
    }

    /// <summary>
    /// Récupération du timer de l'ennemi.
    float getTimer() const {
        return m_timer;
    }
    

};

#endif