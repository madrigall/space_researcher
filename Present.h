#pragma once
#include "Entity.h"

class Present :	public Entity
{
	public:
		Present(float _x, float _y, float _R, float _angle, Animation& a);
		~Present();

		void update(float w, float h);
		int getPresent() const;
};

