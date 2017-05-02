#include <iostream>
#include "coroutine.h"

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

	std::cout << "done" << std::endl;

	while (true)
	{

	}
}
