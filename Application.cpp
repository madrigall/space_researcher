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
	window->create(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), title);//,sf::Style::Fullscreen);
	window->setFramerateLimit(60);
}

bool Application::Start(sf::Sprite &background, std::map<std::string, Animation>& animations)
{
	if (!window->isOpen())
		return false;

	std::list<Entity*> entities;

	//sf::Color main(205, 118, 53);//(201, 68, 65);
	//sf::Color active(241, 104, 157);//(196, 161, 50);

	Menu menu(window->getSize().x, window->getSize().y, 2, sf::Color(201, 68, 65), sf::Color(255, 255, 255));
	
	menu.addMenuItem("New game");
	menu.addMenuItem("Exit");

	menu.showMenu();
	
	Player *p = new Player(sf::VideoMode::getDesktopMode().width / 2.0f, sf::VideoMode::getDesktopMode().height / 2.0f, 20, 0, animations["player"]);

	for (int i = 0; i < 15; i++)
	{
		Asteroid *a = new Asteroid(rand() % sf::VideoMode::getDesktopMode().width, rand() % sf::VideoMode::getDesktopMode().height, 360, 25, animations["asteroid_f"]);
		entities.push_back(a);
	}


	entities.push_back(p);

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
							if (menu.isVisible())
								menu.selectMenuUp();

						break;

						case sf::Keyboard::Down :
							if (menu.isVisible())
								menu.selectMenuDown();
						break;

						case sf::Keyboard::Return :
							switch (menu.getActiveMenu())
							{
								case 0 :
									std::cout << "Play button has been pressed" << std::endl;
									
									if(menu.isVisible())
										menu.hideMenu();
															
								break;

								case 1 :
									window->close();
								break;
							}

						break;
					}
				break;

				case sf::Event::KeyPressed : 
					switch (e.key.code)
					{
						case sf::Keyboard::Right:
							p->setAngle(p->getAngle() + 3);

						break;

						case sf::Keyboard::Left:
							p->setAngle(p->getAngle() - 3);

						break;
					}
				break;

				case sf::Event::Closed :
					window->close();
				break;
			}
		}

		window->draw(background);
		
		if(menu.isVisible())
			menu.draw(window);


		for (auto i : entities)
			i->draw(window);

		for (auto i = entities.begin(); i != entities.end();)
		{
			Entity *e = *i;

			e->update(window->getSize().x, window->getSize().y);
			e->getAnimation().update();

			if (!e->isLive()) 
			{ 
				i = entities.erase(i);
				delete e; 
			}
			else 
				i++;
		}
		
		window->display();
	}

	return true;
}


