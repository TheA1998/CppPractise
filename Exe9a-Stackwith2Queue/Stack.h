#pragma once

#include<queue>
using namespace std;

template<typename T> class CStack {
public:
	CStack();
	~CStack();

	void CStack_push(const T&node);
	T CStack_pop();

private:
	queue<T> queue1;
	queue<T> queue2;
};

template <typename T> CStack<T>::CStack(){}
template <typename T> CStack<T>::~CStack(){}

template <typename T> void CStack<T>::CStack_push(const T& node) {
	if (queue1.size() >= 0 && queue2.size() == 0) {
		queue1.push(node);
	}
	else if (queue1.size() == 0 && queue2.size() > 0) {
		queue2.push(node);
	}
}

template <typename T> T CStack<T>::CStack_pop() {
	T top = NULL;
	if (queue1.size() > 0 && queue2.size() == 0) {
		while (queue1.size() > 1) {
			T& data = queue1.front();
			queue1.pop();
			queue2.push(data);
		}
		T top = queue1.front();
		queue1.pop();
	}

	else if (queue1.size() == 0 && queue2.size() > 0) {
		while (queue2.size() > 1) {
			T& data = queue2.front();
			queue2.pop();
			queue1.push(data);
		}
		T top = queue2.front();
		queue2.pop();
	}

	return top;
}