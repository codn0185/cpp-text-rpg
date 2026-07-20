#pragma once

#include "IState.h"

template <typename Context_T>
class IStateMachine
{
protected:
	IState<Context_T>* currentState;
	bool isRunning;

public:
	IStateMachine(IState<Context_T>* initState)
		: currentState(initState), isRunning(true)
	{
		currentState->onEnter();
	}

	virtual ~IStateMachine()
	{
		delete currentState;
	}

	void run()
	{
		while (isRunning)
		{
			update();
		}
	}

	void update()
	{
		if (currentState->needInput())
		{
			currentState->handleInput(std::cin);
		}
	}

	void changeState(IState<Context_T>* newState)
	{
		currentState->onExit();
		delete currentState;
		currentState = newState;
		currentState->onEnter();
	}
};

