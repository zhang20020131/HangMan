#pragma once
#include"State.h"
#include <iostream>


template<class T>
class StateMachine
{
	// 当前状态
	State<T>* currentState;
	// 之前状态
	State<T>* previousState;
	// 该状态机的所有者
	T* owner;


public:
	// 构造函数
	StateMachine(T* owner)
	{
		if (owner == nullptr)
		{
			this->~StateMachine();
			throw std::exception(
				"Owner of this StateMachine is null");
		}
		else
		{
			this->owner = owner;
		}
	}



	void Update()
	{
		//检查我们当前的状态是否有效
	    //执行当前状态
		if (currentState != nullptr)
			currentState->Execute(owner);
	}

	//获得状态
	State<T> GetState()
	{
		// 返回现在的状态
		return currentState;
	}

	// 切换状态
	void SwitchState(State<T>* newState)
	{
		//检查变量newState是否设置正确
		if (newState == nullptr || currentState == newState)
			return;

		//退出之前的状态
		if (previousState != nullptr) //要是之前的状态指针不等于空指针那么久退出
			previousState->Exit(owner);

		//将先前状态设置为当前状态
		previousState = currentState;

		//将当前状态设置为新状态
		currentState = newState;

		//进入新状态
		currentState->Enter(owner);
	}

	//切换到上一个状态
	void SwitchToPreviousState()
	{
		if (previousState == nullptr)//要是之前的的状态等于空指针那么久返回
			return;

		SwitchState(previousState);//切换到上一个状态
	}
};

