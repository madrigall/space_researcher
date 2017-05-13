#include "Entity.h"

Entity::Entity()
{
	setHealth(1);
	setDamage(1);
}

Entity::Entity(float _x, float _y, float _R, float _angle, std::string _name, Animation& a)
{
	setHealth(1);
	setDamage(1);

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

void Entity::setAnimation(Animation& a)
{
	animation = a;
}

void Entity::setBonus(int b)
{
	bonus = b;
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
	return getHealth() > 0;
}

bool Entity::getRotationMoving() const
{
	return rotation_moving;
}

int Entity::getHealth() const
{
	return health;
}

int Entity::getDamage() const
{
	return damage;
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

int Entity::getBonus() const
{
	return bonus;
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

void Entity::setHealth(int h)
{
	if (h < 0)
		health = 0;
	else
		health = h;
}

void Entity::setDamage(int d)
{
	damage = d;
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
