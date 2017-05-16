#include "Application.h"

Application::Application(std::map<std::string, Animation> &_animations)
{
	window = new sf::RenderWindow;
	animations = _animations;
	isSpace = false;
	setScore(0);

	lag = 0.0;
}

Application::~Application() 
{
	delete player;
	delete window;
}

void Application::createWindow(std::string title)
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	
	//window->create(sf::VideoMode(1280, 720), title);
	window->create(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), title, sf::Style::Fullscreen);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);
}

bool Application::Start(sf::Sprite &background)
{
	if (!window->isOpen())
		return false;

	sf::Music music;
	if (!music.openFromFile("audio/audio.ogg"))
	{
		std::cout << "Music error" << std::endl;
	}
	else
	{
		music.setLoop(true);
		music.setVolume(8.0);
		music.play();
	}

	std::list<Entity*> entities;

	menu.setData(window->getSize().x, window->getSize().y, 2, sf::Color(201, 68, 65), sf::Color(255, 255, 255));
	menu.addMenuItem("New game");
	menu.addMenuItem("Exit");
		
	bool isSpace = false;

	spawnPlayer();
	createPreloadEntities();

	while (window->isOpen())
	{
		window->draw(background);
		gameLoop();
		window->display();
	}

	return true;
}

int Application::getScore() const
{
	return score;
}

void Application::setScore(int s)
{
	if (s < 0)
		score = 0;
	else
		score = s;
}

void Application::gameLoop()
{
	switch (getGameStates())
	{
		case gameStates::start_screen: 
			showStartScreen();
			break;

		case gameStates::starting_game:
			menu.hideMenu();
			if (last_state == gameStates::loosed)
			{
				respawnPlayer();
				removeAsteroidsExplosionsPresents();
				createPreloadEntities();
			}
			
			setGameState(gameStates::playing);
			break;

		case gameStates::playing:
			{
				Informer score(60, 20, "OpenSans.ttf", "Score: " + std::to_string(getScore()));
				
				score.setFontSize(25);
				score.show(true);
				score.draw(window);
			
				drawAllEntities();
				randomSpawnPresents(4000);
				randomSpawnEntities(200);
			}
			break;

		case gameStates::loosed:
			{	
				handleEntitiesActionsAfterLose();
				showStartScreen();

				Informer gameOver(window->getSize().x / 2.0f, 150, "OpenSans.ttf", "Game Over", sf::Color(247, 203, 27));
				
				gameOver.setFontSize(64);
				gameOver.show(true);
				gameOver.draw(window);

				Informer score(window->getSize().x / 2.0f, 225, "OpenSans.ttf", "Your score: " + std::to_string(getScore()), sf::Color(247, 203, 27));
				score.setFontSize(32);
				score.show(true);
				score.draw(window);
			}
			break;

		case gameStates::exiting:
			window->close();
			break;
		
		default:
			window->close();
			break;
	}

	handleEvents(sf::Event());
	lag += c_lag.getElapsedTime().asMilliseconds();

	while (lag >= 150)
	{
		handleEntitiesActions();
		lag -= 150;
		c_lag.restart();

	}
	
	updateEntities();
}

void Application::createPreloadEntities()
{
	for (int i = 0; i < rand() % 10 + 5; ++i)
	{
		entities.push_back(new Asteroid(rand() % window->getSize().x + 25, 25, 40, 25, animations["asteroid_f"]));
		entities.push_back(new Asteroid(rand() % window->getSize().x + 25, 25, 40, 90,rand() % 2 + 1 ,animations["asteroid_s"]));
	}
}

void Application::spawnPlayer()
{
	player = new Player(window->getSize().x / 2.0f, window->getSize().y - 40.0, 20, 0, animations["player"]);
	player->setSpeed(10);

	entities.push_back(player);
}

