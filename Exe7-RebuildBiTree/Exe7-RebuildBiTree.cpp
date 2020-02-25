#include<iostream>
//todo

typedef struct BiTreeNode {
	int value;
	BiTreeNode* pleft;
	BiTreeNode* pright;
}BiTreeNode, *BiTree;

int FindRootInorderIndex(int* inorder, int root_value);

BiTreeNode* Construct(int* preorder, int pre_start, int pre_end, 
	int* inorder, int in_start, int in_end) 
{
	if (preorder == nullptr || inorder == nullptr) {
		throw std::exception("Invalid Input");
	}

	BiTreeNode* root = new BiTreeNode();
	root->value = preorder[0];
	root->pleft = root->pright = nullptr;

	if (pre_start == pre_end) {
		if (in_start == in_end && inorder[in_start] == preorder[pre_start]) {
			return root;
		}
		else {
			throw std::exception("Invalid Input");
		}
	}

	int root_inorder_index= FindRootInorderIndex(inorder, root->value);
	int leftLength = root_inorder_index - in_start;

	if (leftLength > 0) {
		root->pleft = Construct(preorder, pre_start + 1, pre_start + leftLength,
			inorder, in_start, root_inorder_index - 1);
	}
	if (leftLength < pre_end - pre_start) {
		root->pright = Construct(preorder, pre_start + leftLength + 1, pre_end,
			inorder, root_inorder_index + 1, in_end);
	}

	return root;
}

int FindRootInorderIndex(int* inorder, int root_value) {
	int index = 0;
	while (inorder[index] != NULL && inorder[index] != root_value) {
		index++;
	}
	return index;
}

int main() {
	int preorder[] = { 1,2,4,7,3,5,6,8 };
	int inorder[] = { 4,7,2,1,5,3,8,6 };
	BiTree root = Construct(preorder, 0, 8, inorder, 0, 8);
	std::cout << root->value;
	return 0;
}