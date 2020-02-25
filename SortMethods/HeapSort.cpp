// 堆排序
#include"HeadforSort.h"

#define MAXSIZE 50

void BuildMaxHeap(int A[], int len);
void AdjustDown(int A[], int k, int len);
void HeapSort(int A[], int len);

void BuildMaxHeap(int A[], int len) {
	for (int i = len / 2; i > 0; i--) // 序号len/2之后都是叶子节点
		AdjustDown(A, i, len);
}

void AdjustDown(int A[], int k, int len) {
	if (len <= 0)
		return;
	A[0] = A[k]; //k是当前结点的序号
	for (int i = 2 * k; i < len; i = i * 2) {
		if (i < len && A[i] < A[i + 1])
			i++;
		if (A[i] <= A[0])
			break;
		else {
			A[k] = A[i];
			k = i;//现在i变为要比较的结点序号
		}
	}
	A[k] = A[0];
	
}

void HeapSort(int A[], int len) {
	BuildMaxHeap(A, len);
	for (int i = len; i > 0; i--) {
		int temp = A[i];
		A[i] = A[1];
		A[1] = temp;
		cout << A[i] << " ";
		AdjustDown(A, 1, i - 1);
	}
}

//void PrintNums(int nums[], int len) {
//	for (int i = 1; i <= len; i++) {
//		cout << nums[i] << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	int length;
//	cout << "Input Length: ";
//	cin >> length;
//
//	int nums[MAXSIZE];
//	for (int i = 1; i <= length; i++) {
//		cin >> nums[i];
//	}
//	cout << "Nums are: ";
//	PrintNums(nums, length);
//
//	HeapSort(nums, length);
//
//	return 0;
//}