#pragma once

#include "Edge.h"
#include <vector>

#include "CoordinateSystemSwitcher.h"

class GeometricObject
{ 

public:
	GeometricObject() = default;

	GeometricObject(std::vector<Edge> vertices)
		:
		vertices(vertices)
	{};

	void Draw(Graphics& gfx) {
		for (size_t i = 0; i < vertices.size(); i++)
		{
			gfx.DrawLine(css.ToGraphicsCoordinate<int>(vertices[i].point1), css.ToGraphicsCoordinate<int>(vertices[i].point2), vertices[i].color);
		}
	}

private:
	std::vector<Edge> vertices;
	CoordinateSystemSwitcher css = CoordinateSystemSwitcher {};
};