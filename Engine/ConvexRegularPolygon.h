#pragma once

#include "GeometricObject.h"


class ConvexRegularPolygon : public GeometricObject
{
public:
	ConvexRegularPolygon() = default;
	//todo add color list for colors of edges
	ConvexRegularPolygon(Vec2<int> center, int sideCount, float radius, Color c=Colors::Blue, float rotationAngle_Radian = 0)
		:
		sideCount(sideCount),
		radius(radius)
	{
		std::vector<Vec2<float>> points;
		points.reserve(sideCount);
		const float dTheta = 2.0f * 3.14159f / float(sideCount );

		for (int i = 0; i < sideCount; ++i) {
			
			points.emplace_back(
				Vec2<float>{
					radius* cos((float)i* dTheta + rotationAngle_Radian),
					radius* sin((float)i* dTheta + rotationAngle_Radian)
				}
			);
		}

		std::vector<Edge> edges = {};
		for (int i = 0; i < sideCount - 1; ++i) {
			edges.emplace_back(Vec2<int>{(int)points[i].x, (int)points[i].y}, Vec2<int>{(int)points[i + 1].x, (int)points[i + 1].y}, c);
		}

		edges.emplace_back(Vec2<int>{(int)points.front().x, (int)points.front().y}, Vec2<int>{(int)points.back().x, (int)points.back().y}, c);

		SetEdges(edges);
		this->center = center;
		this->c = c;
	};

private:
	int sideCount; 
	float radius;
};