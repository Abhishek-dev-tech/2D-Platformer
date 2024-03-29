#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "Entity.h"
#include "Timer.h"


class RenderWindow
{
public:
	RenderWindow(const char* p_title, int x, int y, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void clear();
	void Render(Entity& p_entity, float p_Angle, const SDL_RendererFlip p_Flip, SDL_Rect& p_Dst);
	void RenderAnimate(Entity& p_entity, float p_Angle, const SDL_RendererFlip p_Flip, SDL_Rect& p_Dst);
	void display();

	SDL_Renderer* GetRenderer();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Rect m_AnimationSrc;
	SDL_Rect m_Src;
	SDL_Rect m_Dst;

	Timer m_AnimationTimer;

	float m_MaxTime;

};