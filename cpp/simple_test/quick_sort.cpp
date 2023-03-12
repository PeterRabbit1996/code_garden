#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <forward_list>

template <class _ForwardIterator>
void display(_ForwardIterator __first, _ForwardIterator __last)
{
	for (auto v = __first; v != __last; ++v)
	{
		std::cout << *v << " ";
	}
	std::cout << std::endl;
	return;
}

template <class _Predicate, class _ForwardIterator>
_ForwardIterator __partition(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred)
{
	auto first = __first;
	auto last = __last;
	while (true)
	{
		if (__first == __last)
			return __first;
		if (!__pred(*__first))
			break;
		++__first;
	}
	for (_ForwardIterator __p = __first; ++__p != __last;)
	{
		if (__pred(*__p))
		{
			std::swap(*__first, *__p);
			++__first;
			display(first, last);
		}
	}
	return __first;
}

template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last)
{
	if (first == last)
		return;
	auto pivot = *std::next(first, std::distance(first, last) / 2);
	auto middle1 = __partition(first, last, [pivot](const auto &em)
				   { return em < pivot; });
	auto middle2 = __partition(middle1, last, [pivot](const auto &em)
				   { return !(pivot < em); });
	if (middle1 != last)
		std::cout << "middle1 = " << *middle1 << std::endl;
	if (middle2 != last)
		std::cout << "middle2 = " << *middle2 << std::endl;

	display(first, last);
	quicksort(first, middle1);
	quicksort(middle2, last);
}

int main()
{
	std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::cout << "Original vector:\n    ";
	for (int elem : v)
		std::cout << elem << ' ';

	auto it = std::partition(v.begin(), v.end(), [](int i)
				 { return i % 2 == 0; });

	std::cout << "\nPartitioned vector:\n    ";
	std::copy(std::begin(v), it, std::ostream_iterator<int>(std::cout, " "));
	std::cout << " * "
		     " ";
	std::copy(it, std::end(v), std::ostream_iterator<int>(std::cout, " "));

	std::forward_list<int> fl = {1, 30, -4, 3, 5, 40, 1, 6, -8, 2, -5, 64, 1, 92};
	std::cout << "\nUnsorted list:\n    ";
	for (int n : fl)
		std::cout << n << ' ';
	std::cout << '\n';

	quicksort(std::begin(fl), std::end(fl));
	std::cout << "Sorted using quicksort:\n    ";
	for (int fi : fl)
		std::cout << fi << ' ';
	std::cout << '\n';
}