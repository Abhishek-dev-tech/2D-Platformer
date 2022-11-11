#include "Game.h"
#include "RenderWindow.h"

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