#include "Asteroid.h"


Asteroid::Asteroid()
{
	setX((float)(rand() % 8 - 4.0));
	setY((float)(rand() % 8 - 4.0));

	setName("asteroid");
}

Asteroid::Asteroid(float _x, float _y, float _R, float _angle, Animation & a)
{
	setX(_x);// = _x;
	setY(_y);

	//dx = _dx;
	//dy = _dy;

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
		setX(0);

	if (getX() < 0)
		setX(_w);

	if (getY() > _h)
		setY(0);

	if (getY() < 0)
		setY(_h);
}
