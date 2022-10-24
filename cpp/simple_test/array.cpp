#include <iostream>

using namespace std;

void func_1()
{
	//char astr[6] = "Daniel"; // error: initializer-string for char array is too long.
	//char astr1[] = {'C', '+', '+'}; // should add '\0' at the end of the char array.
	//cout << astr1 << endl;
}

void func_2()
{
	int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (int *first = begin(ia), *last = end(ia); first != last; first++)
		cout << *first << " ";
	cout << endl;
}

void func_3()
{
	constexpr size_t rowcnt = 3;
	constexpr size_t colcnt = 4;
	int iarr[rowcnt][colcnt];
	size_t cnt = 0;

	for (auto &row: iarr)
		for (auto &col: row) {
			col = cnt;
			cnt++;
		}

	for (auto &row: iarr) {
		for (auto &col: row) {
			cout << col << " ";
		}
		cout << endl;
	}
}

int main()
{
	func_1();
	func_2();
	func_3();

	return 0;
}
