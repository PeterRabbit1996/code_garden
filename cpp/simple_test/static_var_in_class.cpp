#include <iostream>

using namespace std;

class TestClass
{
public:
	static int num;

};

int TestClass::num = 0;

int main()
{
	TestClass::num = 100;
	TestClass::num = 101;

	return 0;
}
