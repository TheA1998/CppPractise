#include"typedef.h"

int BinarySearch(SeqList list, int key) {
	int low = 0, high = list.tablelen - 1, mid;
	while (low <= high) {
		mid = (low + high) >> 1;
		if (list.elem[mid] == key)
			return mid;
		else if (list.elem[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}