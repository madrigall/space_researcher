#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include <list>

#include "Menu.h"
#include "Animation.h"
#include "Entity.h"
#include "Player.h"
#include "Asteroid.h"


class Application
{
	private:
		sf::RenderWindow *window = NULL;

	public:
		Application();
		~Application();
		void createWindow(std::string title);
		bool Start(sf::Sprite &background, std::map<std::string, Animation>& animations);
};

