#include <iostream>

using namespace std;

class Test
{
	public:
		static int cnt;
		int num;
	public:
		void display() {cout << "cnt = " << cnt << endl;}
		static void say() {cout << "cnt = " << cnt << endl;}
};

int Test::cnt = 0;

int main()
{
	Test::cnt = 11;
	Test::say();

	Test test;
	test.cnt = 22;
	test.display();
	test.say();

	return 0;
}
