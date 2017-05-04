#pragma once
#include <functional>

/*=============================================================================================
Coroutine class.

Create a coroutine by calling the constructor and passing a lambda.
Call Resume() to continue execution until IsDone() returns true.
If the coroutine calls YieldCoroutine(), execution will stop until Resume() is called again.
==============================================================================================*/

class CoroutineImpl;

class Coroutine
{
private:
	CoroutineImpl* mCoroutineImpl; // Coroutine implementations - depends on OS
	static CoroutineImpl* CurrentRunningCoroutine;

public:
	Coroutine(std::function<void()> lambda);

	void Resume();
	bool IsDone();

	static void YieldCoroutine();
};
