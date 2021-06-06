#include "Game.h"
#include "Input.h"
#include<iostream>
#include "GameIntro.h"
#include"StateLOL.h"

Game::Game()
{
	isQuitting = false;
	stateMachine = new StateMachine<Game>(this);
	stateMachine->SwitchState(new GameIntro());
}

void Game::Update()
{
	if (!Input::HasCommand())
		return;

	std::string sentence = Input::GetLastSentence();//获得最后一句话


	if (Input::IsEqual("quit", sentence))//所需要的指令指令是quit
	{
		isQuitting = true;

		return;
	}

	if (Input::IsEqual("operation", sentence))//所需要的指令指令是quit
	{
		Input::ClearLastSentence();//清除最后一句话
		stateMachine->SwitchState(new StateLOL());
		return;
	}
	


	//插入状况系统
	stateMachine->Update();

	Input::ClearLastSentence();
}

void Game::Quit()//退出游戏
{
	Input::PrintSentence(std::string("Quitting. \r\n"));
	system("pause");
}
