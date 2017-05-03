#pragma once

#include <functional>

class CoroutineImpl
{
protected:
	std::function<void()> mFunction;

public:
	virtual void SetFunction(std::function<void()> function);
	virtual void Initialise() = 0;
	virtual void ResumeCoroutine() = 0;
	virtual void YieldCoroutine() = 0;
	virtual bool IsDone() = 0;

};
