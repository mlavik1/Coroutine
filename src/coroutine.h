#pragma once
#include <functional>

class CoroutineImpl;

class Coroutine
{
private:
	CoroutineImpl* mCoroutineImpl;
	static CoroutineImpl* CurrentRunningCoroutine;

public:
	Coroutine(std::function<void()> lambda);

	void Resume();

	void StopCoroutine();

	static void YieldCoroutine();
};
