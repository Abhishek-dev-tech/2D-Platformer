#include <SDL.h>
#include <SDL_image.h>

#include "Entity.h"

Entity::Entity(Vector2f p_pos, Vector2f p_scale, SDL_Texture* p_tex)
	:pos(p_pos), tex(p_tex), scale(p_scale)
{
	SDL_QueryTexture(tex, NULL, NULL, &currentFrame.w, &currentFrame.h);

	currentFrame.x = 0;
	currentFrame.y = 0;

	destroy = false;
}

void Entity::Update()
{
	dst.x = GetPos().x - currentFrame.w / 2.0 * GetScale().x;
	dst.y = GetPos().y - currentFrame.h / 2.0 * GetScale().y;
	dst.w = GetScale().x * currentFrame.w;
	dst.h = GetScale().y * currentFrame.h;
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
	return dst;
}

bool Entity::IsDestroy()
{
	return  destroy;
}
