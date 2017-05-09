#pragma once
#include <iostream>
#include "Animation.h"

class Entity
{
	private:
		bool live;
		
		float x;
		float y;
		
		float dx;
		float dy;
		
		float R = 1.0;
		float angle;

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

