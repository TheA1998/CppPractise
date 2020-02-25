#include"Stack.h"
#include<iostream>

void Test(char result, char expected) {
	if (result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

int main() {
	CStack<char> stack;

	stack.CStack_push('a');
	stack.CStack_push('b');
	stack.CStack_push('c');

	cout<<stack.CStack_pop()<<endl;
	cout<<stack.CStack_pop()<<endl;

	//Test(stack.CStack_pop(), 'c');
	//Test(stack.CStack_pop(), 'b');
	stack.CStack_push('d');
	/*Test(stack.CStack_pop(), 'd');
	Test(stack.CStack_pop(), 'a');*/
	//Test(stack.CStack_pop(), NULL);
	cout<<stack.CStack_pop()<<endl;
	cout<<stack.CStack_pop()<<endl;
	cout<<stack.CStack_pop()<<endl;

	return 0;
}