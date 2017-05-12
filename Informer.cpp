#include "Informer.h"



Informer::Informer(float _x, float _y, std::string font_path)
{
	setColor(sf::Color(255, 255, 255));

	setX(_x);
	setY(_y);

	if (!font.loadFromFile(font_path))
	{
		std::cout << "Font didn't load!" << std::endl;
	}
}

Informer::Informer(float _x, float _y, std::string font_path, std::string msg)
{
	setColor(sf::Color(255, 255, 255));

	if (!font.loadFromFile(font_path))
	{
		std::cout << "Font didn't load!" << std::endl;
	}

	setX(_x);
	setY(_y);

	setMsg(msg);
}

Informer::Informer(float _x, float _y, std::string font_path, std::string msg, sf::Color c)
{
	setColor(c);

	if (!font.loadFromFile(font_path))
	{
		std::cout << "Font didn't load!" << std::endl;
	}

	setX(_x);
	setY(_y);

	setMsg(msg);
}

void Informer::setMsg(std::string msg)
{
	text.setString(msg);
}

void Informer::setColor(sf::Color c)
{
	color = c;
}

void Informer::setFontSize(unsigned int size)
{
	text.setCharacterSize(size);
}

void Informer::setX(float _x)
{
	x = _x;
}

void Informer::setY(float _y)
{
	y = _y;
}

float Informer::getX() const
{
	return x;
}

float Informer::getY() const
{
	return y;
}

void Informer::draw(sf::RenderWindow * win) const
{
	if(isVisible())
		win->draw(text);
}

bool Informer::isVisible() const
{
	return visible;
}

void Informer::show(bool centered)
{
	visible = true;
	
	text.setFont(font);
	text.setFillColor(color);

	text.setPosition(sf::Vector2f(getX(), getY()));

	//Центрирование
	if (centered)
	{
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

	}
}

void Informer::hide()
{
	visible = false;
}


Informer::~Informer()
{
}
