#include <iostream>
#include <thread>
#include <atomic>
#include <time.h>
#include <mutex>
#include <string>

std::mutex mtx;

long cnt = 0;

std::atomic_long lcnt;

void counter()
{
	for (int i = 0; i < 10000; ++i)
	{
		mtx.lock();
		++cnt;
		mtx.unlock();
	}
}

void counterAtomic()
{
	for (int i = 0; i < 10000; ++i)
	{
		++lcnt;
	}
}

void mtxTest()
{
	clock_t t1 = clock();
	std::thread tds[100];
	for (int i = 0; i < 100; i++)
	{
		tds[i] = std::thread(counter);
	}
	for (int i = 0; i < 100; i++)
	{
		tds[i].join();
	}
	std::cout << "cnt = " << std::to_string(cnt) << "res = " << std::to_string(clock() - t1) << std::endl;

	return;
}

void atcTest()
{
	clock_t t1 = clock();
	std::thread tds[100];
	for (int i = 0; i < 100; i++)
	{
		tds[i] = std::thread(counterAtomic);
	}
	for (int i = 0; i < 100; i++)
	{
		tds[i].join();
	}
	std::cout << "cnt = " << std::to_string(lcnt) << "res = " << std::to_string(clock() - t1) << std::endl;

	return;
}

int main()
{
	mtxTest();
	atcTest();

	return 0;
}
