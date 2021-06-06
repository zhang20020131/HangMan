#include "GameIntro.h"
#include "Input.h"
void GameIntro::Enter(Game* game)
{
	Input::PrintSentence(std::string("Shit Game. \r\n"));
	Input::PrintSentence(std::string("Quit Game? type quit. \r\n"));
	Input::PrintSentence(std::string("Want to know the operation,type operation. \r\n"));
}

void GameIntro::Execute(Game* game)
{
}

void GameIntro::Exit(Game* game)
{
}
