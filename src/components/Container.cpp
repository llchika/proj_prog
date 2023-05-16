#include <Container.h>

Container::Container()
: m_inventory(std::vector<Item>()) {}

void Container::addItem(Item item) {
    m_inventory.push_back(item);
}

Item Container::getItem(int position) {
    if (0<=position && position<m_inventory.size()) {
        Item tmp=m_inventory[position];
        std::vector<Item>::iterator it=m_inventory.begin();
        it+=position;
        m_inventory.erase(it);
        return tmp;
    }
}