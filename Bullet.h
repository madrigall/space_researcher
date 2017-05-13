#pragma once
#include "Entity.h"
class Bullet : public Entity
{
	public:
		Bullet(float _x, float _y, float _R, float _angle, Animation& a);
		~Bullet();

		void update(float w, float h);
};

