#include<time.h>
#include<algorithm>
#include"Random.h"
#include"Sort.h"
using namespace std;

void output(unsigned int* nums, int length) {
	for (int i = 0; i < min(length, 5); i++)
		cout << nums[i] << " ";
	cout << endl;
}

int main() {
	clock_t start, end;

	while (1) {
		int length;
		char flag;
		cout << "Please input the number (0 to end): ";
		cin >> length;

		if (length <= 0) break;

		unsigned int size = length * sizeof(unsigned int);
		unsigned int* nums = new unsigned int[length];
		unsigned int* backup = new unsigned int[length];

		start = clock();
		bigRandom(nums, length);
		end = clock();
		cout << "Random Running Time " << (double)(end - start) / CLOCKS_PER_SEC << " sec." << endl;
		output(nums, length);

		start = clock();
		bigRandomDIY(nums, length);
		end = clock();
		cout << "DIY Random Running Time " << (double)(end - start) / CLOCKS_PER_SEC << " sec." << endl;
		output(nums, length);
		memcpy(backup, nums, size);

		Sort sort(nums, length);

		cout << "Use quick sort (Y/N): ";
		cin >> flag;
		if (flag == 'Y') {
			start = clock();
			sort.quickSort(nums, length);
			end = clock();
			cout << "Quick Sort - Running Time " << (double)(end - start) / CLOCKS_PER_SEC << " sec." << endl;
			output(nums, length);
			memcpy(nums, backup, size);
		}
		
		cout << "Use radix sort (Y/N): ";
		cin >> flag;
		if (flag == 'Y') {
			start = clock();
			sort.radixSort(nums, length);
			end = clock();
			cout << "Radix Sort - Running Time " << (double)(end - start) / CLOCKS_PER_SEC << " sec." << endl;
			output(nums, length);
			memcpy(nums, backup, size);
		}
		
		cout << "Use merge sort (Y/N): ";
		cin >> flag;
		if (flag == 'Y') {
			start = clock();
			sort.mergeSort(nums, length);
			end = clock();
			cout << "Merge Sort - Running Time " << (double)(end - start) / CLOCKS_PER_SEC << " sec." << endl;
			output(nums, length);
			memcpy(nums, backup, size);
		}
		
		cout << "Use shell sort (Y/N): ";
		cin >> flag;
		if (flag == 'Y') {
			start = clock();
			sort.shellSort(nums, length);
			end = clock();
			cout << "Shell Sort - Running Time " << (double)(end - start) / CLOCKS_PER_SEC << " sec." << endl;
			output(nums, length);
			memcpy(nums, backup, size);
		}
		
		cout << "Use insert sort (Y/N): ";
		cin >> flag;
		if (flag == 'Y') {
			start = clock();
			sort.insertSort(nums, length);
			end = clock();
			cout << "Insert Sort - Running Time " << (double)(end - start) / CLOCKS_PER_SEC << " sec." << endl;
			output(nums, length);
		}

		delete[] nums;
		delete[] backup;
	}
}