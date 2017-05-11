#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Menu
{
	private:
		int menuAmount = 0;
		int currentIndex = 0;
		int activeMenu = 0;

		unsigned width;
		unsigned height;

		sf::Color mainColor;
		sf::Color activeColor;
		sf::Font font;
		sf::Text *menu;

		bool visible = false;

	public:
		Menu();
		Menu(unsigned _w, unsigned _h, int n, sf::Color _color, sf::Color _activeColor);
		~Menu();

		void draw(sf::RenderWindow *window) const;

		void selectMenuUp();
		void selectMenuDown();
		void setData(unsigned _w, unsigned _h, int n, sf::Color _color, sf::Color _activeColor);

		int getActiveMenu() const;

		void setActiveMenu(int _a);
		void setMenuAmount(int n);

		bool addMenuItem(std::string name);
		bool isVisible();

		void showMenu();
		void hideMenu();
};