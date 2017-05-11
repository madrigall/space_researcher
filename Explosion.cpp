#include "Explosion.h"



Explosion::Explosion(float _x, float _y, float _R, float _angle, Animation& a)
{
	setName("explosion");

	setX(_x);
	setY(_y);

	setR(_R);
	setAngle(_angle);

	setAnimation(a);

}


Explosion::~Explosion()
{
}

void Explosion::update(float w, float h)
{

}
