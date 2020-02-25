// ÷±Ω”≤Â»Î≈≈–Ú
#include"HeadforSort.h"

typedef int Elemtype;

//void PrintNums(int nums[], int len) {
//	for (int i = 0; i < len; i++) {
//		cout << nums[i] << " ";
//	}
//	cout << endl;
//}

void InsertSort(Elemtype A[], int n) {
	int i, j;
	for (i = 2; i <= n; i++) {
		if (A[i] < A[i - 1]) {
			A[0] = A[i];
			for (j = i - 1; A[j] > A[0]; j--) {
				A[j + 1] = A[j];
			}
			A[j + 1] = A[0];
		}
	}
}


//int main() {
//	int nums[] = {0,1,2,4,3,7,6,6,4,9 };
//	int length = 9;
//	for (int i = 0; i < length; i++) {
//		cout << nums[i] << " ";
//	}
//	cout << endl;
//	InsertSort(nums, length);
//	for (int i = 0; i < length; i++) {
//		cout << nums[i] << " ";
//	}
//	return 0;
//}