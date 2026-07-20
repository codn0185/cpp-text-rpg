#pragma once

#include "IState.h"

class StateMachine
{
protected:
	IState<StateMachine>* currentState;
	bool isRunning;

public:
	StateMachine(IState<StateMachine>* initState);
	virtual ~StateMachine() = 0;

	void run();
	void update();
	void changeState(IState<StateMachine>* newState);
};

