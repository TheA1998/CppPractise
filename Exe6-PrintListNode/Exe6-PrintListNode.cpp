#include<iostream>
#include<stack>
using std::stack;
using std::cin;
using std::cout;
using std::endl;

typedef struct ListNode {
	int value;
	struct ListNode* pNext;
}ListNode, *LinkList;

// Add a node to the tail of LinkList
void AddToTail(LinkList pHead, int value) {
	ListNode* pNew = new ListNode();
	pNew->pNext = nullptr;
	pNew->value = value;
	
	if (pHead->pNext == nullptr) {
		pHead->pNext = pNew;
		++pHead->value;
	}
	else {
		ListNode* pNode = pHead;
		while (pNode->pNext != nullptr)
			pNode = pNode->pNext;
		pNode->pNext = pNew;
		++pHead->value;
	}
	
}

// Delete a node
void RemoveNode(LinkList pHead, int value) {
	if (pHead == nullptr)
		return;
	ListNode* tobeRemoved = nullptr;
	ListNode* pNode = pHead;
	while (pNode->pNext !=nullptr && pNode->pNext->value != value) {
		pNode = pNode->pNext;
	}
	if (pNode->pNext != nullptr && pNode->pNext->value == value) {
		tobeRemoved = pNode->pNext;
		pNode->pNext = pNode->pNext->pNext;
	}
	if (tobeRemoved != nullptr) {
		delete tobeRemoved;
		tobeRemoved = nullptr;
	}
}

void PrintList(LinkList pHead) {
	if (pHead == nullptr) {
		cout << "pHead nullptr" << endl;
		return;
	}
	ListNode* pNode = pHead;
	while (pNode->pNext != nullptr) {
		cout << pNode->pNext->value << " ";
		pNode = pNode->pNext;
	}
	cout << endl;
	return;
}

void PrintListReversingly_Iteratively(ListNode* pHead) {
	//Using Stack
	stack<ListNode*> nodes;
	if (pHead == nullptr) {
		cout << "pHead nullptr";
		return;
	}
	ListNode* pNode = pHead;
	while (pNode->pNext != nullptr) {
		nodes.push(pNode->pNext);
		pNode = pNode->pNext;
	}

	while (!nodes.empty()) {
		pNode = nodes.top();
		cout << pNode->value << " ";
		nodes.pop();
	}
	cout << endl;
}

void PrintRecursively(ListNode* pNode) {
	if (pNode != nullptr) {
		if (pNode->pNext != nullptr) {
			PrintRecursively(pNode->pNext);
		}
		cout << pNode->value << " ";
	}
}

void PrintListReversingly_Recursively(LinkList pHead) {
	if (pHead == nullptr || pHead->pNext == nullptr) {
		cout << "pHead nullptr";
		return;
	}
	PrintRecursively(pHead->pNext);
	return;
}

int main() {
	LinkList pHead = new ListNode();
	pHead->pNext = nullptr;
	pHead->value = 0;

	int length;
	cin >> length;
	int invalue;
	for (int i = 0; i < length; ++i) {
		cin >> invalue;
		AddToTail(pHead, invalue);
	}
	PrintList(pHead);
	PrintListReversingly_Iteratively(pHead);
	PrintListReversingly_Recursively(pHead);
	return 0;
}