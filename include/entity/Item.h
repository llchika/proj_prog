#ifndef ITEM_H
#define ITEM_H

class Item {
public:
    enum class objet {xp, mana};

    objet m_objet;
    int m_value;

    Item(objet objet, int value) : m_value(value), m_objet(objet) {}
};

#endif