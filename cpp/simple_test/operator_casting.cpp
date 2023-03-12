#include <iostream>

namespace operator_casting
{
	struct ST
	{
		int num;
		ST(int num) : num(num) {}
		operator int() const { return num; }
	};

	void test1()
	{
		ST st(99);
		int val1 = int(st);
		int val2 = st;
		ST ab = 100;

		return;
	}

} // namespace operator_casting

namespace class_to_class
{
	class TEST;
	class VALUE
	{
	public:
		VALUE() {}
		explicit VALUE(TEST &t)
		{
			std::cout << "explicit VALUE(TEST& t)" << std::endl;
		}
	};

	class TEST
	{
	public:
		TEST(int num) : num_(num) {}
		int getNum() { return num_; }
		operator VALUE()
		{
			VALUE ret;
			std::cout << "operator VALUE()" << std::endl;
			return ret;
		}

	private:
		int num_;
	};

	void test1()
	{
		TEST t(100);
		VALUE v1(t);
		VALUE v2 = t;

		return;
	}
} // namespace class_to_class

int main()
{
	operator_casting::test1();
	class_to_class::test1();

	return 0;
}
