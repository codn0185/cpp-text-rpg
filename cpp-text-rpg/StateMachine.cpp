#include "StateMachine.h"

template <typename Context_T>
StateMachine<Context_T>::StateMachine(IState<Context_T>* initState) : currentState(initState), isRunning(true)
{
}

template <typename Context_T>
StateMachine<Context_T>::~StateMachine()
{
	delete currentState;
}

template <typename Context_T>
void StateMachine<Context_T>::run()
{
	while (isRunning)
	{
		update();
	}
}

template <typename Context_T>
void StateMachine<Context_T>::update()
{
	if (currentState->needInput())
	{
		currentState->handleInput(std::cin);
	}
}

template <typename Context_T>
void StateMachine<Context_T>::changeState(IState<Context_T>* newState)
{
	currentState->onExit();
	delete currentState;
	currentState = newState;
	currentState->onEnter();
}
