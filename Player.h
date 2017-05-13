#pragma once
#include "Entity.h"

class Player : public Entity
{
	bool move;
	float maxSpeed;
	int power;

	public:
		Player(float _x, float _y, float _R, float _angle, Animation& a);
		~Player();

		void update(float w, float h);
		bool getMove();
		void setMove(bool t);
		int getPower() const;
		void setPower(int p);

		float getSpeed();
		void setSpeed(float s);
};

