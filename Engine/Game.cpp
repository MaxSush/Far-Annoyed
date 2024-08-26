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
	ball(Vec2(416.0f,470.0f), Vec2(-300.0f, -300.0f)),
	wall(0.0f,0.0f,gfx.ScreenWidth, gfx.ScreenHeight),
	pad(Vec2(400,500), 50,10),
	soundpad(L"Sounds\\arkpad.wav")
{
	Color brickColor[5] = { Colors::Blue, Colors::Cyan, Colors::Green, Colors::Gray, Colors::Red };
	Vec2 top_left(20.0f, 20.0f);
	for (int x = 0; x < nBrickAcross; x++) {
		for (int y = 0; y < nBrickDown; y++) {
			const Color c = brickColor[y];
			brick.emplace_back(Brick(RectF(top_left + Vec2(x * brickWidth, y * brickHeigth), brickWidth, brickHeigth), c));
		}
	}
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

	pad.Update(wnd.kbd, dt);
	pad.doWallCollision(wall);

	ball.Update(dt);

	bool collisionHappened = false;
	float curColDistSq = 0.0f;
	int curColIndex;
	for (int i = 0; i < totalBrick; i++)
	{
		if (brick[i].checkBallCollision(ball))
		{
			const float newColDistSq = (ball.getCenter() - brick[i].GetCenter()).GetLengthSq();
			if (collisionHappened)
			{
				if (newColDistSq < curColDistSq)
				{
					curColDistSq = newColDistSq;
					curColIndex = i;
				}
			}
			else
			{
				curColDistSq = newColDistSq;
				curColIndex = i;
				collisionHappened = true;
			}
		}
	}

	if (collisionHappened)
	{
		brick[curColIndex].ExecuteBallCollision(ball);
		ball.Update(dt);
	}

	if (pad.doBallCollision(ball)) {
		soundpad.Play();
	}

	ball.doWallColision(wall);
}

void Game::ComposeFrame()
{
	for (const auto& b : brick) {
		b.Draw(gfx);
	}
	ball.Draw(gfx);
	pad.Draw(gfx);
}
