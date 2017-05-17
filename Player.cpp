#include "Player.h"

Player::Player(float _x, float _y, float _R, float _angle, Animation & a)
{
	setPower(1);
	
	setRotationMoving(false);
	setName("player");

	setX(_x);
	setY(_y);

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

	if (getMove())
		setDx((float)(getDx() + sin(getAngle()*DEGTORAD)*0.4));
	else
		setDx((float)(getDx() * 0.5));
	
	float speed = sqrt(pow(getDx(), 2));

	if (speed > maxSpeed)
		setDx(getDx() * maxSpeed / speed);

	setX(getX() + getDx());

	if (getX() + 10 > w)
		setX(w - 10);

	if (getX() - 10 < 0)
		setX(10);

	if (getY() > h)
		setY(h);

	if (getY() < 0)
		setY(0);
}

bool Player::getMove()
{
	return move;
}

void Player::setMove(bool t)
{
	move = t;
}

int Player::getPower() const
{
	return power;
}

void Player::setPower(int p)
{
	if (p <= 0)
		power = 1;
	else
		if (p > 5)
			power = 5;
		else
			power = p;
}

float Player::getSpeed()
{
	return maxSpeed;
}

void Player::setSpeed(float s)
{
	maxSpeed = s;
}
