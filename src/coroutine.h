#pragma once
#include <windows.h>
#include <functional>

class Coroutine
{
private:
	static void* MainFiber;
	void* mCurrentFiber;
	std::function<void()> mFunction;
	bool mIsDone = false;

private:
	static void WINAPI proc(LPVOID data);

public:
	Coroutine(std::function<void()> lambda);

	void Resume();

	void StopCoroutine();

	static void YieldCoroutine();
};
