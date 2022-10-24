#include <iostream>

using namespace std;

void func_1()
{
	const int cinum = 11;
	const int *pcinum = &cinum;

	cout << "cinum: " << cinum << endl;
	cout << "*pcinum: " << *pcinum << endl;
}

void func_2()
{
	const int cinum = 55;
	int inum = cinum;

	cout << "cinum = " << cinum << endl;
	cout << "inum = " << inum << endl;
}

int main()
{
	func_1();
	func_2();

	return 0;
}
