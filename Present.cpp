#include "Present.h"



Present::Present(float _x, float _y, float _R, float _angle, Animation& a)
{
	setBonus(1);
	setName("present");

	setX(_x);
	setY(_y);

	setR(_R);
	setAngle(_angle);

	setRotationMoving(false);
	setAnimation(a);
}


Present::~Present()
{
}

void Present::update(float w, float h)
{
	setDy(getDy() + 0.04);

	setY(getY() + getDy());

	if (getX() > w || getX() < 0 || getY() > h || getY() < 0)
		setHealth(0);
}

int Present::getPresent() const
{
	return getBonus();
}
