#include <iostream>
#include <vector>

using namespace std;

void func_1()
{
	int iarr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> ivct(begin(iarr), end(iarr));

	for (auto num : ivct)
		cout << num << " ";
	cout << endl;

	for (auto rit = ivct.rbegin(); rit != ivct.rend(); rit++)
		cout << *rit << " ";
	cout << endl;

	for (decltype(ivct.size()) i = 0; i < ivct.size(); i++)
		ivct.at(i) *= ivct.at(i); // function at() return the reference of vector.

	for (auto num : ivct)
		cout << num << " ";
	cout << endl;
}

void func_2()
{
	vector<int> ivct;

	for (int i = 0; i < 100; i++)
		ivct.push_back(i);

	cout << "ivct capacity: " << ivct.capacity() << endl;
	cout << "ivct size: " << ivct.size() << endl;
}

int main()
{
	func_1();
	func_2();

	return 0;
}
