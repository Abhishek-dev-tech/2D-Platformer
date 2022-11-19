#include "AssertManager.h"

AssertManager::AssertManager()
{
}

AssertManager& AssertManager::GetInstance()
{
	static AssertManager* instance = new AssertManager;

	return *instance;
}

void AssertManager::LoadTextures(RenderWindow& window)
{
	m_PlayerIdleTexture = window.loadTexture("res/gfx/Player_Idle.png");
	m_PlayerRunTexture = window.loadTexture("res/gfx/Player_Run.png");
	m_PlayerJumpTexture = window.loadTexture("res/gfx/Player_Jump.png");
	m_PlayerFallTexture = window.loadTexture("res/gfx/Player_Fall.png");

	m_PlatformTexture = window.loadTexture("res/gfx/Platform.png");

	SetEntity();
}

void AssertManager::SetEntity()
{
	m_Player = Player(Vector2f(100, 100), Vector2f(1.5, 1.5), m_PlayerIdleTexture);
	
	for (int i = 0; i < 5; i++)
	{
		m_Platform[i] = Entity(Vector2f((48 * (i + 1)) * 2, 475), Vector2f(2, 2), m_PlatformTexture);

	}
		
}

void AssertManager::Update()
{
	m_Player.Update();

	for (int i = 0; i < 5; i++)
		m_Platform[i].Update();
}

void AssertManager::Render(RenderWindow& window)
{
	if (!m_Player.IsPlayerJumped() && !m_Player.IsPlayerJumped() && m_Player.IsPlayerGrounded())
		window.RenderAnimate(m_Player, 0, m_Player.GetRendererFlip());
	else if(!m_Player.IsPlayerGrounded())
		window.Render(m_Player, 0, m_Player.GetRendererFlip());

	for (int i = 0; i < 5; i++)
		window.Render(m_Platform[i], 0, SDL_FLIP_NONE);
}
