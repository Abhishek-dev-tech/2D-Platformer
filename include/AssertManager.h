#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.h"
#include "Entity.h"
#include "Mathf.h"
#include "Player.h"


class AssertManager
{
public:

	AssertManager();

	static AssertManager& GetInstance();

	void LoadTextures(RenderWindow& window);
	void Update();
	void SetEntity();
	void GetFruitCollectedEffect(Vector2f p_Pos, Vector2f p_Scale);
	void Render(RenderWindow& window);

	std::vector<Entity>& GetFruits();

	Player m_Player;

	Entity m_Platform[2];
	Entity m_Bottom_PlatformOutline;

	SDL_Texture* m_PlayerIdleTexture;
	SDL_Texture* m_PlayerRunTexture;
	SDL_Texture* m_PlayerJumpTexture;
	SDL_Texture* m_PlayerDoubleJumpTexture;
	SDL_Texture* m_PlayerFallTexture;


private:
	SDL_Texture* m_PlatformTexture;
	SDL_Texture* m_Top_Bottom_OutlinePlatformTexture;

	SDL_Texture* m_AppleTexture;
	SDL_Texture* m_BananasTexture;
	SDL_Texture* m_CherriesTexture;
	SDL_Texture* m_MelonTexture;
	SDL_Texture* m_StrawberryTexture;

	SDL_Texture* m_FruitsCollectedTexture;
	
	std::vector<Entity> fruits;
	std::vector<Entity> fruitsCollectedEffect;

	Timer FruitsCollectedDestroyTimer;

};
