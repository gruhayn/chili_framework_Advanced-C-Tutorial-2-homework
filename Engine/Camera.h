#pragma once
#include "CoordinateSystemSwitcher.h"
#include "Drawable.h"

class Camera
{
public:
	Camera(CoordinateSystemSwitcher& css) :
		css(css)
	{}

	void MoveUp(int step) {
		center.y -= step;
	}

	void MoveRight(int step) {
		center.x -= step;
	}

	void Draw(Drawable& drawable) {
		drawable.AddTranslation(center);

		drawable.MultiplySeperateZoom(zoom,zoom);
		css.Draw(drawable);
	}

	float GetZoom() {
		return zoom;
	}

	void MultiplyZoom(float multiplier) {
		zoom *= multiplier;
	}

private:
	float zoom = 1.0f;
	Vec2<int> center = Vec2<int>{ 0,0 };
	CoordinateSystemSwitcher& css;
};