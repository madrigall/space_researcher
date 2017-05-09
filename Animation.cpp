#include "Animation.h"

Animation::Animation()
{
}

Animation::~Animation()
{
}


Animation::Animation(sf::Texture & t, int x, int y, int w, int h, int count, float _speed)
{
	currentFrame = 0;
	speed = _speed;

	for (int i = 0; i < count; ++i)
		frames.push_back(sf::IntRect(x + i*w, y, w, h));

	sprite.setTexture(t);
	sprite.setOrigin(w / 2, h / 2);

	sprite.setTextureRect(frames[0]);
}

void Animation::update()
{
	currentFrame += speed;

	int n = frames.size();

	if (currentFrame >= n) 
		currentFrame -= n;

	if (n > 0) 
		sprite.setTextureRect(frames[int(currentFrame)]);
}

bool Animation::isEnd()
{
	return (currentFrame + speed >= frames.size());
}

sf::Sprite& Animation::getSprite()
{
	return sprite;
}
