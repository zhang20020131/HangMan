#include "Input.h"
#include <conio.h>
#include <iostream>

bool Input::inputPause = false;

std::vector<char> Input::buffer;
std::vector<char> Input::lastSentence;

void Input::Update()
{
	if (!_kbhit() && inputPause) //是否有Input 没有就返回
		return;

	char c = (char)_getch();


	if (c == '\r' || c == '\n')
	{

		buffer.push_back('\0');

		std::copy(buffer.begin(), buffer.end(),
			std::back_inserter(lastSentence));
		buffer.clear();

		inputPause = true;

		std::cout << "\r\n";
	}
	else
	{
		buffer.push_back(c);
		std::cout << c;
	}


}
