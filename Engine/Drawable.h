#pragma once

#include "Vec2.h"
#include "Edge.h"
#include <algorithm>

class Drawable
{
public:

	Drawable(std::vector<Edge> edges, Vec2<int> translation = Vec2<int>{ 0, 0 }, float zoom_x = 1.0f, float zoom_y = 1.0f)
		:
		edges(edges),
		translation(translation),
		zoom_x(zoom_x),
		zoom_y(zoom_y)
	{

	}

	void SetZoom(float in_zoom) {

		zoom_x = in_zoom;
		zoom_y = in_zoom;
		translation.x *= in_zoom;
		translation.y *= in_zoom;
	}

	void MultiplySeperateZoom(float in_zoom_x, float in_zoom_y) {

		zoom_x *= in_zoom_x;
		zoom_y *= in_zoom_y;
		translation.x *= in_zoom_x;
		translation.y *= in_zoom_y;
	}

	float GetZoomX() {
		return zoom_x;
	}

	float GetZoomY() {
		return zoom_y;
	}

	void SetTranslation(Vec2<int> in_translation) {
		translation = in_translation;
	}

	void AddTranslation(Vec2<int> in_translation) {
		translation += in_translation;
	}

	//todo bunun icini yaz
	void Render(Graphics& gfx) {
		for (auto& edge : edges) {
			gfx.DrawLine(
				Vec2<int>{(int)(edge.point1.x* zoom_x + translation.x), (int)(edge.point1.y* zoom_y + translation.y)},
				Vec2<int>{(int)(edge.point2.x* zoom_x + translation.x), (int)(edge.point2.y* zoom_y + translation.y)},
				edge.color
			);
		}
		
	}

private:
	float zoom_x;
	float zoom_y;
	Vec2<int> translation;

	//todo CoordinateSystemSwitcher'e bax
	//CoordinateSystemSwitcher& css;
	std::vector<Edge> edges;

};