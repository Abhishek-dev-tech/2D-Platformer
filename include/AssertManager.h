#pragma once
#include <iostream>
#include <vector>
#include <SDL_ttf.h>

#include "RenderWindow.h"
#include "Entity.h"
#include "Player.h"


class AssertManager
{
public:

	AssertManager();

	static AssertManager& GetInstance();

	void LoadTextures(RenderWindow& window);
	void Update();
	void SetEntity();
	void Render(RenderWindow& window);

	Player m_Player;

	Entity m_Platform[5];

	SDL_Texture* m_PlayerIdleTexture;
	SDL_Texture* m_PlayerRunTexture;

private:
	SDL_Texture* m_PlatformTexture;

};
