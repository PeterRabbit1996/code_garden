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

void func_3()
{
	vector<string> vec;
	vec.push_back("abc");

	cout << "vec.size = " << vec.size() << endl;

	if (vec.size() == 0)
		cout << "error" << endl;
	else
		cout << "correct" << endl;
}

int main()
{
	func_3();

	return 0;
}
