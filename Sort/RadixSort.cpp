#include<algorithm>
#include "Sort.h"

void Sort::radixSort(unsigned int* nums, int length) {
	int r = (int)log2(length);
	int pass = (int)ceil(32.0 / r), K = (int)pow(2, r), K_minus1 = K - 1;
	int* C = new int[K];
	unsigned int size = length * sizeof(unsigned int);

	for (int move = 0; move < 32; move+=r) {
		memset(C, 0, K * sizeof(int));
		for (int i = 0; i < length; ++i)
			++C[(nums[i] >> move) & K_minus1];
		for (int i = 1; i < K; ++i)
			C[i] += C[i - 1];

		for (int i = length - 1; i >= 0; --i) {
			int t = (nums[i] >> move) & K_minus1;
			cache[C[t] - 1] = nums[i];
			--C[t];
		}

		memcpy(nums, cache, size);
	}
}