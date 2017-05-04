#ifdef _WIN32
#pragma once

#include "coroutine_impl.h"
#include <Windows.h>

/*=============================================================================================
Coroutine implementation, using Windows Fiber API.

This can only be used on Windows.
==============================================================================================*/

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
#endif
