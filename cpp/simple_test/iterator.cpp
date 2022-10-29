#include <iostream>
#include <vector>

using namespace std;

class Pixel
{
private:
	unsigned short x;
	unsigned short y;
	unsigned short val;
};

void func_1()
{
	string str = "hello world!";
	// for (string::iterator it = str.begin(); it != str.end(); it++)
	for (auto it = str.begin(); it != str.end(); it++)
		cout << *it;
	cout << endl;

	for (auto it = str.begin(); it != str.end(); it++)
		*it = toupper(*it);
	cout << str << endl;

	/*
	 * unlike function begin(),
	 * cbegin() returns a const variable that not allowed to be changed.
	 */
	/*
	for (auto it = str.cbegin(); it != str.cend(); it++)
		*it = toupper(*it);
	cout << str << endl;
	*/
}

void func_2()
{
	// string iterator.
	string::iterator sit;
	string::const_iterator scit;

	string str = "hello world!";
	for (sit = str.begin(); sit != str.end(); sit++)
		*sit = toupper(*sit);
	cout << str << endl;

	/*
	 * unlike iterator.
	 * const_iterator returns a const iterator that not allowed to be changed.
	 */
	/*
	for (scit = str.begin(); scit != str.end(); scit++)
		*scit = toupper(*scit);
	cout << str << endl;
	*/

	// vector iterator.
	vector<int>::iterator vit;
	vector<int>::const_iterator vcit;

	vector<int> ivec;
	for (int i = 0; i != 10; i++)
		ivec.push_back(i);
	for (vit = ivec.begin(); vit != ivec.end(); vit++)
		*vit *= *vit;
	for (vcit = ivec.begin(); vcit != ivec.end(); vcit++)
		cout << *vcit << " ";
	cout << endl;

	/*
	 * unlike iterator.
	 * const_iterator returns a const iterator that not allowed to be changed.
	 */
	/*
	for (vcit = ivec.begin(); vcit != ivec.end(); vcit++)
		*vcit *= *vcit;
	*/
}

void test1()
{
	func_1();
	return;
}

void test2()
{
	func_2();
	return;
}

void test3()
{
	
	return;
}

int main()
{
	func_1();
	func_2();

	return 0;
}
