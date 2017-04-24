#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "GameObject.h"
#include "SFML/Graphics.hpp"

class Ball : public GameObject
{
public:
	static constexpr float RADIUS = 25;

	Ball(World *world, float x, float y) :
		GameObject(world, new sf::CircleShape(RADIUS), rect(x, y, RADIUS * 2, RADIUS * 2))
	{

	}

	void move(float time)
	{
		moveBy(moveX * time, moveY * time);
	}

	/// the reaction of this ball when it touches something with its left side
	void onTouchLeft()
	{
		if (moveX < 0)
			moveX = -moveX;
	}

	void onTouchRight()
	{
		if (moveX > 0)
			moveX = -moveX;
	}

	void onTouchTop()
	{
		if (moveY < 0)
			moveY = -moveY;
	}

	void onTouchBottom()
	{
		if (moveY > 0)
			moveY = -moveY;
	}

private:
	/// the current moving direction
	float moveX, moveY;
};

#endif
