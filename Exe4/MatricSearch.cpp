#include <cstdio>
using namespace std;
bool Find(int* matrix, int row, int column, int key) {
	bool result = 0;
	if (matrix != nullptr && row > 0 && column > 0) {
		int i = 0;
		int j = column - 1;
		while (i < row && j >= 0) {
			if (matrix[i*column+j] == key) {
				result = 1;
				return result;
			}
			else if (matrix[i*column+j] > key) {
				--j;
			}
			else {
				++i;
			}
		}
	}
	return result;
}	// end of bool Find()

void Test(int* matrix, int rows, int columns, int key, bool expected) {
	bool res = Find(matrix, rows, columns, key);
	if (res == expected)
		printf("True\n");
	else
		printf("False\n");
}

int main() {
	int matrix[][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15},{7,9,13,16} };
	Test((int*)matrix, 5, 4, 7, true);
	Test((int*)matrix, 5, 4, 14, false);
	Test((int*)matrix, 5, 4, 20, false);
	Test({}, 0, 0, 20,false);
	return 0;
}
