#ifndef _Game_H
#define _Game_H

#include <Hero.h>
#include <Map.h>
#include <Renderer.h>
#include <TextureManager.h>
#include <Timer.h>

class Game
{
private :

	//State of the game
	enum class GameState { PLAY, EXIT };

	//settings
	GameState m_gameState;	//State of the game

	//Frame Rate
	const int _FPS = 60;
	const int _frameDelay = 1000 / _FPS;
	unsigned long m_frameStart;
	int m_frameTime;

	int count;

	//Map 
	Map* m_map;

	//Player
	Hero* m_hero;
	Vector2<int> move;

public :
	/// <summary>
	/// Constructeur permattant d'initialiser la fen�tre du jeu.
	/// </summary>
	/// <param name="width">Taille de la fen�tre</param>
	/// <param name="height">Taille de la fen�tre</param>
	Game(unsigned int width, unsigned int height);
	virtual ~Game();

	/// <summary>
	/// Fonction permettant de lancer le jeu.
	/// </summary>
	void run();
	

private :

	/// <summary>
	/// Boucle principale du jeu, permet de g�rer toutes les �tapes d'un tour de jeu.
	/// </summary>
	void gameLoop();
	/// <summary>
	/// Gestion des �v�nements du jeu.
	/// </summary>
	void handleEvent();
	/// <summary>
	/// Fonction permettant de mettre � jour tous les �l�ments du jeu.
	/// </summary>
	void update();
	/// <summary>
	/// Fonction pour mettre � jour le renderer.
	/// </summary>
	void render();
	/// <summary>
	/// Fonction pour quitter le jeu et terminer SDL.
	/// </summary>
	void endGame();

	/// <summary>
	/// Fonction permettant de charger la carte du jeu � partir d'un fichier csv. 
	/// </summary>
	/// <param name="filename">Nom du fichier csv contenant la carte du jeu</param>
	void loadMap(std::string filename = "ressources/maps/map_lvl1.csv");

};

#endif
