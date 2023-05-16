#include <TextureManager.h>

SDL_Texture* TextureManager::loadTexture(const char* filename) {
    SDL_Surface* tmpSurface=IMG_Load(filename);
    if (tmpSurface==nullptr) {
        std::cout << IMG_GetError() << std::endl;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(static_cast<SDL_Renderer*>(Renderer::getInstance()->getSdlRenderer()), tmpSurface);
    if (texture==nullptr)
        std::cout << " texture NULL" << std::endl;
    SDL_FreeSurface(tmpSurface);

    return texture;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(static_cast<SDL_Renderer*>(Renderer::getInstance()->getSdlRenderer()), texture, &src, &dest);
}
