#ifndef GAME_OBJECT_H_INCLUDED
#define GAME_OBJECT_H_INCLUDED

#include "Rectangle.h"

namespace sf { class Shape; }

class World;

/**
	Anything that is visible in the game is a GameObject.
	Every GameObject has a rectangular collision shape / hit box,
	so that collisions between e.g. the ball and the paddle can be detected.

	It may have a non-rectangular appearance, though (the ball appears round but has a rectangular collision box)
*/
class GameObject
{
public:

	GameObject(World *world, sf::Shape *shape, Rectangle box) 
		: world(world), visibleShape(shape), collisionBox(box) {}

	// access to the collision box

	Rectangle getCollisionBox() { return collisionBox; }
	void setCollisionBox(Rectangle cb) { collisionBox = cb;  }

	/// the SFML shape that will be displayed on the screen.
	/// it does *not* have to be the same as the collision box
	sf::Shape *getVisibleShape() { return visibleShape;  }
	void setVisibleShape(sf::Shape *s) { visibleShape = s; }

	World *getWorld() { return world; }

	// helper functions:

	// move by given distances
	void moveBy(float x, float y)
	{
		Rectangle box = getCollisionBox();
		box.x += x;
		box.y += y;
		setCollisionBox(box);
	}

	// jump to position
	void jumpTo(float x, float y)
	{
		Rectangle box = getCollisionBox();
		box.x = x;
		box.y = y;
		setCollisionBox(box);
	}

private:
	Rectangle collisionBox;
	sf::Shape *visibleShape;
	World *world;
};

#endif