#pragma once
#include<vector>
#include <string>
#include <ctype.h>
#include <iostream>
#include "Time.h"

class Input
{
	static std::vector<char> buffer;
	static std::vector<char> lastSentence;
	static bool inputPause;

public:
	void Update();

	static std::string GetLastSentence() //获得最后一句
    {
		std::string sentence(lastSentence.begin(), lastSentence.end());

		inputPause = false;

		return sentence;
	}

    static bool HasCommand() { return inputPause; }


    static void PrintSentence(const char* sentence)//所需要的input
    {    
        Time::GetFormattedTimeStamp();

        std::cout << sentence << "\n";
    }

    static void PrintSentence(std::string sentence)//std里的input
    {
        PrintSentence(sentence.c_str());
    }


    static bool IsEqual(const char* left, const char* right)//检查是否是一样的Input 指令
    {
        return strcmp(left, right) == 0;
    }


    static bool IsEqual(std::string left, std::string right)//检查是否是一样的Input 输入的指令
    {
        return IsEqual(ToLower(left).c_str(), ToLower(right).c_str());
    }


    static std::string ToLower(std::string text)//检查大小写和字母；
    {
        for (size_t i = 0; i < text.size(); i++)
            text[i] = std::tolower(text[i]);

        return text;
    }


    static void ClearLastSentence()//清除最后一个句子
    {
        lastSentence.clear();
    }
};

