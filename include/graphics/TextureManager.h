#ifndef _TextureManager_H
#define _TextureManager_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Renderer.h>

class TextureManager
{

public :
	/// <summary>
	/// Cr�� et retourne la texture charg�e � partir d'un fichier.
	/// </summary>
	/// <param name="filename">nom du fichier</param>
	/// <returns>Texture</returns>
	static SDL_Texture* loadTexture(const char* filename);
	/// <summary>
	/// Dessine la texture sur la fen�tre au niveau du rectangle.
	/// </summary>
	/// <param name="texture">Texture � dessiner</param>
	/// <param name="src">position du rectangle</param>
	/// <param name="dest">position du rectangle</param>
	static void draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};

#endif
