#include "Sort.h"

void Sort::quickSort(unsigned int* nums, int low, int high) {
	if (high - low < 13) {
		for (int i = low + 1; i <= high; ++i) {
			int j = i;
			while (j > low && nums[j] < nums[j - 1]) {
				swap(nums[j], nums[j - 1]);
				--j;
			}
		}
		return;
	}

	int middle = low + (high - low) / 2, pivot = low;
	if (nums[low] > nums[middle] && nums[low] > nums[high]) {
		pivot = (nums[middle] > nums[high] ? middle : high);
	} else if (nums[low] < nums[middle] && nums[low] < nums[high]) {
		pivot = (nums[middle] < nums[high] ? middle : high);
	}
	swap(nums[pivot], nums[high]);
	
	int index = low;
	for (int i = low; i < high; ++i)
		if (nums[i] <= nums[high])
			swap(nums[i], nums[index++]);

	swap(nums[index], nums[high]);

	quickSort(nums, low, index - 1);
	quickSort(nums, index + 1, high);
}

void Sort::quickSort(unsigned int* nums, int length) {
	if (nums == NULL || length <= 0) return;
	quickSort(nums, 0, length - 1);
}