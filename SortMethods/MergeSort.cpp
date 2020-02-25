#include<malloc.h>
#include<iostream>
using namespace std;

#define MAXSIZE 50

int* B = nullptr;
void PrintNums(int nums[], int len);
int length;

void Merge(int A[], int low, int mid, int high) {
	int i, j, k;
	for (k = low; k <= high; k++)
		B[k] = A[k];
	for (i = low, j = mid + 1, k = i;
		i <= mid && j <= high; k++) {
		if (B[i] <= B[j])
			A[k] = B[i++];
		else
			A[k] = B[j++];
	}
	while (i <= mid)
		A[k++] = B[i++];
	while (j <= high)
		A[k++] = B[j++];
	
	PrintNums(A, length);
}

void MergeSort(int A[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);
		Merge(A, low, mid, high);
	}
}

//void PrintNums(int nums[], int len) {
//	for (int i = 0; i < len; i++) {
//		cout << nums[i] << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	cout << "Length: ";
//	cin >> length;
//
//	int* nums = (int*)malloc(length*sizeof(int));
//	for (int i = 0; i < length; i++) {
//		cin >> nums[i];
//	}
//	B = (int*)malloc((length) * sizeof(int));
//
//	PrintNums(nums, length);
//
//	MergeSort(nums, 0, length - 1);
//	PrintNums(nums, length);
//
//	return 0;
//
//}