#pragma once

#include "Vec2.h"
#include "Colors.h"

class Edge
{
public:
	Edge() = default;
	Edge(Vec2<int> point1, Vec2<int> point2, Color color)
		:
		point1(point1),
		point2(point2),
		color(color)
	{};
public:
	Vec2<int> point1 = Vec2<int>{};
	Vec2<int> point2 = Vec2<int>{};
	Color color;
};