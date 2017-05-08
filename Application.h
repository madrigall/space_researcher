#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <iostream>

class Application
{
	private:
		sf::RenderWindow *window = NULL;

	public:
		Application();
		~Application();
		void createWindow(std::string title);
		bool Start(sf::Sprite background);
};

