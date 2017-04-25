
#include "Ball.h"

sf::Texture *Ball::getTexture()
{
	static sf::Texture *texture = 0;

	if (!texture)
	{
		texture = new sf::Texture;
		texture->loadFromFile("ball.png");
	}

	return texture;
}

Ball::Ball(World *world, float x, float y) :
	GameObject(world, 0, rect_t(x, y, RADIUS * 2, RADIUS * 2))
{
	setVisibleShape(new sf::RectangleShape(sf::Vector2f(RADIUS * 2, RADIUS * 2)));
	getVisibleShape()->setTexture(getTexture());
}

void Ball::move(float time)
{
	moveBy(moveX * time, moveY * time);
}

/// the reaction of this ball when it touches something with its left side
void Ball::onTouchLeft()
{
	if (moveX < 0)
		moveX = -moveX;
}

void Ball::onTouchRight()
{
	if (moveX > 0)
		moveX = -moveX;
}

void GameObject::moveBy(float x, float y)
{
	Rectangle box = getCollisionBox();
	box.x += x;
	box.y += y;
	setCollisionBox(box);
}

// jump to position
void GameObject::jumpTo(float x, float y)
{
	Rectangle box = getCollisionBox();
	box.x = x;
	box.y = y;
	setCollisionBox(box);
}

void Ball::onTouchTop()
{
	if (moveY < 0)
		moveY = -moveY;
}

void Ball::onTouchBottom()
{
	if (moveY > 0)
		moveY = -moveY;
}