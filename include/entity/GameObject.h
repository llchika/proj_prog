#ifndef _GameObject_H
#define _GameObject_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <Vector2.h>

class Map;

class GameObject
{
private : 
	
	Vector2<int> m_position;			//position des cases 
	SDL_Texture* m_objTexture;			//Texture de l'objet
	SDL_Rect m_srcRect, m_destRect;

	Map* m_map;

public :
	/// <summary>
	/// Constructeur de GameObject. Permet de situer l'objet dans la carte et lui attribuer une texture.
	/// </summary>
	/// <param name="map">Carte</param>
	/// <param name="textureSheet">Texture</param>
	/// <param name="position">Position</param>
	GameObject(Map * map, const char* textureSheet, const Vector2<int>& position);
	virtual ~GameObject();

	/// <summary>
	/// Getter sur la position de l'objet par rapport � la carte.
	/// </summary>
	/// <returns>Position x et y</returns>
	const Vector2<int>& getPosition();
	/// <summary>
	/// Setter sur la position de l'objet
	/// </summary>
	/// <param name="position">La nouvelle position de l'objet</param>
	void setPosition(const Vector2<int>& position);

	/// <summary>
	/// Mise � jour des caract�ristiques de l'objet.
	/// </summary>
	void update();
	/// <summary>
	/// Mise � jour du rendu de l'objet.
	/// </summary>
	void render();

	/// <summary>
	/// Permet de d�terminer si la nouvelle position de l'objet est possible. 
	/// Premier pas dans la gestion des collisions.
	/// </summary>
	/// <param name="newPosition">Nouvelle position de l'objet</param>
	/// <returns>Bool�en : true si la case en param�tre d'entr�e est libre d'acc�s</returns>
	bool isValidCell(const Vector2<int>& newPosition);

	/// <summary>
	/// Translation de l'objet courrant.
	/// </summary>
	/// <param name="v">vecteur du d�placement de l'objet courant</param>
	void translate(Vector2<int> const& v);
	 
};

#endif
