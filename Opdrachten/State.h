#pragma once
template<class T>
class State
{
public:
	//输入状态
	virtual void Enter(T* t) {}

	//执行状态
	virtual void Execute(T* t) = 0; //这个=0 表示 在这个功能没有含义需要别的功能来进行一个输入

	// 退出状态
	virtual void Exit(T* t) {}
};

