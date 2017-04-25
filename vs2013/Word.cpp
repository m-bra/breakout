
#include "World.h"
#include "Ball.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <cstdlib>

World::World(float width, float height)
	: width(width), height(height) 
{
	ball = new Ball(this, width / 2, height / 2);

	float paddleWidth = 200;
	float paddleHeight = 20;
	sf::Shape *paddleShape =
		new sf::RectangleShape(sf::Vector2f(paddleWidth, paddleHeight));
	paddleShape->setFillColor(sf::Color(150, 150, 150));

	Rectangle paddleBox = rect_t((width - paddleWidth) / 2 + 140, height - 60, paddleWidth, paddleHeight);
	paddle = new GameObject(this, paddleShape, paddleBox);

	memset(objects, 0, MAX_OBJECTS * sizeof(GameObject *));

	int blockWidth = 50, blockHeight = blockWidth;
	int gapX = 5, gapY = 5;
	int x = gapX, y = gapY;
	for (int i = 0; i < MAX_OBJECTS; ++i)
	{
		int blockCount = 1 + rand() % 3;
		int thisBlockWidth = (blockWidth + gapX) * blockCount - gapX;
		sf::Shape *shape = 
			new sf::RectangleShape(sf::Vector2f(thisBlockWidth, blockHeight));
		shape->setPosition(x, y);
		shape->setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));

		Rectangle rect = rect_t(x, y, thisBlockWidth, blockHeight);

		x += gapX + thisBlockWidth;
		if (x + 3 * blockWidth + gapX * 3 > width)
		{
			x = gapX;
			y += gapY + blockHeight;
		}

		objects[i] = new GameObject(this, shape, rect);
	}
}

bool World::update(float time)
{
	ball->move(time);

	if (ball->getCollisionBox().y < 0)
		ball->onTouchTop();
	if (ball->getCollisionBox().right() > width)
		ball->onTouchRight();
	if (ball->getCollisionBox().x < 0)
		ball->onTouchLeft();

	for (int i = 0; i < MAX_OBJECTS; ++i)
		if (objects[i])
		{
			if (ball->getCollisionBox().touches(objects[i]->getCollisionBox()))
			{
				delete objects[i];
				objects[i] = 0;

				ball->moveY = -ball->moveY;
				ball->moveX = -ball->moveX;

				break;
			}
		}

	if (ball->getCollisionBox().touches(paddle->getCollisionBox()))
		ball->moveY = -ball->moveY;

	return ball->getCollisionBox().bottom() < height;
}

void World::draw(sf::RenderWindow *window)
{
	Rectangle ballBox = ball->getCollisionBox();
	ball->getVisibleShape()->setPosition(ballBox.x, ballBox.y);

	Rectangle paddleBox = paddle->getCollisionBox();
	paddle->getVisibleShape()->setPosition(paddleBox.x - 70, paddleBox.y);

	window->draw(*ball->getVisibleShape());
	window->draw(*paddle->getVisibleShape());

	for (int i = 0; i < MAX_OBJECTS; ++i)
		if (objects[i])
		{
			ball->getVisibleShape()->setPosition(ballBox.x, ballBox.y);

			window->draw(*objects[i]->getVisibleShape());
		}
}

void World::movePaddle(float x)
{
	paddle->moveBy(x, 0);
}