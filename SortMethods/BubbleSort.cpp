// √∞≈›À„∑®
#include"HeadforSort.h"

#define MAXSIZE 50

void PrintNums(int nums[], int len);

void BubbleSort(int A[], int n) {
	bool flag;
	for (int i = 0; i < n - 1; i++) {
		flag = false;
		for (int j = n - 1; j > i; j--) {
			if (A[j - 1] > A[j]) {
				int temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				flag = true;
			}
		}
		PrintNums(A, n);
		if (flag == false)
			return;
	}
}

//void PrintNums(int nums[], int len) {
//	for (int i = 0; i < len; i++) {
//		cout << nums[i] << " ";
//	}
//	cout << endl;
//}

//int main() {
//	int length;
//	cout << "Input length: ";
//	cin >> length;
//	if (length > MAXSIZE) {
//		cout << "MAXSIZE(50) Exceeded";
//		return -1;
//	}
//
//	int nums[MAXSIZE];
//	cout << "Input nums: ";
//	for (int i = 0; i < length; i++) {
//		cin >> nums[i];
//	}
//	cout << "Nums are:";
//	PrintNums(nums, length);
//
//	BubbleSort(nums, length);
//	PrintNums(nums, length);
//
//	return 0;
//}