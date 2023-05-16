#include <Mouse.h>
#include <constantes.h>
#include <Collision.h>
#include <iostream>
#include <string>
Mouse::Mouse(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name)
: Entity(map, textureSheet, position, name) {
    initPersonnge();
}

Mouse::~Mouse() {}

void Mouse::update(Vector2<int> mousePos){
    setPosition(mousePos);

    std::vector<Entity*> allCollide = Collision::allCollide(this, getPosition());
    //echo type of allCollide
    for (Entity* entity : allCollide) {
        //type id name without the fist char
        std::string typeName = typeid(*entity).name();
        typeName = typeName.substr(1, typeName.length() - 1);

        if(typeName == "Ennemy")
        {
            std::cout << "Ennemy" << std::endl;

            //je vois pas comment le supprimer sans avoir une liste static dans game (sinon ca crash)

        }



    }

    GameObject::update();
}
