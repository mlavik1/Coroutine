#pragma once

/*=============================================================================================
Coroutine implementation, using std::thread

This is not a very good implementation, but it's cross-platform and works as a fallback for
 unhandled OS'es.
Coroutines will run in their own thread. We will make sure the main thread and coroutine thread
 are synchronised, so everything done in a coroutine is thread-safe.
This is NOT a multithreaded implementation. Only one thread will run at a time.
==============================================================================================*/

#include "coroutine_impl.h"
#include <future>
#include <thread>
#include <atomic>

class ThreadCoroutineImpl : public CoroutineImpl
{
private:
	std::packaged_task<void()> mTask;
	std::future<void> mFuture;
	std::thread mThread;
	bool mHasStarted = false;
	std::atomic<bool> mCanRun; // TODO: use mutexes, or something else

public:
	void Initialise();
	void ResumeCoroutine();
	void YieldCoroutine();
	bool IsDone();
};
