#include"Sort.h"

void Sort::mergeSort(unsigned int* nums, int low, int high) {
	if (low == high) return;

	int middle = low + (high - low) / 2;
	mergeSort(nums, low, middle);
	mergeSort(nums, middle + 1, high);

	int index = low, i = low, j = middle + 1;
	while(i <= middle && j <= high)
		if (nums[i] <= nums[j])
			cache[index++] = nums[i++];
		else
			cache[index++] = nums[j++];

	while(i <= middle)	cache[index++] = nums[i++];
	while(j <= high)	cache[index++] = nums[j++];

	for (index = low; index <= high; ++index)
		nums[index] = cache[index];
}

void Sort::mergeSort(unsigned int* nums, int length) {
	if (nums == NULL || length <= 0) return;
	mergeSort(nums, 0, length - 1);
}