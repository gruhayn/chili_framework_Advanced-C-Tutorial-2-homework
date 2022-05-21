#pragma once
#include "Animation.h"
#include "Drawable.h"

class ZoomAnimation : public Animation {
public:
	ZoomAnimation(float duration, float zoom_x_start, float zoom_x_end, float zoom_y_start, float zoom_y_end, float animationSpeedMultiplier=1.0f)
	{

		if (zoom_x_start < zoom_x_end) {
			this->zoom_x_start = zoom_x_start;
			this->zoom_x_end= zoom_x_end;
		}
		else {
			this->zoom_x_start = zoom_x_end;
			this->zoom_x_end = zoom_x_start;
		}


		if (zoom_y_start < zoom_y_end) {
			this->zoom_y_start = zoom_y_start;
			this->zoom_y_end = zoom_y_end;
		}
		else {
			this->zoom_y_start = zoom_y_end;
			this->zoom_y_end = zoom_y_start;
		}


		this->duration = duration;
		this->animationSpeedMultiplier = animationSpeedMultiplier;
	}

	Drawable virtual DoAnimation(Drawable drawable) override
	{
		float currentAnimationTime = this->elapsedTime;

		if (this->elapsedTime < duration / 2) 
		{
			//returning path of animation
			currentAnimationTime = duration - currentAnimationTime;
		}

		float zoomMultiplier = currentAnimationTime / duration;


		float zoom_x = zoom_x_end * zoomMultiplier;
		float zoom_y = zoom_y_end * zoomMultiplier;
		 
		if (zoom_x < zoom_x_start) {
			zoom_x = zoom_x_start;
		}

		if (zoom_y < zoom_y_start) {
			zoom_y = zoom_y_start;
		}

		drawable.MultiplySeperateZoomOnly(zoom_x, zoom_y);
		return drawable;
	}

private: 
	float zoom_x_start;
	float zoom_x_end;

	float zoom_y_start;
	float zoom_y_end;
};