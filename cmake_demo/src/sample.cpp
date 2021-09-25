#include <cstdio>
#include <string>
#include "TString.h"

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	printf("max num is %s\n", stringJoint<std::string, std::string>(std::string("3"), std::string("4")));
	std::string abc = "abc";
	std::string xyz = "xyz";
	swap(abc, xyz);

	printf("abc = [%s]\n", abc.c_str());
	printf("xyz = [%s]\n", xyz.c_str());

	return 0;
}