#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "Entity.h"

RenderWindow::RenderWindow(const char* p_title, int x, int y, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	m_AnimationSrc.x = 0;
	m_AnimationSrc.y = 0;
	m_MaxTime = 0.035;
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::Render(Entity& p_entity, float p_Angle, const SDL_RendererFlip p_Flip, SDL_Rect& p_Dst)
{
	m_Src.x = 0;
	m_Src.y = 0;
	m_Src.w = p_entity.getCurrentFrame().w;
	m_Src.h = p_entity.getCurrentFrame().h;

	m_Dst.x = p_entity.GetPos().x - m_Src.w / 2 * p_entity.GetScale().x;
	m_Dst.y = p_entity.GetPos().y - m_Src.h / 2 * p_entity.GetScale().y;
	m_Dst.w = m_Src.w * p_entity.GetScale().x;
	m_Dst.h = m_Src.h * p_entity.GetScale().y;

	p_Dst = m_Dst;

	SDL_RenderCopyEx(renderer, p_entity.getTex(), &m_Src, &m_Dst, p_Angle, NULL, p_Flip);
}

void RenderWindow::RenderAnimate(Entity& p_entity, float p_Angle, const SDL_RendererFlip p_Flip, SDL_Rect& p_Dst)
{
	m_AnimationSrc.w = p_entity.getCurrentFrame().w;
	m_AnimationSrc.h = p_entity.getCurrentFrame().h;

	if (!m_AnimationTimer.IsStarted())
		m_AnimationTimer.Start();

	if (m_AnimationTimer.GetTicks() * 0.001 > m_MaxTime)
	{
		m_AnimationSrc.x += 32;

		if (m_AnimationSrc.x >= p_entity.getCurrentFrame().w)
			m_AnimationSrc.x = 0;

		m_AnimationTimer.Stop();
	}

	m_AnimationSrc.w = 32;

	m_Dst.x = p_entity.GetPos().x - m_AnimationSrc.w / 2 * p_entity.GetScale().x;
	m_Dst.y = p_entity.GetPos().y - m_AnimationSrc.h / 2 * p_entity.GetScale().y;
	m_Dst.w = m_AnimationSrc.w * p_entity.GetScale().x;
	m_Dst.h = m_AnimationSrc.h * p_entity.GetScale().y;

	p_Dst = m_Dst;

	SDL_RenderCopyEx(renderer, p_entity.getTex(), &m_AnimationSrc, &m_Dst, p_Angle, NULL, p_Flip);
}

void RenderWindow::RenderText(Vector2f p_pos, std::string p_text, TTF_Font* font, SDL_Color textColor)
{
	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, p_text.c_str(), textColor);
	SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	m_Src.x = 0;
	m_Src.y = 0;
	m_Src.w = surfaceMessage->w;
	m_Src.h = surfaceMessage->h;

	m_Dst.x = p_pos.x - m_Src.w / 2;
	m_Dst.y = p_pos.y - m_Src.h / 2;
	m_Dst.w = m_Src.w;
	m_Dst.h = m_Src.h;

	SDL_RenderCopy(renderer, message, &m_Src, &m_Dst);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(message);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

SDL_Renderer* RenderWindow::GetRenderer()
{
	return renderer;
}