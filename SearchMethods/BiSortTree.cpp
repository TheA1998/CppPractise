//二叉排序树
#include<malloc.h>
#include<iostream>
using std::cout;
using std::endl;

typedef struct BSTreeNode {
	int value;
	BSTreeNode* lchild;
	BSTreeNode* rchild;
}*BSTree;

// 二叉排序树查找结点
BSTreeNode* BSTree_Search(BSTree T, int key, BSTreeNode*& p) {
	p = nullptr;
	while (T != nullptr && T->value != key) {
		p = T;	//p为T的parent
		if (T->value > key)
			T = T->lchild;
		else
			T = T->rchild;
	}
	return T;
}

// 二叉排序树的插入
int BSTree_Insert(BSTree& T, int k) {
	if (T == nullptr) {
		T = (BSTreeNode*)malloc(sizeof(BSTreeNode));
		T->value = k;
		T->lchild = T->rchild = nullptr;
		return 1;
	}
	else if (T->value == k)
		return 0;
	else if (k < T->value)
		return BSTree_Insert(T->lchild, k);
	else
		return BSTree_Insert(T->rchild, k);
}

// 构造二叉排序树
void BSTree_Create(BSTree& T, int keys[], int n) {
	T = nullptr;
	int i = 0;
	while (i < n) {
		BSTree_Insert(T, keys[i]);
		i++;
	}
}

// 删除结点
void BSTree_Delete(BSTree& T, int key) {
	if (T == nullptr)
		return;
	BSTreeNode* tobeDeleted = nullptr;
	BSTreeNode* parent = nullptr;
	tobeDeleted = BSTree_Search(T, key, parent);
	if (tobeDeleted->lchild == nullptr && tobeDeleted->rchild == nullptr) {
		if (parent->lchild == tobeDeleted)
			parent->lchild = nullptr;
		else if (parent->rchild == tobeDeleted)
			parent->rchild = nullptr;
		delete tobeDeleted;
		return;
	}
	if (tobeDeleted->lchild != nullptr && tobeDeleted->rchild == nullptr) {
		if (parent->lchild == tobeDeleted)
			parent->lchild = tobeDeleted->lchild;
		else if (parent->rchild == tobeDeleted)
			parent->rchild = tobeDeleted->lchild;
		delete tobeDeleted;
		return;
	}
	if (tobeDeleted->lchild == nullptr && tobeDeleted->rchild != nullptr) {
		if (parent->lchild == tobeDeleted)
			parent->lchild = tobeDeleted->rchild;
		else if (parent->rchild == tobeDeleted)
			parent->rchild = tobeDeleted->rchild;
		delete tobeDeleted;
		return;
	}
	if (tobeDeleted->lchild != nullptr && tobeDeleted->rchild != nullptr) {
		if (parent->lchild == tobeDeleted) {
			BSTreeNode* pNode = tobeDeleted->rchild;
			while (pNode->lchild != nullptr && pNode->lchild->lchild != nullptr) {
				pNode = pNode->lchild;
			}
			if (pNode->lchild != nullptr) {
				parent->lchild = pNode->lchild;
				pNode->lchild = pNode->lchild->rchild;
				parent->lchild->lchild = tobeDeleted->lchild;
				parent->lchild->rchild = tobeDeleted->rchild;
				delete tobeDeleted;
			}
			return;
		}
		if (parent->rchild == tobeDeleted) {
			BSTreeNode* pNode = tobeDeleted->rchild;
			while (pNode->lchild != nullptr && pNode->lchild->lchild != nullptr) {
				pNode = pNode->lchild;
			}
			if (pNode->lchild != nullptr) {
				parent->rchild = pNode->lchild;
				pNode->lchild = pNode->lchild->rchild;
				parent->rchild->lchild = tobeDeleted->lchild;
				parent->rchild->rchild = tobeDeleted->rchild;
				delete tobeDeleted;
			}
			return;
		}
	}
	return;
}

void PrintTreeInorder(BSTree T) {
	if (T != nullptr) {
		PrintTreeInorder(T->lchild);
		cout << T->value<<" ";
		PrintTreeInorder(T->rchild);
	}
}

//int main() {
//	int values[] = { 53,17,78,9,45,65,87,23 };
//	BSTree T = nullptr;
//	BSTree_Create(T, values, 8);
//	PrintTreeInorder(T);
//	cout << endl;
//
//	BSTree_Insert(T, 25);
//	PrintTreeInorder(T);
//	cout << endl;
//
//	BSTreeNode* parent = nullptr;
//	BSTreeNode* search = nullptr;
//	search = BSTree_Search(T, 30, parent);
//	if (search == nullptr)
//		cout << "Not found" << endl;
//	search = BSTree_Search(T, 78, parent);
//	cout << search->value << endl;
//
//	BSTree_Delete(T, 87);
//	PrintTreeInorder(T);
//	cout << endl;
//
//	return 0;
//	
//}