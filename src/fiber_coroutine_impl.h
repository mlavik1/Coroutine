#pragma once

#include "coroutine_impl.h"
#include <Windows.h>

class FiberCoroutineImpl : public CoroutineImpl
{
private:
	static void* MainFiber;
	void* mCurrentFiber;
	bool mIsDone;

private:
	static void WINAPI proc(LPVOID data);

public:
	void Initialise();
	void ResumeCoroutine();
	void YieldCoroutine();
	bool IsDone();
};
