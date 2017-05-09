#pragma once
#include <iostream>
#include "Animation.h"

class Entity
{
	private:
		bool live;
		
		float x = 0.0;
		float y = 0.0;
		
		float dx = 0.0;
		float dy = 0.0;
		
		float R = 0.0;
		float angle = 0.0;

		std::string name;
		Animation animation;

	public:
		Entity();
		Entity(float _x, float _y, float _R, float _angle, std::string _name, Animation& a);
		virtual ~Entity();

		void draw(sf::RenderWindow *win);
		virtual void update(float w, float h) = 0;
	
		void setLive(bool _live);
		void setX(float _x);
		void setY(float _y);
		void setDx(float _dx);
		void setDy(float _dy);
		void setR(float _R);
		void setAngle(float _angle);
		void setName(std::string _name);
		void setAnimation(Animation& a);

		bool isLive() const;
		float getX() const;
		float getY() const;
		float getDx() const;
		float getDy() const;
		float getR() const;
		float getAngle() const;
		std::string getName() const;
		Animation getAnimation() const;

};

