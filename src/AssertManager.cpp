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
	m_KiwiTexture = window.loadTexture("res/gfx/fruits/Kiwi.png");
	m_MelonTexture = window.loadTexture("res/gfx/fruits/Melon.png");
	m_OrangeTexture = window.loadTexture("res/gfx/fruits/Orange.png");
	m_PineappleTexture = window.loadTexture("res/gfx/fruits/Pineapple.png");
	m_StrawberryTexture = window.loadTexture("res/gfx/fruits/Strawberry.png");

	SetEntity();
}

void AssertManager::SetEntity()
{
	m_Player = Player(Vector2f(100, 100), Vector2f(1.5, 1.5), m_PlayerIdleTexture);
	
	m_Platform = Entity(Vector2f(150, 475), Vector2f(2, 2), m_PlatformTexture);

	m_Top_Bottom_OutlinePlatform = Entity(Vector2f(450, 514), Vector2f(2, 2), m_Top_Bottom_OutlinePlatformTexture);

	m_Apple = Entity(Vector2f(10, 10), Vector2f(1.5, 1.5), m_AppleTexture);
	m_Bananas = Entity(Vector2f(30, 30), Vector2f(1.5, 1.5), m_BananasTexture);
	m_Cherries = Entity(Vector2f(50, 50), Vector2f(1.5, 1.5), m_CherriesTexture);
	m_Kiwi = Entity(Vector2f(70, 70), Vector2f(1.5, 1.5), m_KiwiTexture);
	m_Melon = Entity(Vector2f(90, 90), Vector2f(1.5, 1.5), m_MelonTexture);
	m_Orange = Entity(Vector2f(110, 110), Vector2f(1.5, 1.5), m_OrangeTexture);
	m_Pineapple = Entity(Vector2f(130, 130), Vector2f(1.5, 1.5), m_PineappleTexture);
	m_Strawberry = Entity(Vector2f(150, 150), Vector2f(1.5, 1.5), m_StrawberryTexture);
	
}

void AssertManager::Update()
{
	m_Player.Update();
}

void AssertManager::Render(RenderWindow& window)
{
	if (m_Player.GetAnimationState() == Run || m_Player.GetAnimationState() == Idle || m_Player.GetAnimationState() == DoubleJump)
		window.RenderAnimate(m_Player, 0, m_Player.GetRendererFlip(), m_Player.GetDst());
	else
		window.Render(m_Player, 0, m_Player.GetRendererFlip(), m_Player.GetDst());

	window.RenderAnimate(m_Apple, 0, SDL_FLIP_NONE, m_Apple.GetDst());
	window.RenderAnimate(m_Bananas, 0, SDL_FLIP_NONE, m_Bananas.GetDst());
	window.RenderAnimate(m_Cherries, 0, SDL_FLIP_NONE, m_Cherries.GetDst());
	window.RenderAnimate(m_Kiwi, 0, SDL_FLIP_NONE, m_Kiwi.GetDst());
	window.RenderAnimate(m_Melon, 0, SDL_FLIP_NONE, m_Melon.GetDst());
	window.RenderAnimate(m_Orange, 0, SDL_FLIP_NONE, m_Orange.GetDst());
	window.RenderAnimate(m_Pineapple, 0, SDL_FLIP_NONE, m_Pineapple.GetDst());
	window.RenderAnimate(m_Strawberry, 0, SDL_FLIP_NONE, m_Strawberry.GetDst());


	window.Render(m_Platform, 0, SDL_FLIP_NONE, m_Platform.GetDst());

	window.Render(m_Top_Bottom_OutlinePlatform, 0, SDL_FLIP_NONE, m_Top_Bottom_OutlinePlatform.GetDst());
	
}
