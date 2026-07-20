#include "IStateMachine.h"

template <typename Context_T>
IStateMachine<Context_T>::IStateMachine(IState<Context_T>* initState) : currentState(initState), isRunning(true)
{
}

template <typename Context_T>
IStateMachine<Context_T>::~IStateMachine()
{
	delete currentState;
}

template <typename Context_T>
void IStateMachine<Context_T>::run()
{
	while (isRunning)
	{
		update();
	}
}

template <typename Context_T>
void IStateMachine<Context_T>::update()
{
	if (currentState->needInput())
	{
		currentState->handleInput(std::cin);
	}
}

template <typename Context_T>
void IStateMachine<Context_T>::changeState(IState<Context_T>* newState)
{
	currentState->onExit();
	delete currentState;
	currentState = newState;
	currentState->onEnter();
}
