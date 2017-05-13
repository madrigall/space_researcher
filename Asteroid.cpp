#include "Asteroid.h"

Asteroid::Asteroid(float _x, float _y, float _R, float _angle, Animation& a)
{
	setHealth((rand() % 6 + 3));

	setDx((float)((rand() % 3) + 1.0));
	setDy((float)((rand() % 3) + 1.0));

	if (!getDy())
		setDy(1);

	if (!getDx())
		setDx(1);

	setName("asteroid");

	setX(_x);
	setY(_y);

	setR(_R);
	setAngle(_angle);

	setAnimation(a);	
}

Asteroid::Asteroid(float _x, float _y, float _R, float _angle, int h, Animation & a)
{
	setHealth(h);

	setDx((float)((rand() % 3) + 1.0));
	setDy((float)((rand() % 3) + 1.0));

	if (!getDy())
		setDy(1);

	if (!getDx())
		setDx(1);

	setName("asteroid");

	setX(_x);
	setY(_y);

	setR(_R);
	setAngle(_angle);

	setAnimation(a);
}

Asteroid::~Asteroid()
{
}


void Asteroid::update(float _w, float _h)
{
	setX(getX() + getDx());
	setY(getY() + getDy());

	if (getX() > _w)
	{
		setDx(-getDx());
		setX(_w);
	}
		
	if (getX() < 0)
	{
		setDx(-getDx());
		setX(0);
	}
		

	if (getY() > _h)
	{
		setY(0);
	}

	if (getY() < 0)
	{
		setDy(-getDy());
		setY(0);
	}
}
