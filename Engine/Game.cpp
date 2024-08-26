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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brick( RectF(500.0f,500.0f,800.0f,600.0f) ,Colors::Blue ),
	ball(Vec2(400.0f,300.0f), Vec2(200.0f, 200.0f)),
	wall(0.0f,0.0f,gfx.ScreenWidth, gfx.ScreenHeight),
	paddel(Vec2(400,500), 50,15)
{
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
	const float dt = ft.Mark();
	brick.doBallCollision(ball);
	ball.Update(dt);
	ball.doWallColision(wall);
	// ballupdate();
	
	paddel.Update(wnd.kbd);
	paddel.doWallCollision(wall);
	paddel.doBallCollision(ball);
}

void Game::ballupdate()
{
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		ball.getCenter().x -= 3;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		ball.getCenter().x += 3;
	}	
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		ball.getCenter().y -= 3;
	}	
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		ball.getCenter().y += 3;
	}
}

void Game::ComposeFrame()
{
	brick.Draw(gfx);
	ball.Draw(gfx);
	paddel.Draw(gfx);
}
