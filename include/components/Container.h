#ifndef CONTAINER_H 
#define CONTAINER_H

#include <vector>
#include <Item.h>

class Container {
private:
    std::vector<Item> m_inventory;

public:
    Container();

    void addItem(Item item);
    Item getItem(int position);
};

#endif