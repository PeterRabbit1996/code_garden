#include <iostream>
#include <vector>

using namespace std;

void func_1()
{
	vector<int> vec;
	fill_n(vec.begin(), 10, 0); // error!

}

int main()
{
	func_1();

	return 0;
}
