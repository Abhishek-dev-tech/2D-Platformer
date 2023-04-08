#include <SDL.h>
#include <SDL_image.h>

#include "Entity.h"

Entity::Entity(Vector2f p_pos, Vector2f p_scale, SDL_Texture* p_tex)
	:pos(p_pos), tex(p_tex), scale(p_scale)
{
	SDL_QueryTexture(tex, NULL, NULL, &currentFrame.w, &currentFrame.h);

	currentFrame.x = 0;
	currentFrame.y = 0;

	m_Dst.w = 0;
	m_Dst.h = 0;

	destroy = false;
	maxDestroyTime = 0;
}

void Entity::Update()
{
	if (maxDestroyTime != 0)
	{
		if (!destroyTimer.IsStarted())
			destroyTimer.Start();

		if (destroyTimer.GetTicks() * 0.001 >= maxDestroyTime)
		{
			Destroy();
			destroyTimer.Stop();
		}
	}
}

void Entity::UpdateTexture()
{
	SDL_QueryTexture(tex, NULL, NULL, &currentFrame.w, &currentFrame.h);

	currentFrame.x = 0;
	currentFrame.y = 0;
}

void Entity::SetTexture(SDL_Texture* p_Texture)
{
	tex = p_Texture;
}

void Entity::SetPos(Vector2f _pos)
{
	pos = _pos;
}

void Entity::SetScale(Vector2f _scale)
{
	scale = _scale;
}

void Entity::Destroy()
{
	destroy = true;
}

void Entity::Destroy(float p_Time)
{
	maxDestroyTime = p_Time;
}

void Entity::SetDestroyFalse()
{
	destroy = false;
}

SDL_Texture* Entity::getTex()
{
	return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}

SDL_Rect& Entity::GetDst()
{
	return m_Dst;
}

bool Entity::IsDestroy()
{
	return  destroy;
}
