#include "Game.h"
#include "RenderWindow.h"
#include "Collision.h"

Game::Game()
	:window("GAME v1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 525)
{
	isRunning = true;
}

void Game::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
		isRunning = true;
	else
		isRunning = false;
	TTF_Init();

	AssertManager::GetInstance().LoadTextures(window);
}

void Game::Update()
{
	AssertManager::GetInstance().Update();

	CheckCollision();
}


void Game::HandleEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

	AssertManager::GetInstance().m_Player.HandleEvent(event);
}

void Game::CheckCollision()
{
	for (int i = 0; i < 5; i++)
	{
		if (Collision::IsCollide(&AssertManager::GetInstance().m_Player.GetDst(), &AssertManager::GetInstance().m_Platform[i].GetDst()) && !AssertManager::GetInstance().m_Player.IsPlayerJumped())
		{
			AssertManager::GetInstance().m_Player.SetPos(Vector2f(AssertManager::GetInstance().m_Player.GetPos().x, AssertManager::GetInstance().m_Platform[i].GetPos().y - AssertManager::GetInstance().m_Platform[i].GetDst().h / 2 - AssertManager::GetInstance().m_Player.GetDst().h / 2));
			AssertManager::GetInstance().m_Player.SetPlayerGrounded(true);
		}
		else
		{
			AssertManager::GetInstance().m_Player.SetPlayerGrounded(false);
		}
	}
}

void Game::Render()
{
	window.clear();

	AssertManager::GetInstance().Render(window);

	window.display();
}


void Game::Clean()
{
	window.cleanUp();
	TTF_Quit();
	SDL_Quit();
}