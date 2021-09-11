#include <iostream>

class people
{
public:
	people() {}
	people(int x) : score(x) {}
	~people() {}
	int getScore() const { return score; }

private:
	int score;
};

int main()
{
	const people p1(22);
	std::cout << p1.getScore() << std::endl; //error
	system("pause");
	return 0;
}