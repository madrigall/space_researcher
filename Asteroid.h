#pragma once
#include "Entity.h"

class Asteroid : public Entity
{
	public:
		Asteroid(float _x, float _y, float _R, float _angle, Animation& a);
		Asteroid(float _x, float _y, float _R, float _angle, int h, Animation& a);
		~Asteroid();

		void update(float w, float h);
};

