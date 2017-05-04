#include "Coroutine.h"
#include "fiber_coroutine_impl.h"
#include "thread_coroutine_impl.h"

CoroutineImpl* Coroutine::CurrentRunningCoroutine = nullptr;

Coroutine::Coroutine(std::function<void()> lambda)
{

#ifdef _WIN32
	mCoroutineImpl = new FiberCoroutineImpl();
#else
	mCoroutineImpl = new ThreadCoroutineImpl();
#endif

	mCoroutineImpl->SetFunction(lambda);

	mCoroutineImpl->Initialise();
}

void Coroutine::Resume()
{
	if (!mCoroutineImpl->IsDone())
	{
		CurrentRunningCoroutine = mCoroutineImpl;
		mCoroutineImpl->ResumeCoroutine();
	}
}

bool Coroutine::IsDone()
{
	return mCoroutineImpl->IsDone();
}

// static

void Coroutine::YieldCoroutine()
{
	if (CurrentRunningCoroutine != nullptr)
	{
		CurrentRunningCoroutine->YieldCoroutine();
	}
}
