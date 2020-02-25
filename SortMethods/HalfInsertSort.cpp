// ’€∞Î≤Â»Î≈≈–Ú
#include"HeadforSort.h"

void HalfInsertSort(int A[], int n) {
	int i, j, low, mid, high;
	for (i = 2; i <= n; i++) {
		A[0] = A[i];
		low = 1;
		high = i - 1;
		while (low <= high) {
			mid = (low + high) >> 1;
			if (A[0] > A[mid])
				low = mid + 1;
			else
				high = mid - 1;
		}
		for (j = i - 1; j >= high + 1; j--)
			A[j + 1] = A[j];
		A[high + 1] = A[0];
	}
}

//int main() {
//	int length;
//	cout << "Input Length: ";
//	cin >> length;
//	if (length > MAXSIZE) {
//		cout << "MAXSIZE(50) Exceeded";
//		return -1;
//	}
//
//	int nums[MAXSIZE];
//	for (int i = 1; i <= length; i++) {
//		cin >> nums[i];
//	}
//	PrintNums(nums, length);
//
//	HalfInsertSort(nums, length);
//	PrintNums(nums, length);
//
//	return 0;
//}