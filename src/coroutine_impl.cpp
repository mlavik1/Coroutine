#include "coroutine_impl.h"

void CoroutineImpl::SetFunction(std::function<void()> function)
{
	mFunction = function;
}
