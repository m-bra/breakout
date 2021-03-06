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

	static sf::Texture *getTexture();

	Ball(World *world, float x, float y);

	void move(float time);

	/// the reaction of this ball when it touches something with its left side
	void onTouchLeft();
	void onTouchRight();
	void onTouchTop();
	void onTouchBottom();

private:
	float jumpBy = PIXEL_SIZE;
};

#endif
