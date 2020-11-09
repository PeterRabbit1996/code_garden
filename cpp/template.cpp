#include <iostream>

using namespace std;

template<typename T> void Swap(T *a, T *b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	//交换 int 变量的值
	int n1 = 100, n2 = 200;
	cout<<n1<<", "<<n2<<endl;
	Swap(&n1, &n2);
	cout<<n1<<", "<<n2<<endl;
   
	//交换 float 变量的值
	float f1 = 12.5, f2 = 56.93;
	cout<<f1<<", "<<f2<<endl;
	Swap(&f1, &f2);
	cout<<f1<<", "<<f2<<endl;
   
	//交换 char 变量的值
	char c1 = 'A', c2 = 'B';
	cout<<c1<<", "<<c2<<endl;
	Swap(&c1, &c2);
	cout<<c1<<", "<<c2<<endl;
   
	//交换 bool 变量的值
	bool b1 = false, b2 = true;
	cout<<b1<<", "<<b2<<endl;
	Swap(&b1, &b2);
	cout<<b1<<", "<<b2<<endl;

	return 0;
}
