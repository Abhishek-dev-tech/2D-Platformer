#pragma once
#include "RenderWindow.h"
#include "Entity.h"
#include "Timer.h"

enum AnimationState
{
	Idle,
	Run,
	Jump,
	DoubleJump,
	Fall
};

class Player : public Entity
{
public:
	Player() = default;
	Player(Vector2f p_pos, Vector2f p_scale, SDL_Texture* p_tex);
	void Update();
	void Movement(int p_Dir);
	void HandleEvent(SDL_Event event);
	void Render(RenderWindow& window);
	void ChangeAnimationState(AnimationState p_AnimationState);
	void ChangeTextureBasedOnAnimation();
	void SetPlayerGravity(float p_Gravity);
	void PlayerJump();
	void SetPlayerGrounded(bool p_Grounded);

	bool IsPlayerJumped();
	bool IsPlayerFalling();
	bool IsPlayerGrounded();
	SDL_RendererFlip GetRendererFlip();
	AnimationState GetAnimationState();


private:
	float m_Speed;
	float m_Gravity;

	bool m_Jumped;
	bool m_Falling;
	bool m_Grounded;

	AnimationState m_AnimationState;

	SDL_RendererFlip m_Flip;

	Timer m_JumpTimer;
};