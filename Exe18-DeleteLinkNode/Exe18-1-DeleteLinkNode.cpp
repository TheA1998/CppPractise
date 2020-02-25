#include<iostream>

typedef struct ListNode {
	int value;
	ListNode* pNext;
}ListNode;

void DeleteNode(ListNode** pHead, ListNode* tobeDeleted) {
	if (!pHead || !tobeDeleted)
		return;
	if (tobeDeleted->pNext != nullptr) {
		ListNode* pNext = tobeDeleted->pNext;
		tobeDeleted->value = pNext->value;
		tobeDeleted->pNext = pNext->pNext;

		delete pNext;
		pNext = nullptr;
	}
	else if (*pHead == tobeDeleted) {
		delete tobeDeleted;
		tobeDeleted = nullptr;
		pHead = nullptr;
	}
	else {
		ListNode* pNode = *pHead;
		while (pNode->pNext != tobeDeleted)
			pNode = pNode->pNext;
		pNode->pNext = nullptr;
		delete tobeDeleted;
		tobeDeleted = nullptr;
	}

}

int main() {
	/* Test double delete: */
	/*ListNode* pNode = new ListNode();
	delete pNode;
	pNode = nullptr;
	delete pNode;*/

	return 0;
}