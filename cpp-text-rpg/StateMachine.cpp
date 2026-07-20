#include "StateMachine.h"

StateMachine::StateMachine(IState<StateMachine>* initState) : currentState(initState), isRunning(true)
{
}

StateMachine::~StateMachine()
{
	delete currentState;
}

void StateMachine::run()
{
	while (isRunning)
	{
		update();
	}
}

void StateMachine::update()
{
	if (currentState->needInput())
	{
		currentState->handleInput(std::cin);
	}
}

void StateMachine::changeState(IState<StateMachine>* newState)
{
	currentState->onExit();
	delete currentState;
	currentState = newState;
	currentState->onEnter();
}
