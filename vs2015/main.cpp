
#include "World.h"
#include "main.h"

int main()
{
	int width = 800, height = 600;
	sf::RenderWindow window(sf::VideoMode(width, height), "breakout!");

	World world((float)width, (float)height);

	sf::Clock clock;
	float currentTime = clock.getElapsedTime().asSeconds();

	int motion = 0;
	bool gameover = false;

	while (window.isOpen())
	{
		float sinceLastFrame = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
					motion = -1;
				if (event.key.code == sf::Keyboard::Right)
					motion = 1;
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Left)
					motion = 0;
				if (event.key.code == sf::Keyboard::Right)
					motion = 0;
			}
		}

		world.movePaddle(motion * sinceLastFrame * 200);

		window.clear();
		
		if (!gameover)
			gameover = !world.update(sinceLastFrame);

		world.draw(&window);

		window.display();
	}

	return 0;
}