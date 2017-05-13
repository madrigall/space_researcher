#include "Bullet.h"

Bullet::Bullet(float _x, float _y, float _R, float _angle, Animation& a)
{
	setName("bullet");

	setX(_x);
	setY(_y);

	setR(_R);
	setAngle(_angle);

	setRotationMoving(true);
	setAnimation(a);
}


Bullet::~Bullet()
{
}

void Bullet::update(float w, float h)
{
	float DEGTORAD = 0.017453f;

	setDy(getDy() - 0.5);
	setDx(getDx() + sin(getAngle()*DEGTORAD)*0.9);

	setY(getY() + getDy());
	setX(getX() + getDx());

	if (getX() > w || getX() < 0 || getY() > h || getY() < 0)
		setHealth(0);
}