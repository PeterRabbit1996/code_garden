/* std::enable_shared_from_this 是一个模板类，定义在头文件<memory> 中，它为一个类模板提供了一个成员函数 shared_from_this()，该函数返回一个指向自身的 std::shared_ptr。使用 std::enable_shared_from_this，可以让类的实例被多个 std::shared_ptr 共享，避免出现悬空指针或者内存泄漏的问题。

使用 std::enable_shared_from_this 的主要原因是可以在一个类的成员函数中获取到一个指向该类对象的 std::shared_ptr，而不必将该指针作为参数传递到函数中。

例如，当一个类的成员函数需要将该对象的智能指针传递给其他函数或者对象时，我们通常会将该指针作为参数传递。这样做的问题是，如果有人在没有使用智能指针的情况下创建了该对象的实例，那么就无法保证在成员函数中获取到的指针是有效的。

使用 std::enable_shared_from_this 可以避免这个问题，因为该类中定义了一个 shared_from_this() 函数，可以返回一个指向该类对象的 std::shared_ptr。由于 shared_from_this() 函数内部使用了一个内部的 weak_ptr，可以确保即使没有使用智能指针，也可以在成员函数中获取到指向该对象的有效智能指针。

使用 std::enable_shared_from_this 的类需要满足以下两个条件：
类本身需要继承自 std::enable_shared_from_this。
类的实例必须要由 std::shared_ptr 所管理。
下面是一个示例： */

#include <iostream>
#include <memory>

class MyClass : public std::enable_shared_from_this<MyClass>
{
public:
	std::shared_ptr<MyClass> get_shared_ptr()
	{
		return shared_from_this();
	}
};

int main()
{
	std::shared_ptr<MyClass> ptr1(new MyClass());
	std::shared_ptr<MyClass> ptr2 = ptr1->get_shared_ptr();

	std::cout << "ptr1 use_count = " << ptr1.use_count() << std::endl;
	std::cout << "ptr2 use_count = " << ptr2.use_count() << std::endl;

	return 0;
}
/* 在这个示例中，MyClass 继承自 std::enable_shared_from_this<MyClass>，并提供了一个成员函数 get_shared_ptr()，该函数返回一个指向自身的 std::shared_ptr。在 main() 函数中，创建了两个指向 MyClass 实例的 std::shared_ptr，分别为 ptr1 和 ptr2。通过 ptr1->get_shared_ptr() 可以获取指向 MyClass 实例的 std::shared_ptr，并将其赋值给 ptr2。由于 ptr2 也指向了同一个 MyClass 实例，因此它们的引用计数都是 2。

需要注意的是，std::enable_shared_from_this 的实现依赖于 std::shared_ptr 的内部实现，因此在使用 shared_from_this() 之前，必须要先创建一个指向该对象的 std::shared_ptr。如果直接从裸指针调用 shared_from_this()，会导致 undefined behavior。 */