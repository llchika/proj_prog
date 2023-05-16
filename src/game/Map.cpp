#include <Map.h>

#include <constantes.h>

Map::Map(std::string filename) {
	loadMap(filename);

	m_floor=TextureManager::loadTexture("ressources/tiles/grassCenter.png");
	m_grass=TextureManager::loadTexture("ressources/tiles/grassGreenCenter.png");

	m_srcRect.x=m_srcRect.y=0;
	m_srcRect.w=m_destRect.w=JeuESIR::tileSize;
	m_srcRect.h=m_destRect.h=JeuESIR::tileSize;
	m_destRect.x=m_destRect.y=0;
}

Map::~Map() {
	//Delete texture
}

int Map::type(int x, int y) const {
	return m_map.at(x).at(y);
}

void Map::loadMap(std::string filename) {
	m_map=(new CSVReader(filename))->getData();
	m_sizeY=m_map.size();
	m_sizeX=m_map.front().size();

	m_data.resize(m_sizeY);
	for (unsigned int row=0; row<m_sizeY; ++row) {
		m_data[row].resize(m_sizeX);
	}
}

void Map::drawMap() {
	int type = -1;

	for (unsigned int row=0; row<m_sizeY; ++row) {
		for (unsigned int column=0; column<m_sizeX; ++column) {
			
			type = m_map.at(row).at(column);

			m_destRect.x=column*JeuESIR::tileSize;
			m_destRect.y=row*JeuESIR::tileSize;
			
			switch (type) {
			case 0 :
				TextureManager::draw(m_grass, m_srcRect, m_destRect);
				break;
			case 1 :
				TextureManager::draw(m_floor, m_srcRect, m_destRect);
				break;
			default:
				break;
			}
		}
	}
}

void Map::addGameObject(GameObject* obj) {
	m_data[obj->getPosition()[0]][obj->getPosition()[1]].insert(obj);
}

void Map::removeGameObject(GameObject* obj) {
	//A compl�ter
}
