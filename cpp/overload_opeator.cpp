#include <iostream>

class Box
{
	friend Box operator+(const Box box1, const Box box2);
private:
	size_t m_length;
	size_t m_width;
	size_t m_height;

public:
	Box(size_t lendth, size_t width, size_t height): m_length(lendth), m_width(width), m_height(height) {}
	Box(): Box(0, 0, 0) {}

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

int main()
{
	Box box1(2, 3, 4);
	Box box2(4, 6, 9);
	Box box = box1 + box2;

	printf("box volume is [%zu]\n", box.calVol());

	return 0;
}