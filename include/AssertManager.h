#pragma once
#include <iostream>
#include <vector>
#include <SDL_ttf.h>

#include "RenderWindow.h"
#include "Entity.h"


class AssertManager
{
public:

	AssertManager();

	static AssertManager& GetInstance();

	void LoadTextures(RenderWindow window);
	void Update();
	void SetEntity();
	void Render(RenderWindow window);

	//Player m_PlayerShip;

private:
	//SDL_Texture* playerShip;


};
