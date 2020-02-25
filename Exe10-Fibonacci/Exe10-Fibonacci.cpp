#include<iostream>
#include<time.h>
using std::cout;
using std::endl;

long long Fibonacci_1(unsigned n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci_1(n - 1) + Fibonacci_1(n - 2);
}

long long Fibonacci_2(unsigned n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	long long fn_1 = 1;
	long long fn_2 = 0;
	long long fn = 0;

	for (unsigned int i = 2; i <= n; i++) {
		fn = fn_1 + fn_2;
		fn_2 = fn_1;
		fn_1 = fn;
	}
	return fn;
}

int main() {
	clock_t start_time,end_time;
	start_time = clock();
	cout << Fibonacci_1(30)<<" ";
	end_time = clock();
	cout << end_time - start_time<<endl;

	start_time = clock();
	cout << Fibonacci_2(30)<<" ";
	end_time = clock();
	cout << end_time - start_time << endl;

	start_time = clock();
	cout << Fibonacci_1(5)<<" ";
	end_time = clock();
	cout << end_time - start_time << endl;

	start_time = clock();
	cout << Fibonacci_2(5) << " ";
	end_time = clock();
	cout << end_time - start_time << endl;

	return 0;

}