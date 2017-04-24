#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "GameObject.h"
#include "SFML/Window.hpp"

#define MAX_OBJECTS 64

class World
{
public:

	void update(float time)
	{

	}

	void draw(sf::Window *window)
	{
		for (int i = 0; i < MAX_OBJECTS; ++i)
			window->draw(objects[i]->getVisibleShape());
	}

private:
	GameObject *objects[MAX_OBJECTS];
};

#endif
