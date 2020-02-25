// ºÚµ•—°‘Ò≈≈–Ú
#include"HeadforSort.h"

#define MAXSIZE 50

void PrintNums(int nums[], int len);

//void PrintNums(int nums[], int len) {
//	for (int i = 0; i < len; i++) {
//		cout << nums[i] << " ";
//	}
//	cout << endl;
//}

void SimpleSelectSort(int A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_pos = i;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[min_pos])
				min_pos = j;
		}
		if (min_pos != i) {
			int temp = A[i];
			A[i] = A[min_pos];
			A[min_pos] = temp;
		}
		PrintNums(A, n);
	}
}

//int main() {
//	int length;
//	cout << "Input Length: ";
//	cin >> length;
//
//	int nums[MAXSIZE];
//	cout << "Input nums: ";
//	for (int i = 0; i < length; i++) {
//		cin >> nums[i];
//	}
//
//	cout << "Nums are: ";
//	PrintNums(nums, length);
//
//	SimpleSelectSort(nums, length);
//
//	cout << "Final Result: ";
//	PrintNums(nums, length);
//
//	return 0;
//}