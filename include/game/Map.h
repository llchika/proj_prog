#ifndef _Map_H
#define _Map_H

#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <cassert>

#include <CSVReader.h>
#include <TextureManager.h>
#include <Entity.h>

#include <Hero.h>

class Map {
private :

	//Représentation de la carte sous forme de case.
	std::vector< std::vector< int > > m_map;
	
	//Un exemple de possiblité pour stocker dans la carte tous les objets cases par cases.
	std::vector< std::vector <std::set< GameObject* >>> m_data;

	//Taille de la carte
	unsigned int m_sizeX;
	unsigned int m_sizeY;

	bool cave;

	//Texture des cases
	SDL_Rect m_srcRect, m_destRect;

	SDL_Texture* m_sombre;

	SDL_Texture* m_black;
	SDL_Texture* m_floor;
	SDL_Texture* m_dirt;
	SDL_Texture* m_rock;
	SDL_Texture* m_tainted_floor;
	SDL_Texture* m_tainted_dirt;
	SDL_Texture* m_tainted_rock;
	SDL_Texture* m_wall;
	SDL_Texture* m_monster_wall;
	SDL_Texture* m_hole_wall;
	SDL_Texture* m_right_of_wall;
	SDL_Texture* m_left_of_wall;
	SDL_Texture* m_top_of_wall;


public :

	SDL_Texture* getSombre() {
		return m_sombre;
	}

	/// <summary>
	/// Constructeur de la carte du jeu.
	/// </summary>
	/// <param name="filename">Nom du fichier csv contenant la carte du jeu.</param>
	Map(std::string filename = "ressources/maps/map_lvl1.csv");
	virtual ~Map();

	/// <summary>
	/// Getter sur la taille de la carte.
	/// </summary>
	/// <returns>Taille</returns>
	unsigned int getSizeX() {return m_sizeX;}
	/// <summary>
	/// Getter sur la taille de la carte.
	/// </summary>
	/// <returns>Taille</returns>
	unsigned int getSizeY() {return m_sizeY;}
	/// <summary>
	/// Retroune le type de texture d'une case.
	/// </summary>
	/// <param name="x">Indice de la carte</param>
	/// <param name="y">Indice de la carte</param>
	/// <returns>Le type de la case</returns>
	int type(int x, int y) const;
	
	/// <summary>
	/// Chargement de la carte en fonction du fichier csv.
	/// </summary>
	/// <param name="filename">Nom du fichier csv contenant la carte du jeu.</param>
	void loadMap(std::string filename="ressources/maps/map_lvl1.csv");
	/// <summary>
	/// Utilisation des textures en fonction du num�ro de la case.
	/// </summary>
	void drawMap(Vector2<int> pos_camera);

	/// <summary>
	/// Ajout d'un game object dans la donn�e m_data
	/// </summary>
	/// <param name="obj">Objet � ins�rer</param>
	void addGameObject(GameObject* obj);
	/// <summary>
	/// Suppression d'un game objet dans la donn�e m_data
	/// </summary>
	/// <param name="obj">Objet � supprimer</param>
	void removeGameObject(GameObject* obj);

	bool isCave() {return cave;}
};

#endif
