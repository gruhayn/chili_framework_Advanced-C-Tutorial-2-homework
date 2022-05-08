#pragma once

#include "Graphics.h"
#include "Vec2.h"


class CoordinateSystemSwitcher
{
public:
	template<typename T>
	Vec2<T> ToGraphicsCoordinate(Vec2<T> coordinate)
	{
		return screenCenterCoordinate + Vec2<T>{coordinate.x, -coordinate.y};
	}

	template<typename T>
	Vec2<T> ToMathCoordinate(Vec2<T> coordinate)
	{
		return Vec2<T>{coordinate.x - screenCenterCoordinate.x , screenCenterCoordinate.y - coordinate.y};
	}

private:
	static constexpr int screenWidth = Graphics::ScreenWidth;
	static constexpr int screenHeight = Graphics::ScreenHeight;
	Vec2<int> screenCenterCoordinate{ (int)screenWidth / 2, (int)screenHeight / 2 };


};