#pragma once

class StateMachine
{
protected:
	bool _isRunning;

public:
	StateMachine();
	virtual ~StateMachine();

	virtual void run();
	virtual void update();
};

