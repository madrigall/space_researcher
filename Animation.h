#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
	private:
		float currentFrame;
		float speed;
		
		sf::Sprite sprite;
		std::vector<sf::IntRect> frames;

	public:
		Animation();
		Animation(sf::Texture &t, int x, int y, int w, int h, int count, float _speed);

		~Animation();

		void update();
		bool isEnd();
		sf::Sprite& getSprite();
};

