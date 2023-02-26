#include "ObjectSpawner.h"

ObjectSpawner::ObjectSpawner()
{

}

ObjectSpawner& ObjectSpawner::GetInstance()
{
	static ObjectSpawner* instance = new ObjectSpawner;

	return *instance;
}

void ObjectSpawner::Update()
{

}

void ObjectSpawner::Render(RenderWindow& window)
{

}