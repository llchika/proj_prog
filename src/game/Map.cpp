#include <Map.h>

#include <constantes.h>

Map::Map(std::string filename) : cave(false) {
	loadMap(filename);

	m_sombre=TextureManager::loadTexture("ressources/sombre.png");
	m_titre=TextureManager::loadTexture("ressources/titre.png");
	m_end=TextureManager::loadTexture("ressources/adieu.png");

	m_floor=TextureManager::loadTexture("ressources/tiles/donjon/tile_0048.png");
	m_dirt=TextureManager::loadTexture("ressources/tiles/donjon/tile_0049.png");
	m_rock=TextureManager::loadTexture("ressources/tiles/donjon/tile_0042.png");
	m_tainted_floor=TextureManager::loadTexture("ressources/tiles/donjon/tile_0000.png");
	m_tainted_dirt=TextureManager::loadTexture("ressources/tiles/donjon/tile_0012.png");
	m_tainted_rock=TextureManager::loadTexture("ressources/tiles/donjon/tile_0024.png");
	m_wall=TextureManager::loadTexture("ressources/tiles/donjon/tile_0040.png");
	m_monster_wall=TextureManager::loadTexture("ressources/tiles/donjon/tile_0019.png");
	m_hole_wall=TextureManager::loadTexture("ressources/tiles/donjon/tile_0007.png");
	m_right_of_wall=TextureManager::loadTexture("ressources/tiles/donjon/tile_0015.png");
	m_left_of_wall=TextureManager::loadTexture("ressources/tiles/donjon/tile_0013.png");
	m_top_of_wall=TextureManager::loadTexture("ressources/tiles/donjon/tile_0002.png");

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

void Map::drawMap(Vector2<int> pos_camera) {
	int type = -1;
	for (unsigned int row=0; row<JeuESIR::maxScreenRow; ++row) {
		for (unsigned int column=0; column<JeuESIR::maxScreenCol; ++column) {
			
			type=m_map.at(pos_camera[0]+row).at(pos_camera[1]+column);

			m_destRect.x=column*JeuESIR::tileSize;
			m_destRect.y=row*JeuESIR::tileSize;
			
			switch (type) {
			case 0 :
				TextureManager::draw(m_black, m_srcRect, m_destRect);
				break;
			case 1 :
				TextureManager::draw(m_floor, m_srcRect, m_destRect);
				break;
			case 2 :
				TextureManager::draw(m_dirt, m_srcRect, m_destRect);
				break;
			case 3 :
				TextureManager::draw(m_rock, m_srcRect, m_destRect);
				break;
			case 4 :
				TextureManager::draw(m_tainted_floor, m_srcRect, m_destRect);
				break;
			case 5 :
				TextureManager::draw(m_tainted_dirt, m_srcRect, m_destRect);
				break;
			case 6 :
				TextureManager::draw(m_tainted_rock, m_srcRect, m_destRect);
				break;
			case 7 :	
				TextureManager::draw(m_wall, m_srcRect, m_destRect);
				break;
			case 8 :
				TextureManager::draw(m_monster_wall, m_srcRect, m_destRect);
				break;
			case 9 :
				TextureManager::draw(m_hole_wall, m_srcRect, m_destRect);
				break;
			case 10 :
				TextureManager::draw(m_right_of_wall, m_srcRect, m_destRect);
				break;
			case 11 :
				TextureManager::draw(m_left_of_wall, m_srcRect, m_destRect);
				break;
			case 12 :
				TextureManager::draw(m_top_of_wall, m_srcRect, m_destRect);
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
