#pragma once

#include "Vec2.h"
#include "Colors.h"

class Edge
{
public:
	Edge() = default;

public:
	Vec2<int> point1 = Vec2<int>{};
	Vec2<int> point2 = Vec2<int>{};
	Color color;
};