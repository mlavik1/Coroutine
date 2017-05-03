#include "thread_coroutine_impl.h"

void ThreadCoroutineImpl::Initialise()
{
}

void ThreadCoroutineImpl::ResumeCoroutine()
{
	mCanRun = true;
	if (!mHasStarted)
	{
		mTask = std::packaged_task<void()>([&]() { mFunction(); });
		mFuture = mTask.get_future();
		mThread = std::thread(std::move(mTask));
		mThread.detach();
		mHasStarted = true;
	}
	// wait for coroutine thread to finish, or for YieldCoroutine() to be called
	while (mCanRun && !IsDone())
	{
	}

}

void ThreadCoroutineImpl::YieldCoroutine()
{
	mCanRun = false;
	while (mCanRun == false)
	{
		_sleep(1);
	}
}

bool ThreadCoroutineImpl::IsDone()
{
	if (!mHasStarted)
		return false;
	auto status = mFuture.wait_for(std::chrono::milliseconds(0));
	return status == std::future_status::ready;
}
