#include <iostream>

using namespace std;

int main()
{
	string str = "hello world!";
	for (auto c: str)
		cout << c;
	cout << endl;

	for (auto &c: str)
		c = toupper(c);
	cout << str << endl;

	return 0;
}
