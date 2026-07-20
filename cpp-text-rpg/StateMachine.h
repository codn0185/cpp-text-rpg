#pragma once

#include "IState.h"

template <typename Context_T>
class StateMachine
{
protected:
	IState<Context_T>* currentState;
	bool isRunning;

public:
	StateMachine(IState<Context_T>* initState);
	virtual ~StateMachine();

	void run();
	void update();
	void changeState(IState<Context_T>* newState);
};

