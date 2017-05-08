#include <SFML/Graphics.hpp>
#include "Application.h"
#include <time.h>
#include <list>

using namespace sf;

int main()
{
	Texture t_background;

	t_background.loadFromFile("images/background.jpg");
	t_background.setSmooth(true);

	Sprite s_background;
	s_background.setTexture(t_background);

	Application app;
	app.createWindow("Space resorcher");
	app.Start(s_background);

	return 0;
}
