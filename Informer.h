#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Informer
{
	private:
		sf::Text text;
		sf::Font font;
		sf::Color color;

		float x;
		float y;

		bool visible = false;

	public:
		Informer(float _x, float _y, std::string font_path);
		Informer(float _x, float _y, std::string font_path, std::string msg);
		Informer(float _x, float _y, std::string font_path, std::string msg, sf::Color c);

		void setMsg(std::string msg);
		void setColor(sf::Color c);

		void setFontSize(unsigned int size);
		
		void setX(float _x);
		void setY(float _y);

		float getX() const;
		float getY() const;

		void draw(sf::RenderWindow *win) const;

		bool isVisible() const;

		void show(bool centered);
		void hide();

		~Informer();
};

