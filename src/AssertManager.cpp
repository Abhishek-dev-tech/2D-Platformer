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
	m_PlayerDoubleJumpTexture = window.loadTexture("res/gfx/Player_DoubleJump.png");
	m_PlayerFallTexture = window.loadTexture("res/gfx/Player_Fall.png");

	m_PlatformTexture = window.loadTexture("res/gfx/Platform.png");
	m_Top_Bottom_OutlinePlatformTexture = window.loadTexture("res/gfx/Top_Bottom_OutlinePlatform.png");

	m_AppleTexture = window.loadTexture("res/gfx/fruits/Apple.png");
	m_BananasTexture = window.loadTexture("res/gfx/fruits/Bananas.png");
	m_CherriesTexture = window.loadTexture("res/gfx/fruits/Cherries.png");
	m_MelonTexture = window.loadTexture("res/gfx/fruits/Melon.png");
	m_StrawberryTexture = window.loadTexture("res/gfx/fruits/Strawberry.png");

	m_FruitsCollectedTexture = window.loadTexture("res/gfx/Collected.png");

	SetEntity();
}

void AssertManager::SetEntity()
{
	m_Player = Player(Vector2f(100, 100), Vector2f(1.5, 1.5), m_PlayerIdleTexture);
	
	m_Platform[0] = Entity(Vector2f(75, 460), Vector2f(2, 2), m_PlatformTexture);
	m_Platform[1] = Entity(Vector2f(850, 460), Vector2f(2, 2), m_PlatformTexture);

	fruits.push_back(Entity(Vector2f(300, 470), Vector2f(2, 2), m_AppleTexture));
	fruits.push_back(Entity(Vector2f(400, 470), Vector2f(2, 2), m_BananasTexture));
	fruits.push_back(Entity(Vector2f(500, 470), Vector2f(2, 2), m_CherriesTexture));
	fruits.push_back(Entity(Vector2f(600, 470), Vector2f(2, 2), m_MelonTexture));
	fruits.push_back(Entity(Vector2f(700, 470), Vector2f(2, 2), m_StrawberryTexture));

	m_Bottom_PlatformOutline = Entity(Vector2f(450, 514), Vector2f(2, 2), m_Top_Bottom_OutlinePlatformTexture);
}

void AssertManager::GetFruitCollectedEffect(Vector2f p_Pos, Vector2f p_Scale)
{
	Entity temp(p_Pos, p_Scale, m_FruitsCollectedTexture);

	temp.Destroy(0.45);

	fruitsCollectedEffect.push_back(temp);
}

std::vector<Entity>& AssertManager::GetFruits()
{
	return fruits;
}

void AssertManager::Update()
{
	m_Player.Update();

	for(int i = 0; i < fruitsCollectedEffect.size(); i++)
		fruitsCollectedEffect[i].Update();
	
}

void AssertManager::Render(RenderWindow& window)
{
	if (m_Player.GetAnimationState() == Run || m_Player.GetAnimationState() == Idle || m_Player.GetAnimationState() == DoubleJump)
		window.RenderAnimate(m_Player, 0, m_Player.GetRendererFlip(), m_Player.GetDst());
	else
		window.Render(m_Player, 0, m_Player.GetRendererFlip(), m_Player.GetDst());

	for (int i = 0; i < 2; i++)
		window.Render(m_Platform[i], 0, SDL_FLIP_NONE, m_Platform[i].GetDst());
	
	for (int i = 0; i < fruits.size(); i++)
		if (!fruits[i].IsDestroy())
			window.RenderAnimate(fruits[i], 0, SDL_FLIP_NONE, fruits[i].GetDst());
		

	for (int i = 0; i < fruitsCollectedEffect.size(); i++)
		if (!fruitsCollectedEffect[i].IsDestroy())
			window.RenderAnimate(fruitsCollectedEffect[i], 0, SDL_FLIP_NONE, fruitsCollectedEffect[i].GetDst());
		


	window.Render(m_Bottom_PlatformOutline, 0, SDL_FLIP_NONE, m_Bottom_PlatformOutline.GetDst());
	
}
