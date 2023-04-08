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
	float playerX = AssertManager::GetInstance().m_Player.GetPos().x;
	float playerY = AssertManager::GetInstance().m_Player.GetPos().y;

	int playerW = AssertManager::GetInstance().m_Player.GetDst().w;
	int playerH = AssertManager::GetInstance().m_Player.GetDst().h;

	Vector2f playerPos = Vector2f(playerX, playerY);


	if (Collision::IsCollide(&AssertManager::GetInstance().m_Player.GetDst(),
		&AssertManager::GetInstance().m_Bottom_PlatformOutline.GetDst()) && !AssertManager::GetInstance().m_Player.IsPlayerJumped())
	{
		playerPos = Vector2f(playerX, AssertManager::GetInstance().m_Bottom_PlatformOutline.GetPos().y - AssertManager::GetInstance().m_Bottom_PlatformOutline.GetDst().h / 2 - playerH / 2 + 1);
		AssertManager::GetInstance().m_Player.SetPlayerGrounded(true);
	}
	else
	{
		AssertManager::GetInstance().m_Player.SetPlayerGrounded(false);
	}

	for (int i = 0; i < 2; i++)
	{
		if (Collision::IsCollide(&AssertManager::GetInstance().m_Player.GetDst(),
			&AssertManager::GetInstance().m_Platform[i].GetDst()))
		{
			if (playerX + playerW / 2 - 4 < AssertManager::GetInstance().m_Platform[i].GetPos().x - AssertManager::GetInstance().m_Platform[i].GetDst().w / 2)
				playerPos = Vector2f(AssertManager::GetInstance().m_Platform[i].GetPos().x - AssertManager::GetInstance().m_Platform[i].GetDst().w / 2 - playerW / 2 - 1, playerPos.y);

			else if (playerX - playerW / 2 + 4 > AssertManager::GetInstance().m_Platform[i].GetPos().x + AssertManager::GetInstance().m_Platform[i].GetDst().w / 2)
				playerPos = Vector2f(AssertManager::GetInstance().m_Platform[i].GetPos().x + AssertManager::GetInstance().m_Platform[i].GetDst().w / 2 + playerW / 2 + 1, playerPos.y);


			if (playerY + playerH / 2 - 10 < AssertManager::GetInstance().m_Platform[i].GetPos().y - AssertManager::GetInstance().m_Platform[i].GetDst().h / 2 && !AssertManager::GetInstance().m_Player.IsPlayerJumped())
			{
				playerPos = Vector2f(playerX, AssertManager::GetInstance().m_Platform[i].GetPos().y - AssertManager::GetInstance().m_Platform[i].GetDst().h / 2 - playerH / 2);
				AssertManager::GetInstance().m_Player.SetPlayerGrounded(true);
			}

			else if (playerY < AssertManager::GetInstance().m_Platform[i].GetPos().y + AssertManager::GetInstance().m_Platform[i].GetDst().h / 2 - playerH / 2 && !AssertManager::GetInstance().m_Player.IsPlayerJumped())
				playerPos = Vector2f(playerX, AssertManager::GetInstance().m_Platform[i].GetPos().y + AssertManager::GetInstance().m_Platform[i].GetDst().h / 2 - playerH / 2);
		}
	}

	for (int j = 0; j < AssertManager::GetInstance().GetFruits().size(); j++)
	{
		if (Collision::IsCollide(&AssertManager::GetInstance().m_Player.GetDst(), &AssertManager::GetInstance().GetFruits()[j].GetDst())
			&& !AssertManager::GetInstance().GetFruits()[j].IsDestroy())
		{
			AssertManager::GetInstance().GetFruits()[j].Destroy();
			AssertManager::GetInstance().GetFruitCollectedEffect(AssertManager::GetInstance().GetFruits()[j].GetPos(), Vector2f(2, 2));
		}
	}

	AssertManager::GetInstance().m_Player.SetPos(playerPos);
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
	SDL_Quit();
}