#include "Coroutine.h"

void* Coroutine::MainFiber = nullptr;

Coroutine::Coroutine(std::function<void()> lambda)
{
	mFunction = lambda;

	if (MainFiber == nullptr)
	{
		MainFiber = ConvertThreadToFiber(NULL);
	}

	mCurrentFiber = CreateFiber(0, &proc, this);
}

void Coroutine::Resume()
{
	if (!mIsDone)
	{
		SwitchToFiber(mCurrentFiber);
	}
}

void Coroutine::StopCoroutine()
{
	mIsDone = true;
	YieldCoroutine();
}


// static

void Coroutine::YieldCoroutine()
{
	SwitchToFiber(MainFiber);
}

void WINAPI Coroutine::proc(LPVOID data)
{
	Coroutine* coroutine = reinterpret_cast<Coroutine*>(data);
	coroutine->mFunction();
	coroutine->mIsDone = true;
	coroutine->YieldCoroutine();
}
