#include "Menu.h"

Menu::Menu(unsigned _w, unsigned _h, int n, sf::Color _color, sf::Color _activeColor)
{
	setMenuAmount(n);
	width = _w;
	height = _h;

	mainColor = _color;
	activeColor = _activeColor;

	menu = new sf::Text[menuAmount];

	if (!font.loadFromFile("OpenSans.ttf"))
	{
		std::cout << "Font didn't load!" << std::endl;
	}
}

Menu::~Menu()
{
	delete[] menu;
}

void Menu::draw(sf::RenderWindow *window) const
{

	for (int i = 0; i < menuAmount; ++i)
	{
		window->draw(menu[i]);
	}
}

void Menu::selectMenuUp()
{
	if (activeMenu - 1 >= 0)
	{
		menu[activeMenu].setFillColor(mainColor);
		activeMenu--;
		menu[activeMenu].setFillColor(activeColor);
	}
}

void Menu::selectMenuDown()
{
	if (activeMenu + 1 < menuAmount)
	{
		menu[activeMenu].setFillColor(mainColor);
		activeMenu++;
		menu[activeMenu].setFillColor(activeColor);
	}
}

int Menu::getActiveMenu() const
{
	return activeMenu;
}

void Menu::setActiveMenu(int _a)
{
	if (_a < 0)
		return;

	activeMenu = _a;
	menu[activeMenu].setFillColor(mainColor);
}

void Menu::setMenuAmount(int n)
{
	if (n < 0)
		menuAmount = 0;
	else
		menuAmount = n;
}

bool Menu::addMenuItem(std::string name)
{
	if (currentIndex >= menuAmount)
		return false;

	menu[currentIndex].setFont(font);

	if(!currentIndex)
		menu[currentIndex].setFillColor(activeColor);
	else
		menu[currentIndex].setFillColor(mainColor);
	
	menu[currentIndex].setString(name);
	menu[currentIndex].setPosition(sf::Vector2f( width / 2.0f, (height / 3.0f) + (currentIndex + 1) * 100.0f ));

	//Центрирование
	sf::FloatRect textRect = menu[currentIndex].getLocalBounds();
	menu[currentIndex].setOrigin(textRect.left + textRect.width / 2.0f,	textRect.top + textRect.height / 2.0f);

	currentIndex++;

	return true;
}
