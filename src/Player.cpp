#include "Player.h"
#include "AssertManager.h"

Player::Player(Vector2f p_pos, Vector2f p_scale, SDL_Texture* p_tex)
	:Entity(p_pos, p_scale, p_tex)
{
	m_Speed = 1.5;
	m_Gravity = 2;

	m_Flip = SDL_FLIP_NONE;

	ChangeAnimationState(Idle);
}

void Player::Update()
{
	Entity::Update();

	ChangeTextureBasedOnAnimation();

	SetPos(Vector2f(GetPos().x, GetPos().y + m_Gravity));
}

void Player::HandleEvent(SDL_Event event)
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	if (currentKeyStates[SDL_SCANCODE_A])
		Movement(-1);

	else if (currentKeyStates[SDL_SCANCODE_D])
		Movement(1);
	else
		ChangeAnimationState(Idle);

	if (currentKeyStates[SDL_SCANCODE_SPACE])
		PlayerJump();
}

void Player::Movement(int p_Dir)
{
	SetPos(Vector2f(GetPos().x + m_Speed * p_Dir, GetPos().y));
	
	ChangeAnimationState(Run);

	if (p_Dir == 1)
		m_Flip = SDL_FLIP_NONE;
	else
		m_Flip = SDL_FLIP_HORIZONTAL;
}

void Player::PlayerJump()
{
	m_Gravity = -4;
}

void Player::ChangeTextureBasedOnAnimation()
{
	switch (m_AnimationState)
	{
	case Idle:
		SetTexture(AssertManager::GetInstance().m_PlayerIdleTexture);
		break;

	case Run:
		SetTexture(AssertManager::GetInstance().m_PlayerRunTexture);
		break;

	case Jump:
		SetTexture(AssertManager::GetInstance().m_PlayerRunTexture);
		break;

	case DoubleJump:
		SetTexture(AssertManager::GetInstance().m_PlayerRunTexture);
		break;

	case Fall:
		SetTexture(AssertManager::GetInstance().m_PlayerRunTexture);
		break;

	default:
		break;
	}
}

void Player::ChangeAnimationState(AnimationState p_AnimationState)
{
	m_AnimationState = p_AnimationState;
}

void Player::SetPlayerGravity(float p_Gravity)
{
	m_Gravity = p_Gravity;
}

SDL_RendererFlip Player::GetRendererFlip()
{
	return m_Flip;
}

void Player::Render(RenderWindow& window)
{

}