void Application::handleEvents(sf::Event e)
{
	while (window->pollEvent(e))
	{
		switch (e.type)
		{
			case sf::Event::KeyReleased:
				switch (e.key.code)
				{
					case sf::Keyboard::Space:
						if (getGameStates() == gameStates::playing)
						{
							isSpace = true;
							sf::Time elapsed = cd.getElapsedTime();
							
							switch (getPlayer()->getPower())
							{
								case 1:
									if (elapsed.asMilliseconds() >= 200)
									{
										entities.push_back(new Bullet(getPlayer()->getX(), getPlayer()->getY(), 1, 0, animations["bullet"]));
										cd.restart();
									}
									break;
								case 2:
									if (elapsed.asMilliseconds() >= 300)
									{
										entities.push_back(new Bullet(getPlayer()->getX() - 15, getPlayer()->getY(), 1, 0, animations["bullet"]));
										entities.push_back(new Bullet(getPlayer()->getX() + 15, getPlayer()->getY(), 1, 0, animations["bullet"]));
										cd.restart();
									}
									break;
								case 3:
									if (elapsed.asMilliseconds() >= 400)
									{
										entities.push_back(new Bullet(getPlayer()->getX(), getPlayer()->getY(), 1, -30, animations["bullet"]));
										entities.push_back(new Bullet(getPlayer()->getX(), getPlayer()->getY(), 1, 0, animations["bullet"]));
										entities.push_back(new Bullet(getPlayer()->getX(), getPlayer()->getY(), 1, 30, animations["bullet"]));
										cd.restart();
									}
									break;
								case 4:
									if (elapsed.asMilliseconds() >= 500)
									{
										entities.push_back(new Bullet(getPlayer()->getX(), getPlayer()->getY(), 1, -30, animations["bullet"]));
										entities.push_back(new Bullet(getPlayer()->getX() - 15, getPlayer()->getY(), 1, 0, animations["bullet"]));
										entities.push_back(new Bullet(getPlayer()->getX() + 15, getPlayer()->getY(), 1, 0, animations["bullet"]));
										entities.push_back(new Bullet(getPlayer()->getX(), getPlayer()->getY(), 1, 30, animations["bullet"]));
										cd.restart();
									}
									break;
								case 5:
									if (elapsed.asMilliseconds() >= 600)
									{
										entities.push_back(new Bullet(getPlayer()->getX(), getPlayer()->getY(), 1, -45, animations["bullet"]));
										entities.push_back(new Bullet(getPlayer()->getX() - 15, getPlayer()->getY(), 1, -30, animations["bullet"]));
										entities.push_back(new Bullet(getPlayer()->getX() + 15, getPlayer()->getY(), 1, 0, animations["bullet"]));
										entities.push_back(new Bullet(getPlayer()->getX(), getPlayer()->getY(), 1, 30, animations["bullet"]));
										entities.push_back(new Bullet(getPlayer()->getX(), getPlayer()->getY(), 1, 45, animations["bullet"]));
										cd.restart();
									}
									break;

								default:
									if (elapsed.asMilliseconds() >= 600)
									{
										entities.push_back(new Bullet(getPlayer()->getX(), getPlayer()->getY(), 1, 0, animations["bullet"]));
										cd.restart();
									}
									break;
							}

							
						}
						break;

					case sf::Keyboard::Up:
						if (menu.isVisible())
							menu.selectMenuUp();
						break;

					case sf::Keyboard::Down:
						if (menu.isVisible())
							menu.selectMenuDown();
						break;

					case sf::Keyboard::Return:
						if (menu.isVisible())
							switch (menu.getActiveMenu())
							{
								case 0:
									setGameState(gameStates::starting_game);
									break;

								case 1:
									setGameState(gameStates::exiting);
									break;
							}
						break;

					default:
						isSpace = false;
						break;
				}
				break;

			case sf::Event::KeyPressed:
				switch (e.key.code)
				{
					case sf::Keyboard::Right:
						if (getGameStates() == gameStates::playing)
						{
							getPlayer()->setMove(true);
							getPlayer()->setAngle(90);
							getPlayer()->setAnimation(animations["player_move_r"]);
						}
						break;

					case sf::Keyboard::Left:
						if (getGameStates() == gameStates::playing)
						{
							getPlayer()->setMove(true);
							getPlayer()->setAngle(-90);
							getPlayer()->setAnimation(animations["player_move_l"]);
						}
						break;

					case sf::Keyboard::Space:
						isSpace = true;
						break;

						default:
							{
								isSpace = false;

								getPlayer()->setAnimation(animations["player"]);
								getPlayer()->setAngle(0);
								getPlayer()->setMove(false);
							}
							break;
				}
				break;

			case sf::Event::Closed:
				setGameState(gameStates::exiting);
				break;
		}

		if (getPlayer()->getMove() && (e.type != sf::Event::KeyPressed) && (e.key.code != sf::Keyboard::Right || e.key.code != sf::Keyboard::Left) && !isSpace)
		{
			getPlayer()->setMove(false);
			getPlayer()->setAnimation(animations["player"]);
			getPlayer()->setAngle(0);
		}
	}
}

