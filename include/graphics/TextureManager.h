#ifndef _TextureManager_H
#define _TextureManager_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Renderer.h>

class TextureManager {

public :
	/**
	 * Retourne une texture chargée à partir d'un fichier.
	 * @param filename: Path du fichier à charger
	*/
	static SDL_Texture* loadTexture(const char* filename);
	
	/**
	 * Dessine une texture
	 * @param texture: Texture à dessiner
	 * @param src: Rectangle source
	 * @param dest: Rectangle destination
	*/
	static void draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};

#endif
