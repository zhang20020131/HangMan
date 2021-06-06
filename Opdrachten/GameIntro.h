#pragma once
#include "State.h"
#include "Game.h"

class GameIntro :
	public State<Game>
{
	void Enter(Game* game) override;
	void Execute(Game* game) override;
	void Exit(Game* game) override;

};

