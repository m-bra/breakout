#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "GameObject.h"
#include <SFML/Graphics.hpp>

#define MAX_OBJECTS 24

class World
{
public:

	World(float width, float height);

	bool update(float time);
	void draw(class sf::RenderWindow *window);
	void movePaddle(float x);

private:
	float width, height;
	class Ball *ball;
	GameObject *paddle;
	GameObject *objects[MAX_OBJECTS];
};

#endif
