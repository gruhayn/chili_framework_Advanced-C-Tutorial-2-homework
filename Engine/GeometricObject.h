#pragma once

#include "Edge.h"
#include <vector>

#include "CoordinateSystemSwitcher.h"

class GeometricObject
{ 

public:
	GeometricObject() = default;

	GeometricObject(std::vector<Edge> edges)
		:
		edges(edges)
	{};

	void Draw(Graphics& gfx) const {
		for (size_t i = 0; i < edges.size(); i++)
		{
			gfx.DrawLine(css.ToGraphicsCoordinate<int>(edges[i].point1), css.ToGraphicsCoordinate<int>(edges[i].point2), edges[i].color);
		}
	}


protected:
	void SetEdges(std::vector<Edge> in_edges) {
		edges = in_edges;
	}

private:
	std::vector<Edge> edges;
	mutable CoordinateSystemSwitcher css = CoordinateSystemSwitcher{};
};