#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "GameObject.h"
#include "SFML/Graphics.hpp"

class Ball : public GameObject
{
public:
	static constexpr float PIXEL_SIZE = 4;
	static constexpr float RADIUS = PIXEL_SIZE * 4;

	/// the current moving direction
	float moveX = 250, moveY = 250;

	static sf::Texture *getTexture()
	{
		static sf::Texture *texture = 0;

		if (!texture)
		{
			texture = new sf::Texture;
			texture->loadFromFile("ball.png");
		}

		return texture;
	}

	Ball(World *world, float x, float y) :
		GameObject(world, 0, rect_t(x, y, RADIUS * 2, RADIUS * 2))
	{
		setVisibleShape(new sf::RectangleShape(sf::Vector2f(RADIUS * 2, RADIUS * 2)));
		getVisibleShape()->setTexture(getTexture());
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
	float jumpBy = PIXEL_SIZE;
};

#endif
