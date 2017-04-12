#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "GameObject.h"

class Ball : public GameObject
{
public:

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