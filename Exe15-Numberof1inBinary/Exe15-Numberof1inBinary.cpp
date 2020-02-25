// 二进制中1的个数
#include<iostream>
using std::cout;
using std::endl;

int NumberOf1_regular(int n) {
	int count = 0;
	unsigned int flag = 1;
	while (flag) {
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

int NumberOf1_suprise(int n) {
	int count = 0;
	while (n) {
		n = (n - 1) & n;
		count++;
	}
	return count;
}

int main() {
	cout << "reg (938): " << NumberOf1_regular(938) << endl;
	cout << "sup (938): " << NumberOf1_suprise(938) << endl;

	cout << "reg (0): " << NumberOf1_regular(0) << endl;
	cout << "sup (0): " << NumberOf1_suprise(0) << endl;

	cout << "reg (1): " << NumberOf1_regular(1) << endl;
	cout << "sup (1): " << NumberOf1_suprise(1) << endl;

	cout << "reg (-60913): " << NumberOf1_regular(-60913) << endl;
	cout << "sup (-60913): " << NumberOf1_suprise(-60913) << endl;

	return 0;
}