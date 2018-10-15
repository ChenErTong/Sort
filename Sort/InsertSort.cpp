#include "Sort.h"

Sort::Sort(const unsigned int* nums, int length) {
	cache = new unsigned int[length];
}

Sort::~Sort() {
	delete[] cache;
}

void Sort::insertSort(unsigned int* nums, int length) {
	if (nums == NULL || length <= 0) return;

	for (int i = 1; i < length; ++i)	{
		int j = i;
		while(j >= 1 && nums[j] < nums[j - 1]) {
			swap(nums[j], nums[j - 1]);
			--j;
		}
	}
}