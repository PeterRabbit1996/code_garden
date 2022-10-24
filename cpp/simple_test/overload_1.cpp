#include <iostream>

using namespace std;

class A
{
public:
	static void func_1(int i_num);
	static void func_1(double d_num);
};

void A::func_1(int i_num)
{
	cout << i_num << endl;
}

void A::func_1(double d_num)
{
	cout << d_num << endl;
}

int main()
{
	A::func_1(19);
	A::func_1(100.23);

	return 0;
}
