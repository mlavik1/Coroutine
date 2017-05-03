#include "fiber_coroutine_impl.h"

void* FiberCoroutineImpl::MainFiber = nullptr;

void WINAPI FiberCoroutineImpl::proc(LPVOID data)
{
	FiberCoroutineImpl* coroutine = reinterpret_cast<FiberCoroutineImpl*>(data);
	coroutine->mFunction();
	coroutine->mIsDone = true;
	coroutine->YieldCoroutine();
}

void FiberCoroutineImpl::Initialise()
{
	if (MainFiber == nullptr)
	{
		MainFiber = ConvertThreadToFiber(NULL);
	}

	mCurrentFiber = CreateFiber(0, &proc, this);
}

void FiberCoroutineImpl::ResumeCoroutine()
{
	SwitchToFiber(mCurrentFiber);
}

void FiberCoroutineImpl::YieldCoroutine()
{
	SwitchToFiber(MainFiber);
}

bool FiberCoroutineImpl::IsDone()
{
	return mIsDone;
}
