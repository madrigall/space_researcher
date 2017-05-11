#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include <list>

#include "Animation.h"
#include "Menu.h"
#include "Entity.h"
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Explosion.h"


class Application
{
	private:
		enum gameStates {
			start_screen,
			starting_game,
			playing,
			loosed,
			exiting
		};

		sf::RenderWindow *window = NULL;
		std::list<Entity*> entities;
		Player *player;
		std::map<std::string, Animation> animations;
		gameStates state;
		gameStates last_state;
		Menu menu;

		bool isSpace = false;

	public:
		Application(std::map<std::string, Animation> &_animations);
		~Application();
		void createWindow(std::string title);
		bool Start(sf::Sprite &background);

		void gameLoop();
		void createPreloadEntities();
		void spawnPlayer();
		void handleEvents(sf::Event e);
		void drawAllEntities();
		void showStartScreen();
		void handleEntitiesActions();
		void updateEntities();
		void randomSpawnEntities(int chance);
		void removeAllEntities();
		void removeAsteroidsAndExplosions();
		void setGameState(gameStates s);

		gameStates getGameStates() const;
		Player* getPlayer() const;
};

