#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "AssertManager.h"
#include "RenderWindow.h"


class Game
{
public:
	Game();

	void Init();
	void HandleEvent();
	void Update();
	void CheckCollision();
	void Render();
	void Clean();

	bool Running() { return isRunning; }


private:
	bool isRunning;

	RenderWindow window;
};