#include "Application.h"

Application::Application()
{
	window = new sf::RenderWindow;
}

Application::~Application() 
{
	delete window;
}

void Application::createWindow(std::string title)
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	
	//window->create(sf::VideoMode(1280, 720), title);
	window->create(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), title, sf::Style::Fullscreen);
	window->setFramerateLimit(60);
}

bool Application::Start(sf::Sprite background)
{
	if (!window->isOpen())
		return false;

	//sf::Color main(205, 118, 53);//(201, 68, 65);
	//sf::Color active(241, 104, 157);//(196, 161, 50);

	Menu menu(window->getSize().x, window->getSize().y, 2, sf::Color(201, 68, 65), sf::Color(255, 255, 255));
	
	menu.addMenuItem("New game");
	menu.addMenuItem("Exit");

	while (window->isOpen())
	{
		sf::Event e;

		while (window->pollEvent(e))
		{
			switch (e.type)
			{
				case sf::Event::KeyReleased	:
					switch (e.key.code)
					{
						case sf::Keyboard::Up :
							menu.selectMenuUp();
						break;

						case sf::Keyboard::Down :
							menu.selectMenuDown();
						break;

						case sf::Keyboard::Return :
							switch (menu.getActiveMenu())
							{
								case 0 :
									std::cout << "Play button has been pressed" << std::endl;
								break;

								case 1 :
									window->close();
								break;
							}

						break;
					}
				break;

				case sf::Event::Closed :
					window->close();
				break;
			}
		}

		window->clear();

		window->draw(background);
		menu.draw(window);

		window->display();
	}

	return true;
}


