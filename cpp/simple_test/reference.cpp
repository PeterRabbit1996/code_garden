#include <iostream>

using namespace std;

void func_1()
{
	int inum = 55;
	const int &rinum = inum;
	const int &rval = 66;

	cout << "inum: "<< inum << endl;
	cout << "rinum: "<< rinum << endl;
	cout << "rval: "<< rval << endl;
}

void func_2()
{
	double dnum = 88.0;
	// int &rinum = dnum; // error while compling.
	const int &rinum = dnum;

	cout << "dnum: " << dnum << endl;
	cout << "rinum: " << rinum << endl;
}

void func_3()
{
	int inum = 44;
	int &rinum = inum;
	int &rrinum = rinum;

	cout << "inum: " << inum << endl;
	cout << "rinum: " << rinum << endl;
	cout << "rrinum: " << rrinum << endl;
}

int main()
{
	func_2();
	
	return 0;
}
