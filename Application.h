#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <list>

#include "Animation.h"
#include "Menu.h"
#include "Entity.h"
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Explosion.h"
#include "Informer.h"
#include "Present.h"


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

		bool isSpace;
		int score;

		sf::RenderWindow *window = NULL;
		std::list<Entity*> entities;
		
		Player *player;
		
		std::map<std::string, Animation> animations;
		
		gameStates state;
		gameStates last_state;

		Menu menu;

		sf::Clock cd;
		sf::Clock c_lag;

		double lag;

	public:
		Application(std::map<std::string, Animation> &_animations);
		~Application();

		void createWindow(std::string title);
		bool Start(sf::Sprite &background);

		int getScore() const;
		void setScore(int s);

		void gameLoop();
		void createPreloadEntities();
		void spawnPlayer();
		void handleEvents(sf::Event e);
		void drawAllEntities();
		void showStartScreen();
		void handleEntitiesActions();
		void updateEntities();
		void randomSpawnEntities(int chance);
		void randomSpawnPresents(int chance);
		void removeAllEntities();
		void removeAsteroidsExplosionsPresents();
		void setGameState(gameStates s);
		void handleEntitiesActionsAfterLose();

		void respawnPlayer();
		
		gameStates getGameStates() const;
		Player* getPlayer() const;
};

