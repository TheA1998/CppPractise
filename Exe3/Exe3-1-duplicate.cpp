#include <iostream>
#include <cstring>
#include <cstdio> 
using namespace std;

bool duplicate(int numbers[], int length, int& duplication)
{
	if (numbers == nullptr || length <= 0) {
		return false;
	}

	for (int i = 0; i < length; i++) {
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;
	}

	for (int i = 0; i < length; i++) {
		while (numbers[i] != i) {
			if (numbers[i] == numbers[numbers[i]]) {
				duplication = numbers[i];
				return true;
			}

			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}

int main() {
	int numbers[] = { 1,2,3,2,3,4,7,4 };
	int length = 8;
	int duplication = 0;
	//for (int i = 0; i < length; i++) {
		//cin >> numbers[i];
	//}
	duplicate(numbers, length, duplication);
	cout << duplication;
}
