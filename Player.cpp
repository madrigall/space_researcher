#include "Player.h"

Player::Player()
{
	setName("player");
}

Player::Player(float _x, float _y, float _R, float _angle, Animation & a)
{
	setX(_x);// = _x;
	setY(_y);

	//dx = _dx;
	//dy = _dy;

	setR(_R);
	setAngle(_angle);

	setAnimation(a);
}


Player::~Player()
{
}

void Player::update(float w, float h)
{
	float DEGTORAD = 0.017453f;

	if (thrust)
	{
		setDx(getDx() + cos(getAngle()*DEGTORAD)*0.2);
		setDy(getDy() + sin(getAngle()*DEGTORAD)*0.2);
	}
	else
	{
		setDx(getDx() * 0.99);
		setDy(getDy() * 0.99);
	}

	int maxSpeed = 10;

	float speed = sqrt(pow(getDx(), 2) + pow(getDy(), 2));

	if (speed > maxSpeed)
	{
		setDx(getDx() * maxSpeed / speed);
		setDy(getDy() * maxSpeed / speed);
	}

	setX(getX() + getDx());
	setY(getY() + getDy());

	if (getX() > w)
		setX(0);

	if (getX() < 0)
		setX(w);

	if (getY() > h)
		setY(0);

	if (getY() < 0)
		setY(h);
}

bool Player::getThrust()
{
	return thrust;
}

void Player::setThrust(bool t)
{
	thrust = t;
}
