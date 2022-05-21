#pragma once

#include "Edge.h"
#include <vector>

#include "CoordinateSystemSwitcher.h"
#include "Animation.h"
#include "memory"

class GeometricObject
{ 

public:
	GeometricObject() = default;

	GeometricObject(std::vector<Edge> edges, std::shared_ptr<Animation> anim=nullptr)
		:
		edges(edges),
		center(Vec2<int>{0, 0}),
		anim(anim)
	{};

	std::vector<Edge> GetEdges() {
		return edges;
	}

	Vec2<int> GetCenter()
	{
		return center;
	}

	Drawable GetDrawable(float elapsedTime) {
		Drawable drawable = Drawable(edges, center);
		if (anim != nullptr) {
			drawable = anim->Do(std::move(drawable), elapsedTime);
		}
		return drawable;
	}

	void SetAnimation(std::shared_ptr<Animation> anim) {
		this->anim = anim;
	}

	virtual ~GeometricObject() = default;
protected:
	
	void SetEdges(std::vector<Edge> in_edges) {
		edges = in_edges;
	}

protected:
	Vec2<int> center = Vec2<int>{0, 0};

private:
	std::vector<Edge> edges= {};
	std::shared_ptr<Animation> anim = nullptr; //todo shared ptr kullanimina bak 
};