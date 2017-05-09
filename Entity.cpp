#include "Entity.h"

Entity::Entity()
{
	live = true;
}

Entity::Entity(float _x, float _y, float _R, float _angle, std::string _name, Animation& a)
{
	x = _x;
	y = _y;

	//dx = _dx;
	//dy = _dy;

	R = _R;
	angle = _angle;

	name = _name;
	animation = a;
}

void Entity::setName(std::string _name)
{
	name = _name;
}

void Entity::setAnimation(Animation & a)
{
	animation = a;
}

Animation Entity::getAnimation() const
{
	return animation;
}

bool Entity::isLive() const
{
	return live;
}

float Entity::getX() const
{
	return x;
}

float Entity::getY() const
{
	return y;
}

float Entity::getDx() const
{
	return dx;
}

float Entity::getDy() const
{
	return dy;
}

float Entity::getR() const
{
	return R;
}

float Entity::getAngle() const
{
	return angle;
}

std::string Entity::getName() const
{
	return name;
}


Entity::~Entity()
{
}

void Entity::draw(sf::RenderWindow *win)
{
	animation.getSprite().setPosition(getX(), getY());
	animation.getSprite().setRotation(getAngle() + 90);

	win->draw(animation.getSprite());

	/*sf::CircleShape circle(R);
	circle.setFillColor(sf::Color(255, 0, 0, 170));
	circle.setPosition(x, y);
	circle.setOrigin(R, R);
	win->draw(circle);*/
}

void Entity::setLive(bool _live)
{
	live = _live;
}

void Entity::setX(float _x)
{
	x = _x;
}

void Entity::setY(float _y)
{
	y = _y;
}

void Entity::setDx(float _dx)
{
	dx = _dx;
}

void Entity::setDy(float _dy)
{
	dy = _dy;
}

void Entity::setR(float _R)
{
	R = _R;
}

void Entity::setAngle(float _angle)
{
	angle = _angle;
}
