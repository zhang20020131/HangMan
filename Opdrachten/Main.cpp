#include<iostream>
#include <string>
#include"Game.h"
#include "Input.h"



int main() 
{
	Game *game = new Game();
	Input* input = new Input();
	try {

		while (!game->GetIsQuitting())
		{
			game->Update();
			input->Update();
		}
	}
	catch (const std::exception* e) {
		std::cerr<<e->what()<< "\n";
	}

	game->Quit();

	
}