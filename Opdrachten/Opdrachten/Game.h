#pragma once
#include "StateMachine.h"
enum class GameStateEnum
{
	GAMESTATE_INTRO,
	GAMESTATE_OUTRO
};


class GameState;
class Game
{
private:
	bool isQuitting;
	StateMachine<Game>* stateMachine;
	
public:

	Game();

	bool GetIsQuitting() { return isQuitting; }


	const StateMachine<Game>* GetStateMachine() { return stateMachine; };
	void Update();
	void Quit();

};

