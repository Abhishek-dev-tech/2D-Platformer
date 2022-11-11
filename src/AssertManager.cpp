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
	m_PlayerTexture = window.loadTexture("res/gfx/Player_Idle.png");

	SetEntity();
}

void AssertManager::SetEntity()
{
	m_Player = Player(Vector2f(100, 100), Vector2f(1.5, 1.5), m_PlayerTexture);
}

void AssertManager::Update()
{
	m_Player.Update();
}

void AssertManager::Render(RenderWindow& window)
{
	window.RenderAnimate(m_Player, 0);
}
