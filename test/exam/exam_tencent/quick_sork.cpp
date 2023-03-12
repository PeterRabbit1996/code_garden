#include <iostream>
#include <vector>

void QuickSort(std::vector<int> &nums, int left, int right)
{
	int i = left, j = right;
	int pivot = nums[(left + right) / 2];
	while (i <= j)
	{
		while (nums[i] < pivot)
		{
			i++;
		}
		while (nums[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			std::swap(nums[i], nums[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		QuickSort(nums, left, j);
	}
	if (i < right)
	{
		QuickSort(nums, i, right);
	}
}

int main()
{
	std::vector<int> nums = {10, 7, 8, 9, 1, 5};
	QuickSort(nums, 0, nums.size() - 1);
	for (const auto &num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	return 0;
}