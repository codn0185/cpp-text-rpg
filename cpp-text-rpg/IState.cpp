#include "IState.h"

template <typename Context_T>
IState<Context_T>::IState(Context_T* context)
	: context(context)
{
}

template <typename Context_T>
bool IState<Context_T>::needInput()
{
	return true;
}
