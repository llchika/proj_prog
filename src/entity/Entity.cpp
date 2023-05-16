#include <Entity.h>

#include <iostream>

uint32_t Entity::Id::m_count; 
std::set<Entity*> Entity::m_entity;

Entity::Entity(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name) :
	GameObject(map, textureSheet, position), m_status(Entity::Status::RUNNING), m_name(name) {
	m_entity.insert(this);
}

Entity::~Entity() {
}

Entity::Status Entity::getStatus() {
	return m_status;
}

void Entity::setStatus(Entity::Status a_stat) {
	m_status = a_stat;
}

void Entity::initPersonnge() {
}

Entity::Id::Id() : m_idEntity(m_count++) {
}

bool Entity::Id::operator==(Id const& id) const {
	if (m_idEntity == id.m_idEntity) return true;
	return false;
}
