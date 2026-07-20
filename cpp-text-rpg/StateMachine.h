#pragma once

#include "IState.h"

class StateMachine
{
protected:
	IState<StateMachine>* currentState;
	bool isRunning;

public:
	StateMachine(IState<StateMachine>* initState);
	virtual ~StateMachine();

	void run();
	void update();
	void changeState(IState<StateMachine>* newState);
};

