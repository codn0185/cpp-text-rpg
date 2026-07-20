#pragma once

#include <iostream>

template <typename Context_T>
class IState
{
protected:
	Context_T* context;

public:
	IState(Context_T* context)
		: context(context)
	{
	}
	virtual ~IState() = default;

	virtual bool needInput()
	{
		return false;
	}

	virtual void handleInput(std::istream& in)
	{
	}

	virtual void onEnter() = 0;
	virtual void onExit() = 0;
};
