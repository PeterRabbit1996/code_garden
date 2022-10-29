#include <iostream>

template <typename T>
void swap(T &t1, T &t2)
{
	T temp = std::move(t1);
	t1 = std::move(t2);
	t2 = std::move(temp);
}