#include"Random.h"
#include<iostream>
#include<random>
#include<limits>
using namespace std;

void bigRandom(unsigned int* nums, int length) {
	random_device device;
	mt19937 seed(device());
	uniform_int_distribution<unsigned int> generator(0, numeric_limits<unsigned int>::max());

	for (int i = 0; i < length; i++)
		nums[i] = generator(seed);
}

void bigRandomDIY(unsigned int* nums, int length) {
	unsigned int size = sizeof(unsigned int) * length;
	memset(nums, 0, size);
	for (int i = 0; i < length; i++)
		for (int j = 0; j < 32; j+=8)
			nums[i] += (rand() & 255) << j;
}