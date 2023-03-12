#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void display(const T &t)
{
	for (auto val : t)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;

	return;
}

namespace std_vector
{
	class TE
	{
	public:
		TE(std::string name) : name_(name) { std::cout << name_ << " "
							       << "TE constructor..." << std::endl; }
		TE(const TE &te)
		{
			name_ = te.name_;
			std::cout << name_ << " "
				  << "TE copy constructor..." << std::endl;
		}

		TE(TE &&te)
		noexcept /* if no "noexecpt" key word, then vector expand size would call copy constructor for safety */
		{
			name_ = te.name_;
			std::cout << name_ << " "
				  << "TE move constructor..." << std::endl;
		}

		~TE() { std::cout << name_ << " "
				  << "TE destructor..." << std::endl; }

	private:
		std::string name_;
	};

	void test1()
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
		return;
	}

	void test2()
	{
		vector<int> ivct;

		for (int i = 0; i < 100; i++)
			ivct.push_back(i);

		cout << "ivct capacity: " << ivct.capacity() << endl;
		cout << "ivct size: " << ivct.size() << endl;
		return;
	}

	void test3()
	{
		vector<string> vec;
		vec.push_back("abc");

		cout << "vec.size = " << vec.size() << endl;

		if (vec.size() == 0)
			cout << "error" << endl;
		else
			cout << "correct" << endl;
		return;
	}

	void test4()
	{
		TE te1("A");
		std::vector<TE> vec{te1};
		return;
	}

	void test5()
	{
		std::vector<TE> vec;
		vec.push_back(std::string("A") /* infact a para, then create a lval object and thus call move */);
		vec.clear();

		TE te2("B");
		vec.push_back(te2 /* infact a rval */);
		vec.clear();

		vec.push_back(TE("C") /* infact a lval */);
		vec.clear();

		return;
	}

	void test6()
	{
		std::vector<TE> vec;
		vec.emplace_back(std::string("A") /* infact a para */);
		vec.clear();

		TE te2("B");
		vec.emplace_back(te2 /* infact a rval */);
		vec.clear();

		vec.emplace_back(TE("C") /* infact a lval */);
		vec.clear();

		return;
	}

	void test7()
	{
		auto displaySize = [](const std::vector<TE> &te)
		{
			std::cout << "capacity: " << te.capacity() << std::endl;
			std::cout << "size: " << te.size() << std::endl;

			return;
		};

		std::vector<TE> vec(10, std::string("A"));
		displaySize(vec);

		vec.emplace_back(std::string("B"));
		displaySize(vec);

		vec.emplace_back(std::string("C"));
		displaySize(vec);
	}

	void test8()
	{
		TE ta = std::string("A");
		TE tb = std::move_if_noexcept(tb);

		return;
	}
} // namespace std_vector

int main()
{
	// std_vector::test1();
	// std_vector::test2();
	// std_vector::test3();
	// std_vector::test4();
	// std_vector::test5();
	// std_vector::test6();
	std_vector::test7();
	std_vector::test8();

	return 0;
}
