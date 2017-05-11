#include "Entity.h"

Entity::Entity()
{
	live = true;
}

Entity::Entity(float _x, float _y, float _R, float _angle, std::string _name, Animation a)
{
	live = true;

	x = _x;
	y = _y;

	R = _R;
	angle = _angle;

	name = _name;
	animation = a;
}

void Entity::setName(std::string _name)
{
	name = _name;
}

void Entity::setAnimation(Animation a)
{
	animation = a;
}

Animation* Entity::getAnimation()
{
	return &animation;
}

bool Entity::isCollided(Entity * e_f, Entity * e_s)
{
	return	(e_s->getX() - e_f->getX())*(e_s->getX() - e_f->getX()) +
			(e_s->getY() - e_f->getY())*(e_s->getY() - e_f->getY())<
			(e_f->getR() + e_s->getR())*(e_f->getR() + e_s->getR());
}

bool Entity::isLive() const
{
	return live;
}

bool Entity::getRotationMoving() const
{
	return rotation_moving;
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

	if(getRotationMoving())
		animation.getSprite().setRotation(getAngle());

	win->draw(animation.getSprite());
}

void Entity::setLive(bool _live)
{
	live = _live;
}

void Entity::setRotationMoving(bool _rot)
{
	rotation_moving = _rot;
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
