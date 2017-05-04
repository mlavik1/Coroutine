#include <iostream>
#include "coroutine.h"
#include <intrin.h>

void doStuff(int value)
{
	std::cout << "A: " << value << std::endl;

	value++;
	Coroutine::YieldCoroutine();

	std::cout << "B: " << value << std::endl;
}

int main(int args, char argv)
{
	Coroutine coroutine1([]() {doStuff(1); });
	Coroutine coroutine2([]() {doStuff(101); });

	coroutine1.Resume();
	coroutine2.Resume();
	coroutine2.Resume();
	coroutine1.Resume();
	coroutine1.Resume(); // should do nothing

	// this is the proper way to create and use coroutines:
	Coroutine coroutine3([]() {doStuff(1001); });
	while (!coroutine3.IsDone())
	{
		coroutine3.Resume();
	}

	std::cout << "done" << std::endl;

	while (true)
	{

	}
}
