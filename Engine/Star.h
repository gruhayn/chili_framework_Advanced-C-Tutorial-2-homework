#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#include "ConvexRegularPolygon.h"
#include <algorithm>
#include <iostream>

class Star : public GeometricObject
{
public:
	Star() = default;
	//todo add color list for colors of edges
	Star(Vec2<int> center, int flareCount, float innerRadius, float outerRadius, Color c = Colors::Blue, float rotationAngle_Radian = 0)
		:
		flareCount(flareCount),
		innerRadius(innerRadius),
		outerRadius(outerRadius)
	{
		
		std::vector<Vec2<float>> points;
		points.reserve(flareCount * 2);
		const float dTheta = 2.0f * 3.14159f / float(flareCount * 2);

		for (int i = 0; i < 2*flareCount; ++i) {
			const float rad = (i % 2 == 0) ? outerRadius : innerRadius;
			points.emplace_back(
				Vec2<float>{
					rad * cos((float)i * dTheta + rotationAngle_Radian),
					rad * sin((float)i * dTheta + rotationAngle_Radian)
				}
			);
		}

		std::vector<Edge> edges = {};
		for (int i = 0; i < 2 * flareCount - 1; ++i) {
			edges.emplace_back(Vec2<int>{(int)points[i].x, (int)points[i].y}, Vec2<int>{(int)points[i+1].x, (int)points[i+1].y}, c);
		}

		edges.emplace_back(Vec2<int>{(int)points.front().x, (int)points.front().y}, Vec2<int>{(int)points.back().x, (int)points.back().y}, c);

		SetEdges(edges);
		this->center = center;
		this->c = c;
	}

private:
	int flareCount;
	float innerRadius;
	float outerRadius;

};