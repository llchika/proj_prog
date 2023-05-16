#include <Title.h>
#include <Renderer.h>
#include <TextureManager.h>
#include <constantes.h>

Title::Title() : m_state(etat::WAIT), m_frameStart(SDL_GetTicks()) {}

void Title::run() {
    SDL_Texture* ecran_titre=TextureManager::loadTexture("ressources/ecran_titre.png");
	SDL_Rect m_srcRect, m_destRect;
	
	m_srcRect.x=m_srcRect.y=0;
	m_srcRect.w=m_destRect.w=JeuESIR::screenWidth;
	m_srcRect.h=m_destRect.h=JeuESIR::screenHeight;
	m_destRect.x=JeuESIR::screenWidth;
	m_destRect.y=JeuESIR::screenHeight;
	while (m_state==etat::WAIT) {
		TextureManager::draw(ecran_titre, m_srcRect, m_destRect);
		Renderer::getInstance()->flush();

		m_frameTime=SDL_GetTicks()-m_frameStart;
			if (_frameDelay>m_frameTime) {
				SDL_Delay(_frameDelay-m_frameTime);
		}
	}

    Renderer::getInstance()->flush();
}