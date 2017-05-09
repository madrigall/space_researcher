#pragma once
#include "Entity.h"

class Player : public Entity
{
	bool thrust;

	public:
		Player();
		Player(float _x, float _y, float _R, float _angle, Animation& a);
		~Player();

		void update(float w, float h);
		bool getThrust();
		void setThrust(bool t);
};

