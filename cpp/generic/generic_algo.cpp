#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

// #define DISPLAY_FUNC_MSG std::cout << __FUNCTION__ << std::endl;

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

// template <typename T>
// std::ostream &operator<<(std::ostream &cout, T t)
// {
// 	for (auto val : t)
// 	{
// 		cout << val << " ";
// 	}

// 	return cout;
// }

namespace equal
{
	void test1()
	{
		std::vector<int> vec1{1, 2};
		std::vector<int> vec2{1, 2, 3};

		std::cout << "is equal = " << std::equal(vec1.begin(), vec1.end(), vec2.begin()) << std::endl;

		vec1 = {1, 2, 3, 4};
		std::cout << "is equal = " << std::equal(vec1.begin(), vec1.end(), vec2.begin()) << std::endl;

		return;
	}

} // namespace equal

namespace copy
{
	void test1()
	{
		std::vector<int> vec1{1, 2, 3, 4, 5};
		std::vector<int> vec2(5, 0);
		auto it = std::copy(vec1.begin(), vec1.end(), vec2.begin());

		// error if vec is empty or size() less than size we want to copy from!
		// std::vector<int> vec3();
		// auto it = std::copy(vec1.begin(), vec1.end(), vec3.begin());

		std::cout << "vec1: ";
		display<std::vector<int>>(vec1);
		std::cout << "vec2: ";
		display<std::vector<int>>(vec2);

		return;
	}

	void test2()
	{
		std::vector<int> vec{1, 2, 0, 3, 0, 0, 4, 0, 5};
		std::cout << "before: ";
		display<std::vector<int>>(vec);

		std::replace(vec.begin(), vec.end(), 0, 99);
		std::cout << "after: ";
		display<std::vector<int>>(vec);

		return;
	}

	void test3()
	{
		std::vector<int> vec{1, 2, 0, 3, 0, 0, 4, 0, 5};
		std::cout << "before: ";
		display<std::vector<int>>(vec);

		std::replace_copy(vec.begin(), vec.end(), std::back_inserter(vec), 0, 99);
		std::cout << "after: ";
		display<std::vector<int>>(vec);

		return;
	}

	void test4()
	{
		std::vector<int> vec{1, 2, 0, 3, 0, 0, 4, 0, 5};
		std::cout << "before: ";
		display<std::vector<int>>(vec);

		std::replace_if(
		    vec.begin(), vec.end(), [](int x)
		    { return x % 2 != 0; },
		    99);
		std::cout << "after: ";
		display<std::vector<int>>(vec);

		return;
	}

	void test5()
	{
		std::vector<int> vec{1, 2, 0, 3, 0, 0, 4, 0, 5};
		std::cout << "before: ";
		display<std::vector<int>>(vec);

		std::replace_copy_if(
		    vec.begin(), vec.end(), std::back_inserter(vec), [](int x)
		    { return x % 2 != 0; },
		    99);
		std::cout << "after: ";
		display<std::vector<int>>(vec);

		return;
	}

	void test6()
	{
		// DISPLAY_FUNC_MSG
		std::vector<int> vec1{1, 2, 0, 3, 0, 0, 4, 0, 5};
		std::cout << "before: ";
		display<std::vector<int>>(vec1);

		std::vector<int> vec2(15, 77);
		std::replace_copy(vec1.begin(), vec1.end(), vec2.begin() /* not allowed empty and less than size */, 0, 99);
		std::cout << "after: ";
		display<std::vector<int>>(vec1);
		display<std::vector<int>>(vec2);

		return;
	}
} // namespace copy

namespace sort
{
	void test1()
	{
		std::vector<std::string> vec{"a", "c", "d", "a", "f", "d"};

		std::cout << "before: ";
		display<std::vector<std::string>>(vec);

		std::sort(vec.begin(), vec.end());
		display<std::vector<std::string>>(vec);

		auto unique_end = std::unique(vec.begin(), vec.end());
		std::cout << "size = " << std::to_string(vec.size()) << std::endl;
		vec.erase(unique_end, vec.end());
		std::cout << "after unique: ";
		display<std::vector<std::string>>(vec);
		std::cout << "size = " << std::to_string(vec.size()) << std::endl;

		return;
	}

	void test2()
	{
		std::vector<std::string> vec{"aba", "c", "de", "fa", "ac", "f", "dah", "df"};
		std::cout << "before: ";
		display<std::vector<std::string>>(vec);

		std::sort(vec.begin(), vec.end());
		auto unique_end = std::unique(vec.begin(), vec.end());
		vec.erase(unique_end, vec.end());
		std::cout << "after sort and unique: ";
		display<std::vector<std::string>>(vec);

		std::sort(vec.begin(), vec.end(), [](const std::string &s1, const std::string &s2) -> bool
			  { return s1.size() < s2.size(); });
		std::cout << "after self-sort: ";
		display<std::vector<std::string>>(vec);
	}

	void test3()
	{
		std::vector<std::string> vec{"aba", "c", "de", "fa", "ac", "f", "dah", "df"};
		std::cout << "before: ";
		display<std::vector<std::string>>(vec);

		std::stable_sort(vec.begin(), vec.end(), [](const std::string &s1, const std::string &s2) -> bool
				 { return s1.size() < s2.size(); });
		std::cout << "after stable sort: ";
		display<std::vector<std::string>>(vec);
	}

} // namespace sort

namespace find
{
	void test1()
	{
		std::vector<std::string> vec{"a", "b", "a", "c"};
		auto is_find = std::find(vec.begin(), vec.end(), "d");
		if (is_find != vec.end())
		{
			std::cout << "found num = " << *is_find << std::endl;
		}
		else
		{
			std::cout << "not found" << std::endl;
		}
	}

	void test2()
	{
		std::vector<std::string> vec{"a", "bd", "aaa", "c", "ddd"};
		auto is_find = std::find_if(vec.begin(), vec.end(), [](std::string str)
					    { return str.size() == 3; });
		if (is_find != vec.end())
		{
			std::cout << "found num = " << *is_find << std::endl;
		}
		else
		{
			std::cout << "not found" << std::endl;
		}
	}

} // namespace find

namespace insert_iterator
{
	void test1()
	{
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
		{
			*(back_inserter(vec)) = i;
		}
		display<std::vector<int>>(vec);

		return;
	}

	void test2()
	{
		std::list<int> vec;
		for (int i = 0; i < 10; i++)
		{
			*(front_inserter(vec)) = i;
		}
		display<std::list<int>>(vec);

		return;
	}

	void test3()
	{
		std::list<int> vec;
		for (int i = 0; i < 10; i++)
		{
			*(inserter(vec, vec.begin())) = i;
		}
		display<std::list<int>>(vec);

		for (int i = 0; i < 10; i++)
		{
			*(inserter(vec, vec.end())) = i;
		}
		display<std::list<int>>(vec);

		return;
	}
} // namespace insert_iterator

int main()
{
	equal::test1();
	copy::test1();
	copy::test2();
	copy::test3();
	copy::test4();
	copy::test5();
	copy::test6();

	sort::test1();
	sort::test2();
	sort::test3();

	find::test1();
	find::test2();

	insert_iterator::test1();
	insert_iterator::test2();
	insert_iterator::test3();

	return 0;
}