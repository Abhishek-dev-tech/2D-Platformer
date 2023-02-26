#pragma once
#include <vector>

#include "RenderWindow.h"

class ObjectSpawner
{
public:
	ObjectSpawner();

	static ObjectSpawner& GetInstance();

	void Update();
	void Render(RenderWindow& window);

private:

	std::vector<Entity> m_Apple;
	std::vector<Entity> m_Banana;
	std::vector<Entity> m_Cherrie;
	std::vector<Entity> m_Melon;
	std::vector<Entity> m_Strawberry;
};