#pragma once
#include "Entity.h"
class Asteroid : public Entity
{
	public:
		Asteroid();
		Asteroid(float _x, float _y, float _R, float _angle, Animation & a);
		~Asteroid();

		void update(float w, float h);
};

