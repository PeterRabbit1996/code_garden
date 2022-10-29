#include <iostream>
#include <string>

namespace overload_operator
{
	class Box
	{
		friend Box operator+(const Box box1, const Box box2);
		friend std::ostream &operator<<(std::ostream &cout, Box box);

	private:
		size_t m_length;
		size_t m_width;
		size_t m_height;
		char *m_note = NULL;

	public:
		Box(size_t lendth, size_t width, size_t height, std::string note) : m_length(lendth), m_width(width), m_height(height)
		{
			m_note = new char[note.size() + 1];
			strncpy(m_note, note.c_str(), note.size());
		}

		Box(size_t lendth, size_t width, size_t height) : m_length(lendth), m_width(width), m_height(height) {}

		Box() : Box(0, 0, 0) {}

		bool operator==(const Box &box)
		{
			if (m_length != box.m_height ||
			    m_height != box.m_height ||
			    m_width != box.m_width)
			{
				return false;
			}

			if ((m_note == NULL && box.m_note == NULL) ||
			    (m_note != NULL && box.m_note != NULL && strncmp(m_note, box.m_note, strlen(m_note))))
			{
				return true;
			}
			else
			{
				return false;
			}

			return true;
		}

		Box &operator++()
		{
			m_length++;
			m_height++;
			m_width++;
			return *this;
		}

		Box operator++(int)
		{
			Box box = *this;
			m_length++;
			m_height++;
			m_width++;

			return box;
		}

		void operator()()
		{
			std::cout << "length = " << m_length << ", width = " << m_width << ", height = " << m_height << ", volume = " << calVol() << std::endl;
		}

		size_t calVol()
		{
			return m_length * m_width * m_height;
		}
	};

	Box operator+(const Box box1, const Box box2)
	{
		Box box;
		box.m_length = box1.m_length + box2.m_length;
		box.m_width = box1.m_width + box2.m_width;
		box.m_height = box1.m_height + box2.m_height;

		return box;
	}

	std::ostream &operator<<(std::ostream &cout, Box box)
	{
		cout << "length = " << box.m_length << ", width = " << box.m_width << ", height = " << box.m_height << ", volume = " << box.calVol();

		return cout;
	}

	template <typename T>
	class TC
	{
		friend std::ostream &operator<<(std::ostream &cout, const TC<T> &tc)
		{
			cout << tc.t_;
			return cout;
		}

	public:
		TC(T t) : t_(t) {}

	private:
		T t_;
	};

	void test1()
	{
		Box box1(2, 3, 4);
		Box box2(4, 6, 9);
		Box box3 = box1 + box2;

		std::cout << box3 << std::endl;
		std::cout << ++box3 << std::endl;
		std::cout << box3++ << std::endl;
		std::cout << box3 << std::endl;

		Box box4(9, 9, 9);
		Box box5(9, 9, 9);
		if (box4 == box5)
		{
			std::cout << box4 << std::endl;
			std::cout << box5 << std::endl;
		}

		Box box6(11, 22, 33);
		box6();
	}

	void test2()
	{
		TC<std::string> tc("Nintendo is everything!");
		std::cout << tc << std::endl;

		return;
	}
} // namespace overload_operator

int main()
{
	overload_operator::test1();
	overload_operator::test2();

	return 0;
}