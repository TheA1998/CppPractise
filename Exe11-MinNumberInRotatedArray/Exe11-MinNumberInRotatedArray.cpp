// 旋转数组的最小数字
#include<exception>
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#define MAXSIZE 50

int MinInOrder(int* nums, int low, int high);

int Min(int* nums, int length) {
	if (nums == nullptr || length < 0) {
		throw new std::exception("Invalid Params");
	}

	int low = 0;
	int high = length - 1;
	int mid = low;

	while (nums[low] >= nums[high]) {
		if (high - low == 1) {
			mid = high;
			break;
		}
		mid = (low + high) / 2;
		if (nums[low] == nums[high] == nums[mid]) {
			return MinInOrder(nums, low, high);
		}
		if (nums[mid] >= nums[low])
			low = mid;
		else if (nums[mid] <= nums[high])
			high = mid;
	}
	return nums[mid];
}

int MinInOrder(int* nums, int low, int high) {
	int result = nums[low];
	for (int i = low + 1; i <= high; i++) {
		if (result > nums[i])
			result = nums[i];
	}
	return result;
}

int main() {
	int nums1[] = { 5,6,7,8,9,1,2,3,4 };
	cout << Min(nums1, 9) << endl;

	int nums2[] = { 3,4,5,6,7,0,1 };
	cout << Min(nums2, 7) << endl;

	int nums3[] = { 1,0,0,1,1 };
	cout << Min(nums3, 5) << endl;

	return 0;
}
