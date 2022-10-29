#include <iostream>
#include <map>

template <typename T>
void display(const T &t)
{
	for (auto val : t)
	{
		std::cout << val.first << ": " << val.second << std::endl;
	}

	return;
}

namespace map
{
	void test1()
	{
		std::map<std::string, int> m{
		    {"b", 20},
		    {"a", 10},
		    {"c", 30},
		};
		m["d"] = 40;
		display<std::map<std::string, int>>(m);

		try
		{
			int num = m.at("f");
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	void test2()
	{
		std::map<std::string, int> m{
		    {"a", 10},
		};
		display<std::map<std::string, int>>(m);

		auto res = m.insert({"a", 20});
		if (res.second)
		{
			printf("insert {%s, %d} done!\n", res.first->first.c_str(), res.first->second);
		}
		else
		{
			printf("insert failed\n");
		}

		return;
	}

} // namespace map

namespace multimap
{
	void test1()
	{
		std::multimap<std::string, int> m{
		    {"a", 10},
		};

		auto res = m.insert({"a", 20});
		printf("insert {%s, %d} done!\n", res->first.c_str(), res->second);

		return;
	}

	void test2()
	{
		std::multimap<std::string, int> m{
		    {"a", 10},
		    {"b", 11},
		    {"b", 12},
		    {"b", 13},
		    {"c", 14},
		    {"a", 15},
		};

		auto it = m.find("b");
		int cnt = m.count("b");
		while (cnt)
		{
			printf("{%s, %d}\n", it->first.c_str(), it->second);
			++it;
			--cnt;
		}

		return;
	}

	void test3()
	{
		std::multimap<std::string, int> m{
		    {"a", 10},
		    {"b", 11},
		    {"b", 12},
		    {"b", 13},
		    {"c", 14},
		    {"a", 15},
		};

		auto it = m.lower_bound("b");
		auto last = m.upper_bound("b");
		while (it != last)
		{
			printf("{%s, %d}\n", it->first.c_str(), it->second);
			++it;
		}

		return;
	}

	void test4()
	{
		std::multimap<std::string, int> m{
		    {"a", 10},
		    {"b", 11},
		    {"b", 12},
		    {"b", 13},
		    {"c", 14},
		    {"a", 15},
		};

		auto res = m.equal_range("b");
		while (res.first != res.second)
		{
			auto it = res.first;
			printf("{%s, %d}\n", it->first.c_str(), it->second);
			++res.first;
		}

		return;
	}
} // namespace multimap

int main()
{
	map::test1();
	map::test2();

	multimap::test1();
	multimap::test2();
	multimap::test3();
	multimap::test4();

	return 0;
}
