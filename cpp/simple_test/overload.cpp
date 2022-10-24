#include <iostream>

using namespace std;

#if 1
void p_num(int num1, int num2)
{
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
}
#endif

#if 1
void p_num(double num1, double num2)
{
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
}
#endif

#if 1
void p_num(int num1, double num2)
{
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
}
#endif

#if 1
void p_num(double num1, int num2)
{
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
}
#endif

int main()
{
	int inum1 = 12;
	int inum2 = 34;
	double dnum1 = 56.56;
	double dnum2 = 78.78;

	p_num(inum1, inum2);
	p_num(dnum1, dnum2);
	p_num(inum1, dnum1);
	p_num(dnum1, inum1);

	return 0;
}
