#pragma once
#include "Entity.h"

class Explosion : public Entity
{
	public:
		Explosion(float _x, float _y, float _R, float _angle, Animation& a);
		~Explosion();

		void update(float w, float h);

};

