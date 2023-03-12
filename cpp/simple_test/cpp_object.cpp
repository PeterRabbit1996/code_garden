class Base
{
public:
	// Base() {}
	// Base(const Base &base) {}
	// Base(const Base &&base) {}
};

class Derive1 : public Base
{
};

class Derive2 : public Base
{
};

// class TE
// {
// public:
// 	TE() {}
// 	Base base;
// };

// Base *createObj(int val)
// {
// 	switch (val)
// 	{
// 	case 1:
// 		return new Derive1();
// 		break;
// 	case 2:
// 		return new Derive2();
// 		break;

// 	default:
// 		break;
// 	}
// }

int main()
{
	// Base te;
	Derive1 d1;
	return 0;
}