/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

#include "Edge.h" 
#include "GeometricObject.h"
#include "Star.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	css(gfx),
	cam(css)
{
	ConvexRegularPolygon go1 = ConvexRegularPolygon{ Vec2<int>{0,0},3, 100, Colors::Blue, 3.14159f / 4 };
	ConvexRegularPolygon go2 = ConvexRegularPolygon{ Vec2<int>{200,100},6, 100, Colors::Yellow, 3.14159f / 4 };

	Star s = Star{ Vec2<int>{0,100},5, 10, 100, Colors::Blue, 3.14159f/4 };

	objects.push_back(go1);
	objects.push_back(go2);
	objects.push_back(s);

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	int speed = 20;
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		cam.MoveUp(speed);
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		cam.MoveUp(-speed);
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		cam.MoveRight(-speed);
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		cam.MoveRight(speed);
	}

	if (!wnd.mouse.IsEmpty()) {
		if (wnd.mouse.LeftIsPressed()) {
			cam.MultiplyZoom(1.05f);
		}
		else if (wnd.mouse.RightIsPressed()) {
			cam.MultiplyZoom(0.95f);
		}
	}
	
}

void Game::ComposeFrame()
{
	for (auto& o : objects) {
		cam.Draw(o.GetDrawable());
	}
}
