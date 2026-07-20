#include "IState.h"

template <typename Context_T>
IState<Context_T>::IState(Context_T* context)
	: context(context)
{
}