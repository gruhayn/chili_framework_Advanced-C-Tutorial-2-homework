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
		edges(edges),
		center(Vec2<int>{0, 0})
	{};

	std::vector<Edge> GetEdges() {
		return edges;
	}

	Vec2<int> GetCenter()
	{
		return center;
	}

	Drawable GetDrawable() {
		return Drawable(edges, center);
	}

protected:
	
	void SetEdges(std::vector<Edge> in_edges) {
		edges = in_edges;
	}


protected:
	Vec2<int> center;
	Color c;

private:
	std::vector<Edge> edges;
};