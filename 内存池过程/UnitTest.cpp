#include "Common.h"
#include "ConcurrentAlloc.h"

void Alloc(size_t n)
{
	std::vector<void*> v;
 	for (size_t i = 0; i < n; ++i)
	{
		v.push_back(ConcurrentAlloc(10));
	}

	for (size_t i = 0; i < n; ++i)
	{
		ConcurrentFree(v[i], 10);
		cout << v[i] << endl;
	}
	v.clear();

	cout << endl << endl;
	for (size_t i = 0; i < n; ++i)
	{
		v.push_back(ConcurrentAlloc(10));
	}

	for (size_t i = 0; i < n; ++i)
	{
		ConcurrentFree(v[i], 10);
		cout << v[i] << endl;
	}
	v.clear();
}

void TestThreadCache()
{
	std::thread t1(Alloc, 5);
	//std::thread t2(Alloc, 5);
	//std::thread t3(Alloc, 5);
	//std::thread t4(Alloc, 5);

	t1.join();
	//t2.join();
	//t3.join();
	//t4.join();
}

void TestCentralCache()
{
	std::vector<void*> v;
	for (size_t i = 0; i < 8; ++i)
	{
		v.push_back(ConcurrentAlloc(10));
	}

	for (size_t i = 0; i < 8; ++i)
	{
		cout << v[i] << endl;
	}
}

int main()
{
	//TestThreadCache();
	//TestCentralCache();

	system("pause");
	return 0;
}