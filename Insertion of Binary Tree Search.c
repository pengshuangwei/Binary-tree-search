#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *BinTree;
typedef BinTree Postition;
struct TreeNode {
	int Data;
	BinTree left;
	BinTree right;
};
Postition CreateTree();
BinTree Insert(int X, BinTree BST);
int main()
{
	int X = 0;
	BinTree Root = (BinTree)malloc(sizeof(struct TreeNode));
	Root = CreateTree();
	Root = Insert(X, Root);
	return 0;
}

BinTree Insert(int X, BinTree BST)
{
	if (!BST) {
		//原树为空，生成并返回一个结点的二叉树
		BST = (BinTree)malloc(sizeof(struct TreeNode));
		if (BST == NULL) {
			printf("申请内存失败");
		}
		else {
			BST->Data = X;
			BST->left = BST->right = NULL;
			printf("qq.com");
		}
	}
	else {
		if (X < BST->Data)
			BST->left = Insert(X, BST->left);
		else if (X > BST->Data)
			BST->right = Insert(X, BST->right);
	}
	return BST;
}Postition CreateTree()
{
	BinTree BST = NULL;

	return BST;
}