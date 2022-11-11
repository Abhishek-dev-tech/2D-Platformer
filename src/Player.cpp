#include "Player.h"

Player::Player(Vector2f p_pos, Vector2f p_scale, SDL_Texture* p_tex)
	:Entity(p_pos, p_scale, p_tex)
{
	m_Speed = 1.5;
	m_Gravity = 1;
}

void Player::Update()
{
	Entity::Update();

	//SetPos(Vector2f(GetPos().x, GetPos().y + m_Gravity));
}

void Player::HandleEvent(SDL_Event event)
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	if (currentKeyStates[SDL_SCANCODE_A])
		SetPos(Vector2f(GetPos().x - m_Speed, GetPos().y));

	else if (currentKeyStates[SDL_SCANCODE_D])
		SetPos(Vector2f(GetPos().x + m_Speed, GetPos().y));
}

void Player::Render(RenderWindow& window)
{

}


