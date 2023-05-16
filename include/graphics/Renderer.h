#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <algorithm>
#include <map>
#include <vector>
#include <memory>
#include <iostream>
#include <Rectangle.h>
#include <Vector2.h>


/**
 * Classe pour le rendu 2D
*/
class Renderer {
public:
    /** 
     * Classe pour la gestion des couleurs (RGBA)
    */
    class Color {
	union {
		Uint32 m_colorValue;
		Uint8  m_color[4];
	};

	public:
		Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255) {
			m_color[0]=red;
			m_color[1]=green;
			m_color[2]=blue;
			m_color[3]=alpha;
		}
		
		Uint8 & operator[](unsigned int index) {
			return m_color[index];
		}

		Sint8 operator[](unsigned int index) const {
			return m_color[index];
		}
		
		bool operator<(const Color & color) const {
			return m_colorValue < color.m_colorValue;
		}
		
		bool operator==(const Color & color) const {
			return m_colorValue == color.m_colorValue;
		}
	};

protected:
    /**
     * Représentation interne des string 
    */
    struct String {
		Vector2<float> position;
		Color color;
		std::string string;
	};

    /**
     * Représentation interne des cercles 
    */
    struct Circle {
		Vector2<float> center;
		float radius;
		Color color;
	};

    /**
     * Représentation interne des rectangles 
    */
	struct Rect {
		Vector2<float> upperLeftPosition;
		Vector2<float> lowerRightPosition;
		Color color;
	};

    static std::unique_ptr<Renderer> m_singleton;

    /**
     * Hauteur & largeur de la fenêtre
    */
	unsigned int m_width, m_height;

    /**
     * The rendering window (provided by SDL)
    */
	SDL_Window *window;

    /**
     * The internal renderer (provided by SDL)
    */
	SDL_Renderer *renderer;
	
    /**
     * Les pixels à afficher
    */
	::std::vector< ::std::pair<Color, SDL_Point> > m_pixels;

    /**
     * Les string à afficher
    */
	::std::vector<String> m_strings;	

    /**
     * Cercles à afficher
    */
	::std::vector<Circle> m_circles;

	std::vector<Rectangle> m_rectangles;
	
    /**
     * Constructeur de Renderer
     * @param width: Largeur de la fenêtre
     * @param height: Hauteur de la fenêtre
    */
	Renderer(unsigned int width, unsigned int height);

	/**
     * Dessine un pixel
    */
	void flushPixels();
	
	/**
     * Dessine un string
    */
	void flushStrings();
	
	/**
     * Dessine un cercle
    */
	void flushCircles();

public:
    /**
     * Destructeur de Renderer
    */
    ~Renderer();

    /**
     * Récupère la SDL Renderer
    */
    SDL_Renderer * getSdlRenderer() const {return renderer;}

    /**
     * Recupère la largeur
    */
    unsigned int width() const {return m_width;}

    /**
     * Recupère la hauteur
    */
    unsigned int height() const {return m_height;}


    /**
     * Dessiner un pixel
     * @param coordinates: Coordonnées du pixel
     * @param color: Couleur du pixel
    */
    void drawPixel(Vector2<float> const & coordinates, const Color & color);

    /**
     * Dessiner un cercle
     * @param center: Centre du cercle
     * @param radisu: Rayon du cercle
     * @param color: Couleur du cercle
    */
    void drawCircle(Vector2<float> const & center, float radius, const Color & color);

    /**
     * Dessiner un string
     * @param position: Coordonnées du string
     * @param str: Contenu du string
     * @param color: Couleur du string
    */
    void drawString(Vector2<float> const & position, const ::std::string & str, const Color & color = Color(255, 255, 255, 255));

    /**
     * Dessiner une map
    */
	void drawMap();

    /**
     * Affiche tout sur l'écran
    */
    void flush();

    /**
     * Initialise le singleton
     * @param width: Largeur de la fenêtre
     * @param height: Hauteur de la fenêtre
    */
	static void initialize(unsigned int width, unsigned int height);
	
	/**
     * Finalize le renderer
    */
	static void finalize();

	/**
     * Récupère l'instance du renderer
    */
	static Renderer * getInstance() { return m_singleton.get(); }




};

#endif