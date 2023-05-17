#ifndef _Entity_H
#define _Entity_H

#include <set>
#include <string>
#include <GameObject.h>

/**
*  classe de base pour toutes les entités du jeu.
*/

class Entity : public GameObject {
public:

	/// <summary>
	/// Id de l'entity.
	/// </summary>
	class Id {
	private:
		uint32_t m_idEntity;
		static uint32_t m_count;
	public:
		Id();
		bool operator==(Id const& id) const;
	};
	static std::set<Entity*> m_entity;
	enum class Status { RUNNING, DESTROY };
	private :
	//Status 
		
	Status m_status;

	//Liste de toutes les entités du jeu
	
	Id m_id;

	//Caractéristiques du l'entité.
	std::string m_name;

	Vector2<int> m_size;


public :
	/// <summary>
	/// Constructeur
	/// </summary>
	/// <param name="map">Carte du jeu</param>
	/// <param name="textureSheet">Texture de l'entité</param>
	/// <param name="position">Position de l'entité</param>
	/// <param name="name">Nom de l'entité</param>
	Entity(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name);
	virtual ~Entity();

	/// <summary>
	/// Getter
	/// </summary>
	/// <returns></returns>
	Status getStatus();
	/// <summary>
	/// Setter
	/// </summary>
	/// <param name="a_stat"></param>
	void setStatus(Status a_stat);

	/// <summary>
	/// Fonction � compl�ter permettant d'initaliser toutes les caract�ristiques de l'entit�.
	/// </summary>
	void initPersonnge();

	const Vector2<int>& getSize();

};


#endif