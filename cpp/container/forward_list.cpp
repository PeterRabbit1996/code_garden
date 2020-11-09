#include <iostream>
#include <forward_list>

using namespace std;

void func_1()
{
	forward_list<int> ifl;
	for (int i = 0; i < 10; i++)
		ifl.insert_after((ifl.before_begin()), i);

	for (auto it = ifl.begin(); it != ifl.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int main()
{
	func_1();

	return 0;
}
