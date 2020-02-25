// øÏÀŸ≈≈–Ú
#include"HeadforSort.h"

#define MAXSIZE 50

//void PrintNums(int nums[], int len) {
//	for (int i = 0; i < len; i++) {
//		cout << nums[i] << " ";
//	}
//	cout << endl;
//}

int Partition(int A[], int low, int high) {
	int pivot = A[low];
	while (low < high) {
		while (low < high && A[high] >= pivot)
			high--;
		A[low] = A[high];
		while (low < high && A[low] <= pivot)
			low++;
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}

void QuickSort(int A[], int low, int high) {
	if (low < high) {
		int pivot_pos = Partition(A, low, high);
		QuickSort(A, low, pivot_pos - 1);
		QuickSort(A, pivot_pos + 1, high);
	}
}

//int main() {
//	int length;
//	cout << "Input length: ";
//	cin >> length;
//
//	int nums[MAXSIZE];
//	for (int i = 0; i < length; i++) {
//		cin >> nums[i];
//	}
//	cout << "Nums are: ";
//	PrintNums(nums, length);
//
//	QuickSort(nums, 0, length-1);
//
//	cout << "Final Result: ";
//	PrintNums(nums, length);
//
//	return 0;
//}