#include "Player.h"
#include "AssertManager.h"

Player::Player(Vector2f p_pos, Vector2f p_scale, SDL_Texture* p_tex)
	:Entity(p_pos, p_scale, p_tex)
{
	m_Speed = 1.5;
	m_Gravity = 4;

	m_Jumped = false;
	m_Falling = false;

	m_Flip = SDL_FLIP_NONE;

	ChangeAnimationState(Idle);
}

void Player::Update()
{
	Entity::Update();

	ChangeTextureBasedOnAnimation();

	SetPos(Vector2f(GetPos().x, GetPos().y + m_Gravity));

	m_Gravity = m_Gravity >= 4 ? 4 : m_Gravity + 0.1;

	if (m_Gravity >= 0 && !m_Grounded)
	{
		ChangeAnimationState(Fall);
		m_Jumped = false;
		m_Falling = true;
	}
	else
		m_Falling = false;

	std::cout << "jump: " << m_Jumped << "  Fall: " << m_Falling << "  Grounded: " << m_Grounded << std::endl;
}

void Player::HandleEvent(SDL_Event event)
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	if (currentKeyStates[SDL_SCANCODE_A])
		Movement(-1);
	else if (currentKeyStates[SDL_SCANCODE_D])
		Movement(1);
	else if (!m_Jumped && !m_Falling && m_Grounded)
		ChangeAnimationState(Idle);
	
	if (currentKeyStates[SDL_SCANCODE_SPACE] && !m_Jumped)
		PlayerJump();
}

void Player::Movement(int p_Dir)
{
	SetPos(Vector2f(GetPos().x + m_Speed * p_Dir, GetPos().y));
	
	if(m_Grounded)
		ChangeAnimationState(Run);

	if (p_Dir == 1)
		m_Flip = SDL_FLIP_NONE;
	else
		m_Flip = SDL_FLIP_HORIZONTAL;
}

void Player::PlayerJump()
{
	m_Gravity = -4;
	ChangeAnimationState(Jump);
	m_Jumped = true;
	m_Falling = false;
}

void Player::ChangeTextureBasedOnAnimation()
{
	switch (m_AnimationState)
	{
	case Idle:
		SetTexture(AssertManager::GetInstance().m_PlayerIdleTexture);
		UpdateTexture();
		break;

	case Run:
		SetTexture(AssertManager::GetInstance().m_PlayerRunTexture);
		UpdateTexture();
		break;

	case Jump:
		SetTexture(AssertManager::GetInstance().m_PlayerJumpTexture);
		UpdateTexture();
		break;

	case DoubleJump:
		SetTexture(AssertManager::GetInstance().m_PlayerFallTexture);
		UpdateTexture();
		break;

	case Fall:
		SetTexture(AssertManager::GetInstance().m_PlayerFallTexture);
		UpdateTexture();
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

void Player::SetPlayerGrounded(bool p_Grounded)
{
	m_Grounded = p_Grounded;
}

SDL_RendererFlip Player::GetRendererFlip()
{
	return m_Flip;
}

bool Player::IsPlayerJumped()
{
	return m_Jumped;
}

bool Player::IsPlayerFalling()
{
	return m_Falling;
}

bool Player::IsPlayerGrounded()
{
	return m_Grounded;
}

void Player::Render(RenderWindow& window)
{

}


