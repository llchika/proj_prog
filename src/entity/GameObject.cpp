#include <GameObject.h>

#include <Map.h>
#include <constantes.h>


GameObject::GameObject(Map * map, const char* textureSheet, const Vector2<int>& position) {
	m_map = map;

	m_objTexture = TextureManager::loadTexture(textureSheet);
	
	m_position[0] = position[0];
	m_position[1] = position[1];

	std::cout << "m_position " << m_position[0] << ";" << m_position[1] << std::endl;

	m_srcRect.h = JeuESIR::tileSize;
	m_srcRect.w = JeuESIR::tileSize;
	m_srcRect.x = 0;
	m_srcRect.y = 0;

	m_destRect.h = m_srcRect.h;
	m_destRect.w = m_srcRect.w;
	m_destRect.x = m_position[0];
	m_destRect.y = m_position[1];

	//Ajout de l'objet dans la carte
	m_map->addGameObject(this);
}

GameObject::~GameObject() {
	//Suppression de l'objet dans la carte
	m_map->removeGameObject(this);
}

const Vector2<int>& GameObject::getPosition() {
	return m_position;
}

void GameObject::setPosition(const Vector2<int>& position) {
	m_map->removeGameObject(this);

	if (isValidCell(position)) {
		m_position[0] = position[0];
		m_position[1] = position[1];
	}

	m_map->addGameObject(this);
}

void GameObject::translate(Vector2<int> const& v) {
	setPosition(m_position + v);
}

bool GameObject::isValidCell(const Vector2<int>& newPosition) {
	//A compl�ter.
	return true;
}

void GameObject::update() {
	m_srcRect.h = JeuESIR::tileSize;
	m_srcRect.w = JeuESIR::tileSize;
	m_srcRect.x = 0;
	m_srcRect.y = 0;

	m_destRect.h = m_srcRect.h ;
	m_destRect.w = m_srcRect.w ;
	m_destRect.x = m_position[1] * JeuESIR::tileSize;
	m_destRect.y = m_position[0] * JeuESIR::tileSize;
}

void GameObject::render() {
	SDL_RenderCopy(Renderer::getInstance()->getSdlRenderer(), m_objTexture, &m_srcRect, &m_destRect);
}
