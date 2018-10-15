#pragma once
#include<iostream>
using namespace std;

class Sort{
public:
	Sort(const unsigned int* nums, int length);
	~Sort();
	void insertSort(unsigned int*, int);
	void shellSort(unsigned int*, int);
	void quickSort(unsigned int*, int);
	void mergeSort(unsigned int*, int);
	void radixSort(unsigned int*, int);
private:
	unsigned int* cache;
	void quickSort(unsigned int*, int, int);
	void mergeSort(unsigned int*, int, int);
};