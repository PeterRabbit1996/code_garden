#include <iostream>

using namespace std;

int main()
{
	string sstr = "hello world!";
	//char *cstr = sstr; // error.
	//char *cstr = sstr.c_str(); // error, must be const.
	const char *cstr = sstr.c_str(); // cstr is not allowed to be changed, and it may be out of use if changed.

	cout << sstr << endl;
	cout << cstr << endl;

	return 0;
}
