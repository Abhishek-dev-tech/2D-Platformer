#include "AssertManager.h"

AssertManager::AssertManager()
{
}

AssertManager& AssertManager::GetInstance()
{
	static AssertManager* instance = new AssertManager;

	return *instance;
}

void AssertManager::LoadTextures(RenderWindow window)
{
	//playerShip = window.loadTexture("res/GFX/PlayerShip.png");

	SetEntity();
}

void AssertManager::SetEntity()
{
	//m_PlayerShip = Player(Vector2f(360, 650), playerShip, Vector2f(2.25, 2.25));
}

void AssertManager::Update()
{

}

void AssertManager::Render(RenderWindow window)
{

}
