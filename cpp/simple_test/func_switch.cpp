#include <iostream>
#include <future>
#include <memory>

void p1(int num)
{
	std::cout << num << std::endl;
}

template <class F, class... Args>
auto TEFunc(F &&f, Args &&...args)
    -> std::future<typename std::result_of<F(Args...)>::type>
{
	using return_type = typename std::result_of<F(Args...)>::type;

	auto task = std::make_shared<std::packaged_task<return_type()>>(
	    std::bind(std::forward<F>(f), std::forward<Args>(args)...));

	std::future<return_type> res = task->get_future();
	(*task)();
	return res;
}

int main()
{
	TEFunc(p1, 12);
	return 0;
}
