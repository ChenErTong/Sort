#include "Sort.h"

void Sort::shellSort(unsigned int* nums, int length) {
	if (nums == NULL || length <= 0) return;

	for (int gap = length / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < length; ++i){
			int j = i;
			while (j >= gap && nums[j] < nums[j - gap]) {
				swap(nums[j], nums[j - gap]);
				j -= gap;
			}
		}
	}
}