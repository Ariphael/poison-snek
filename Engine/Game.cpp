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
#include "Location.h"
#include <iostream>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( 2 ),
	snek( brd ),
	counter( 0 ),
	bounds(Location(5,5),Location(55,55)),
	apple(brd),
	poison(brd),
	EatS(L"Bite.wav"),
	DeathS(L"death.wav")
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
	float dt = ct.Mark();
	counter += dt;
	PoisonCounter += dt;
	if (!snek.CheckGameOver(bounds,poison)) {
		snek.DrawSnake(gfx);
		bounds.DrawBorder(brd, gfx);
		apple.DrawFood(gfx, poison);
		poison.DrawPoison(gfx);
	}
	else {
		if (GameOverSound == false) {
			DeathS.Play();
			GameOverSound = true;
		}
		brd.DrawGameOver(350, 250, gfx);
	}
}

void Game::ComposeFrame()
{
	if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
		speed = 0.05;
	}
	else {
		speed = 0.1;
	}
	if(!snek.CheckGameOver(bounds, poison)){
		if (PoisonCounter > PoisonMax) {
			poison.GenPoison(snek, apple);
			PoisonCounter = 0;
			a++;
		}
		if (a >= 3) {
			std::cout << "debug\n";
		}
		snek.Manage(wnd.kbd);
		if (counter > speed) {
			snek.Update(apple, poison, EatS);
			counter = 0;
		}
	}
}
