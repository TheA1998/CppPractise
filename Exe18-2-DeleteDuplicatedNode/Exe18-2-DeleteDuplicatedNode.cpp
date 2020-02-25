#include"../Utilities/List.h"

void DeleteDuplicaton(ListNode** pHead) {
	if (pHead == nullptr || *pHead == nullptr)
		return;
	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	while (pNode != nullptr) {
		bool needDelete = false;
		ListNode* pNext = pNode->m_pNext;
		
		// dupicate situation
		if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
			needDelete = true;
		
		// no need to delete, get next
		if (!needDelete) {
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else {
			int value = pNode->m_nValue;
			ListNode* tobeDeleted = pNode;
			while (tobeDeleted != nullptr && tobeDeleted->m_nValue == value) {
				pNext = tobeDeleted->m_pNext;
				delete tobeDeleted;
				tobeDeleted = nullptr;
				tobeDeleted = pNext;
			}
			if (pPreNode == nullptr)
				*pHead = pNext;
			else
				pPreNode->m_pNext = pNext;
			pNode = pNext;
		}
	}
}
