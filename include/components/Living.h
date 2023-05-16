#ifndef _Living_H
#define _Living_H


class Living {
private:
    int const MAXHEALTH;
    int m_health;
    //Entity lifeBar;

public:
    Living(int maxHealth);
    int getHealth() const;
    void setHealth(int health);
};

#endif