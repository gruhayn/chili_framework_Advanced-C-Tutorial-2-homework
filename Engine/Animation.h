#pragma once
#include "Drawable.h"

class Animation 
{
public:
	
	virtual ~Animation() = default;

	Drawable Do(Drawable drawable, float elapsedTime) {

		this->elapsedTime += elapsedTime * animationSpeedMultiplier;
		if (this->elapsedTime < 0) {
			this->elapsedTime = 0;
		}
		while (this->elapsedTime>duration) {
			this->elapsedTime -= duration;
		}


		Drawable dr = DoAnimation(std::move(drawable));
		return dr;
	}

protected:

	Drawable virtual DoAnimation(Drawable drawable) = 0;

	


protected:
	float duration; // duration of animation
	float animationSpeedMultiplier = 1.0f;
	float elapsedTime = 0.0f;
};
