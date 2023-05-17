#ifndef _constantes_H
#define _constantes_H

namespace JeuESIR {
	//! Constantes d�finissant la taille de la tile.
	static const int originalTileSize = 32;			//16 x 16 Tiles
	static const int tileSize = originalTileSize * 1;	//1 -> scale   // 32 x 1 = 32 Tile (32 x 32)

	//! Constantes définissant la taille du screen en fonction des tiles.
	static const int maxScreenCol=33;
	static const int maxScreenRow=21;
	static const int demiCol=16;
	static const int demiRow=10;
	static const int screenWidth=tileSize*maxScreenCol;	  // 1056
	static const int screenHeight=tileSize*maxScreenRow;  // 672
}
#endif