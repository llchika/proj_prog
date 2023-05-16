#ifndef GAME_H
#define GAME_H

#include <Hero.h>
#include <Map.h>
#include <Renderer.h>
#include <TextureManager.h>
#include <Timer.h>

class Game {
private :
	// État du jeu
	enum class GameState {INIT, PLAY, EXIT};

	// Paramètres
	GameState m_gameState;	// État du jeu

	// Frame Rate
	const int _FPS=60;
	const int _frameDelay=1000/_FPS;
	unsigned long m_frameStart;
	int m_frameTime;

	int count;

	// Map 
	Map* m_map;

	// Joueur
	Hero* m_hero;
	Vector2<int> move;

public :
	/**
	 * Constructeur de la fenêtre de jeu
	 * @param width: Largeur de la fenêtre
	 * @param height: Hauteur de la fenêtre
	*/
	Game(unsigned int width, unsigned int height);
	virtual ~Game();

	/**
	 * Lancer le jeu
	*/
	void run();
	

private :

	/**
	 * Boucle du jeu, gère toutes les étapes du jeu
	*/
	void gameLoop();

	/**
	 * Gestion des événements 
	*/
	void handleEvent();

	/**
	 * Gestion des événements sur l'écran
	*/
	void startScreen();

	/**
	 * Mettre à jour tout les éléments du jeu
	*/
	void update();

	/**
	 * Mettre à jour le rendu
	*/
	void render();

	/**
	 * Quitter le jeu et terminer la sdl
	*/
	void endGame();

	/**
	 * Charger une map
	 * @param filename: Path de la map
	*/
	void loadMap(std::string filename = "ressources/maps/map_lvl1.csv");
};

#endif