#include<iostream>
using std::cout;
using std::endl;

typedef int key_type;

typedef struct{
	key_type key;
	long low;
	long high;
}index;

int index_search(int* e, key_type key, int n, index idx[], int idx_length) {
	//块间查找
	int low = 0;
	int high = idx_length - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) >> 1;
		if (key < idx[mid].key)
			high = mid - 1;
		else if (key > idx[mid].key)
			low = mid + 1;
		else
			break;
	}
	if (mid<0 || mid>idx_length)
		return -1;
	//块内查找
	int i = idx[mid].low;
	while (i <= idx[mid].high && e[i] != key) {
		i++;
	}
	if (i > idx[mid].high)
		return -1;
	else
		return i;
}

//int main() {
//	int list[] = { 8,20,13,17,40,42,45,32,49,58,50,52,67,79,78,80 };
//	int n = sizeof(list) / sizeof(int);
//	index ind_table1[6] = { {8,0,0},{20,1,3},{45,4,7},{58,8,11},{67,12,12},{79,13,15} };
//	int ind1_length = sizeof(ind_table1) / sizeof(index);
//	cout << index_search(list, 50, n, ind_table1, ind1_length)<<endl;
//	cout << index_search(list, 49, n, ind_table1, ind1_length) << endl;
//	cout << index_search(list, 80, n, ind_table1, ind1_length) << endl;
//	cout << index_search(list, 90, n, ind_table1, ind1_length) << endl;
//	
//	index ind_table2[4] = { {20,0,3},{49,4,8},{58,9,11},{80,12,15} };
//	int ind2_length = sizeof(ind_table2) / sizeof(index);
//	cout << index_search(list, 50, n, ind_table2, ind2_length) << endl;
//	cout << index_search(list, 49, n, ind_table2, ind2_length) << endl;
//	cout << index_search(list, 80, n, ind_table2, ind2_length) << endl;
//	cout << index_search(list, 90, n, ind_table2, ind2_length) << endl;
//	return 0;
//}