// Ï£¶ûÅÅÐò
#include"HeadforSort.h"

void ShellSort(int A[], int n) {
	int i, j, d;
	for (d = n / 2; d >= 1; d = d / 2) {
		for (i = 1 + d; i <= n; i++) {
			if (A[i] < A[i - d]) {
				A[0] = A[i];
				for (j = i - d; j > 0 && A[j] > A[0]; j = j - d) {
					A[j + d] = A[j];
				}
				A[j + d] = A[0];
			}
		}
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
//	ShellSort(nums, length);
//	PrintNums(nums, length);
//
//	return 0;
//}