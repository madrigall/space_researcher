#include "Bullet.h"


Bullet::Bullet()
{
}

Bullet::Bullet(float _x, float _y, float _R, float _angle, Animation& a)
{
	setName("bullet");

	setX(_x);
	setY(_y);

	setR(_R);
	setAngle(_angle);

	setAnimation(a);
}


Bullet::~Bullet()
{
}

void Bullet::update(float w, float h)
{
	setDy(getDy() - 0.5);

	setY(getY() + getDy());

	if (getX() > w || getX() < 0 || getY() > h || getY() < 0)
		setLive(false);
}