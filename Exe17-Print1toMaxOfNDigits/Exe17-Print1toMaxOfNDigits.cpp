// 打印从1到最大的n位数
#include <vcruntime_string.h>
#include <string.h>
#include<iostream>

using std::cout;
using std::endl;

void Print1ToMaxofNDigits(int n);
bool Increment(char* number);
void PrintNumber(char* number);

/* Method 1 */
void Print1ToMaxofNDigits(int n) {
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!Increment(number)) {
		PrintNumber(number);
	}
	cout << endl;

	delete[] number;
}

bool Increment(char* number) {
	bool isOveflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for (int i = nLength - 1; i >= 0; i--) {
		int nSum = number[i] - '0' + nTakeOver; //ASCII '0'
		if (i == nLength - 1)
			nSum++;

		if (nSum >= 10) {
			if (i == 0)
				isOveflow = true;
			else {
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else {
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOveflow;
}

void PrintNumber(char* number) {
	bool beginsWithZero = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength; i++) {
		if (beginsWithZero && number[i] != '0')
			beginsWithZero = false;
		if (!beginsWithZero)
			cout << number[i];
	}
	cout << " ";
}


/*Method 2: 排列组合*/
void PrintRecursively(char* number, int length, int index);

void PrintDigits_method2(int n) {
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	number[n] = '\0';
	for (int i = 0; i < 10; i++) {
		number[0] = i + '0';
		PrintRecursively(number, n, 0);
	}
	delete[] number;
}

void PrintRecursively(char* number, int length, int index) {
	if (index == length - 1) {
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; i++) {
		number[index + 1] = i + '0';
		PrintRecursively(number, length, index + 1);
	}
}


int main() {
	Print1ToMaxofNDigits(2);
	Print1ToMaxofNDigits(0);
	Print1ToMaxofNDigits(-2);

	PrintDigits_method2(2);
	PrintDigits_method2(0);
	PrintDigits_method2(-2);

	return 0;
}