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

		void setSpeed(float s);
		void setMove(bool t);
		void setPower(int p);

		bool getMove();
		int getPower() const;
		float getSpeed();
		
};

