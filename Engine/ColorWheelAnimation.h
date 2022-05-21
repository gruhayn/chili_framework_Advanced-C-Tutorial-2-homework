#pragma once

#include "Animation.h"

class ColorWheelAnimation : public Animation
{

public:
	//duration (0,1)
	ColorWheelAnimation(float duration, float animationSpeedMultiplier = 1.0f) {
		this->duration = 1/duration;
		this->animationSpeedMultiplier = animationSpeedMultiplier;
	}

	Drawable virtual DoAnimation(Drawable drawable) override
	{
		float currentAnimationTime = this->elapsedTime;
		
		int edgeCount = drawable.GetEdgeCount();

		int stepCount = (int)(duration / edgeCount * currentAnimationTime);
		drawable.TurnColorWheel(stepCount);
		
		return drawable;
	}

};
