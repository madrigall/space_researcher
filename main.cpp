#include <SFML/Graphics.hpp>

#include "Application.h"
#include <map>
#include <time.h>

using namespace sf;

int main()
{
	srand(time(0));
	
	std::map<std::string, Animation> animations;

	Texture t_background, t_player, t_explosion_f, t_explosion_s, t_asteroid_f, t_asteroid_s, t_bullet, t_present;

	t_background.loadFromFile("images/background.jpg");
	t_background.setSmooth(true);

	t_player.loadFromFile("images/spaceship.png");
	t_player.setSmooth(true);

	t_explosion_f.loadFromFile("images/explosions/type_C.png");
	t_explosion_s.loadFromFile("images/explosions/type_B.png");
	t_explosion_s.setSmooth(true);

	t_asteroid_f.loadFromFile("images/rock.png");
	t_asteroid_s.loadFromFile("images/rock_small.png");

	t_bullet.loadFromFile("images/fire_blue.png");

	t_present.loadFromFile("images/present_small.png");
	t_present.setSmooth(true);

	Sprite s_background;
	s_background.setTexture(t_background);

	Animation a_player(t_player, 40, 0, 40, 40, 1, 0);
	Animation a_player_move_l(t_player, 0, 40, 40, 40, 1, 0.2);
	Animation a_player_move_r(t_player, 80, 40, 40, 40, 1, 0.2);

	Animation a_explosion_f(t_explosion_f, 0, 0, 256, 256, 48, 0.5);
	Animation a_explosion_ship(t_explosion_s, 0, 0, 192, 192, 64, 0.5);

	Animation a_asteroid_f(t_asteroid_f, 0, 0, 64, 64, 16, 0.09);
	Animation a_asteroid_s(t_asteroid_s, 0, 0, 64, 64, 16, 0.09);

	Animation a_bullet(t_bullet, 0, 0, 32, 64, 16, 0.5);

	Animation a_present(t_present, 0, 0, 64, 64, 1, 0);

	animations["player"]			= a_player;
	animations["player_move_l"]		= a_player_move_l;
	animations["player_move_r"]		= a_player_move_r;
	animations["explosion_f"]		= a_explosion_f;
	animations["explosion_ship"]	= a_explosion_ship;
	animations["asteroid_f"]		= a_asteroid_f;
	animations["asteroid_s"]		= a_asteroid_s;
	animations["bullet"]			= a_bullet;
	animations["present"]			= a_present;

	Application app(animations);
	app.createWindow("Space researcher");
	app.Start(s_background);

	return 0;
}
