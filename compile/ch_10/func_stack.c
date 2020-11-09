struct large_var {
	char buff[128];
};

struct large_var func()
{
	struct large_var l_v;

	return l_v;
}

int main()
{
	struct large_var l_v = func();

	return 0;
}
