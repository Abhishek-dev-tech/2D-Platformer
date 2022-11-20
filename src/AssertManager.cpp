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
	m_Top_Bottom_OutlinePlatformTexture = window.loadTexture("res/gfx/Top_Bottom_OutlinePlatform.png");

	SetEntity();
}

void AssertManager::SetEntity()
{
	m_Player = Player(Vector2f(100, 100), Vector2f(1.5, 1.5), m_PlayerIdleTexture);
	
	m_Platform = Entity(Vector2f(150, 475), Vector2f(2, 2), m_PlatformTexture);

	for (int i = 0; i < 9; i++)
	{
		m_Top_Bottom_OutlinePlatform[i] = Entity(Vector2f((48 * (i + 1)) * 2, 513), Vector2f(2, 2), m_Top_Bottom_OutlinePlatformTexture);
	}
}

void AssertManager::Update()
{
	m_Player.Update();
}

void AssertManager::Render(RenderWindow& window)
{
	if (m_Player.GetAnimationState() == Run || m_Player.GetAnimationState() == Idle)
		window.RenderAnimate(m_Player, 0, m_Player.GetRendererFlip(), m_Player.GetDst());
	else
		window.Render(m_Player, 0, m_Player.GetRendererFlip(), m_Player.GetDst());

	window.Render(m_Platform, 0, SDL_FLIP_NONE, m_Platform.GetDst());

	for (int i = 0; i < 9; i++)
	{
		window.Render(m_Top_Bottom_OutlinePlatform[i], 0, SDL_FLIP_NONE, m_Top_Bottom_OutlinePlatform[i].GetDst());
	}
}
