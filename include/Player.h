#pragma once
#include "RenderWindow.h"
#include "Entity.h"
#include "Timer.h"


class Player : public Entity
{
public:
	Player() = default;
	Player(Vector2f p_pos, Vector2f p_scale, SDL_Texture* p_tex);
	void Update();
	void HandleEvent(SDL_Event event);
	void Render(RenderWindow& window);

private:
	float m_Speed;
	float m_Gravity;
};
