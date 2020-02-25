// МєЩўзг
#include<math.h>
#include<iostream>
using namespace std;

void PrintNums(int* nums, int length) {
	for (int i = 0; i <= length; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

int maxProduct_dynamic(int length) {
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;

	for (int i = 4; i <= length; i++) {
		max = 0;
		for (int j = 1; j <= i>>1 ; j++) {
			int product = products[j] * products[i - j];
			if (max < product) {
				max = product;
			}
		}
		products[i] = max;
	}
	max = products[length];
	PrintNums(products, length);
	delete[] products;

	return max;
}

int maxProduct_greedy(int length) {
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int timesof3 = length / 3;
	if (length - timesof3 * 3 == 1)
		timesof3 -= 1;

	int timesof2 = (length - timesof3 * 3) / 2;

	return (int)(pow(3, timesof3)) * (int)(pow(2, timesof2));

}

int main() {
	cout << "Dynamic(8): " << maxProduct_dynamic(8) << endl;
	cout << "Greedy(8): " << maxProduct_greedy(8) << endl;

	cout << "Dynamic(0): " << maxProduct_dynamic(0) << endl;
	cout << "Greedy(0): " << maxProduct_greedy(0) << endl;

	cout << "Dynamic(49): " << maxProduct_dynamic(49) << endl;
	cout << "Greedy(49): " << maxProduct_greedy(49) << endl;

	cout << "Dynamic(2): " << maxProduct_dynamic(2) << endl;
	cout << "Greedy(2): " << maxProduct_greedy(2) << endl;

	return 0;

}