void Application::drawAllEntities()
{
	for (auto e : entities)
	{
		if (e->getName() == "explosion")
		{
			if (e->getAnimation()->isEnd())
			{
				e->setHealth(0);
				continue;
			}
		}
		
		if(e->isLive())
			e->draw(window);
	}
		
}

void Application::showStartScreen()
{
	menu.showMenu();
	
	for (auto i : entities)
		if (i->getName() == "asteroid" || i->getName() == "explosion")
			i->draw(window);
	
	menu.draw(window);
}

void Application::handleEntitiesActions()
{
	if (getGameStates() != gameStates::playing)
		return;

	for (auto e_f : entities)
		for (auto e_s : entities)
			{
				if (e_f->getName() == "asteroid" && e_s->getName() == "bullet")
				{
					if (Entity::isCollided(e_f, e_s))
					{
						e_f->setHealth(e_f->getHealth() - getPlayer()->getDamage());
						e_s->setHealth(0);

						if (!e_f->isLive())
						{
							e_f->setHealth(0);
							entities.push_back(new Explosion(e_f->getX(), e_f->getY(), 1, 0, animations["explosion_f"]));
							setScore(getScore() + 1);
						}
					}
				}
				else
					if (e_f->getName() == "player" && e_s->getName() == "asteroid")
					{
						if (Entity::isCollided(e_f, e_s))
						{
							e_f->setHealth(0);
							e_s->setHealth(0);

							entities.push_back(new Explosion(e_f->getX(), e_f->getY(), 1, 0, animations["explosion_ship"]));
							setGameState(gameStates::loosed);
						}
					}
					else
						if (e_f->getName() == "player" && e_s->getName() == "present")
						{
							if (Entity::isCollided(e_f, e_s))
							{
								e_s->setHealth(0);
								getPlayer()->setPower(getPlayer()->getPower() + e_s->getBonus());
								getPlayer()->setDamage(getPlayer()->getPower());
							}
						}
			}
}

void Application::updateEntities()
{
	for (auto i = entities.begin(); i != entities.end();)
	{
		Entity *e = *i;

		e->update(window->getSize().x, window->getSize().y);
		e->getAnimation()->update();

		if (!e->isLive())
		{
			i = entities.erase(i);
			if(e->getName() != "player")
				delete e;
		}
		else
			i++;
	}
}

void Application::removeAsteroidsExplosionsPresents()
{
	for (auto i = entities.begin(); i != entities.end();)
	{
		Entity *e = *i;

		if (e->getName() == "asteroid" || e->getName() == "explosion" || e->getName() == "present")
		{
			i = entities.erase(i);
			delete e;
		}
		else
			i++;
	}
}

void Application::setGameState(gameStates s)
{
	last_state = state;
	state = s;
}

void Application::handleEntitiesActionsAfterLose()
{
	for (auto e : entities)
	{
		if (e->getName() == "explosion")
		{
			if (e->getAnimation()->isEnd())
			{
				e->setHealth(0);
				continue;
			}
		}
	}
}

void Application::respawnPlayer()
{
	getPlayer()->setHealth(1);
	getPlayer()->setPower(1);

	getPlayer()->setAnimation(animations["player"]);
	getPlayer()->setX(window->getSize().x / 2.0f);
	getPlayer()->setY(window->getSize().y - 40.0);
	getPlayer()->setR(20);
	getPlayer()->setAngle(0);
	getPlayer()->setDx(0);
	getPlayer()->setDy(0);

	entities.push_back(getPlayer());
}


void Application::randomSpawnEntities(int chance)
{
	if (!(rand() % chance))
	{
		for (int i = 0; i < rand() % 3; ++i)
		{
			entities.push_back(new Asteroid(rand() % window->getSize().x + 25, 25, 40, 25, animations["asteroid_f"]));
			entities.push_back(new Asteroid(rand() % window->getSize().x + 25, 25, 40, 90, rand() % 2 + 1, animations["asteroid_s"]));
		}
	}
}

void Application::randomSpawnPresents(int chance)
{
	if (!(rand() % chance))
	{
		entities.push_back(new Present(rand() % window->getSize().x + 25, 25, 40, 0, animations["present"]));
	}
}

void Application::removeAllEntities()
{
	entities.clear();
}

Application::gameStates Application::getGameStates() const
{
	return state;
}

Player * Application::getPlayer() const
{
	return player;
}

