#include<iostream>

typedef struct BiTreeNode {
	int value;
	BiTreeNode* pParent;
	BiTreeNode* pLeft;
	BiTreeNode* pRight;
}BiTreeNode;

BiTreeNode* GetNextNode(BiTreeNode* pNode) {
	if (pNode == nullptr)
		return nullptr;
	
	BiTreeNode* pNext = nullptr;

	if (pNode->pRight != nullptr) {
		pNext = pNode->pRight;
		while (pNext->pLeft != nullptr)
			pNext = pNext->pLeft;
	}

	else if (pNode->pParent != nullptr){
		if (pNode->pParent->pLeft == pNode) {
			pNext = pNode->pParent;
		}

		if (pNode->pParent->pRight == pNode) {
			pNext = pNode;
			while (pNext->pParent != nullptr && pNext->pParent->pLeft != pNext) {
				pNext = pNext->pParent;
			}
			pNext = pNext->pParent;
		}
	}

	return pNext;
}

BiTreeNode* CreateNode(int value) {
	BiTreeNode* node = new BiTreeNode();
	node->value = value;
	node->pParent = nullptr;
	node->pLeft = nullptr;
	node->pRight = nullptr;
	return node;
}

void ConnectNodes(BiTreeNode* node, BiTreeNode* lchild, BiTreeNode* rchild) {
	if (node != nullptr) {
		node->pLeft = lchild;
		node->pRight = rchild;
		if (lchild != nullptr) {
			lchild->pParent = node;
		}
		if (rchild != nullptr) {
			rchild->pParent = node;
		}
	}
}

void DeleteTree(BiTreeNode* bitree) {
	if (bitree != nullptr) {
		BiTreeNode* left = bitree->pLeft;
		BiTreeNode* right = bitree->pRight;

		delete bitree;
		bitree = nullptr;

		DeleteTree(left);
		DeleteTree(right);
	}
	return;
}

void Test(BiTreeNode* pNode, BiTreeNode* expectedNext) {
	BiTreeNode* next = nullptr;
	next = GetNextNode(pNode);
	if (next == expectedNext) {
		std::cout<<"true"<<std::endl;
	}
	else
		std::cout<<"false"<<std::endl;
	return;
}

void Test1() {
	BiTreeNode* node1 = CreateNode(1);
	BiTreeNode* node2 = CreateNode(2);
	BiTreeNode* node3 = CreateNode(3);
	BiTreeNode* node4 = CreateNode(4);
	BiTreeNode* node5 = CreateNode(5);
	BiTreeNode* node6 = CreateNode(6);
	BiTreeNode* node7 = CreateNode(7);
	BiTreeNode* node8 = CreateNode(8);
	BiTreeNode* node9 = CreateNode(9);

	ConnectNodes(node1, node2, node3);
	ConnectNodes(node2, node4, node5);
	ConnectNodes(node5, node6, node7);
	ConnectNodes(node3, node8, node9);

	Test(node2, node6);
	Test(node7, node1);
	Test(node9, nullptr);
	Test(nullptr, nullptr);
	return;
}

void Test2() {
	BiTreeNode* node1 = CreateNode(1);
	BiTreeNode* node2 = CreateNode(2);
	BiTreeNode* node3 = CreateNode(3);
	BiTreeNode* node4 = CreateNode(4);
	BiTreeNode* node5 = CreateNode(5);
	BiTreeNode* node6 = CreateNode(6);

	ConnectNodes(node1, node2, node6);
	ConnectNodes(node2, node3, nullptr);
	ConnectNodes(node3, node4, node5);

	Test(node5, node2);
	Test(node4, node3);
	Test(node1, node6);
	return;
}

int main() {
	Test1();
	Test2();
	return 0;
}