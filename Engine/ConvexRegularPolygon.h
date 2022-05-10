#pragma once

#include "GeometricObject.h"


class ConvexRegularPolygon : public GeometricObject
{
public:
	ConvexRegularPolygon() = default;
	//todo add color list for colors of edges
	ConvexRegularPolygon(Vec2<int> center, int sideCount, float radius, Color c=Colors::Blue, float rotationAngle_Radian = 0)
		:
		center(center),
		sideCount(sideCount),
		radius(radius)
	{
		Vec2<float> firstPoint = Vec2<float>{ 0, radius };
		if (rotationAngle_Radian != 0) {
			firstPoint.x = cos(-rotationAngle_Radian) * firstPoint.x - sin(-rotationAngle_Radian) * firstPoint.y;
			firstPoint.y = sin(-rotationAngle_Radian) * firstPoint.x + cos(-rotationAngle_Radian) * firstPoint.y;
		}
		
		std::vector<Edge> edges = {};
		float angle = 2.0f * 3.14159f / sideCount;

		for (int i = 0; i < sideCount; ++i)
		{
			Vec2<float> secondPoint;
			secondPoint.x = cos(-angle) * firstPoint.x - sin(-angle) * firstPoint.y;
			secondPoint.y = sin(-angle) * firstPoint.x + cos(-angle) * firstPoint.y;

			edges.emplace_back(Vec2<int>{(int)firstPoint.x, (int)firstPoint.y}, Vec2<int>{(int)secondPoint.x, (int)secondPoint.y}, c);

			firstPoint = secondPoint;
		}

		SetEdges(edges);

		TranslatePointsOfEdges(center);
		
	};

private:
	Vec2<int> center;
	int sideCount; 
	float radius;
};