#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *BinTree;
typedef BinTree Postition;
struct TreeNode {
	int Data;
	BinTree left;
	BinTree right;
};/*定义结构体*/
Postition CreateTree();
/*创建二叉搜索树*/
BinTree Insert(int X, BinTree BST);
/*二叉搜索树的插入操作*/
int main()
{
	int X = 0;
	BinTree Root = (BinTree)malloc(sizeof(struct TreeNode));
	if (!Root) {
		printf("申请内存失败");
		return -1;
	}
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
		}/*验空*/
		else {
			BST->Data = X;
			BST->left = BST->right = NULL;
		}
	}
	else {
		/*分别向左向右递归找到X的位置并插入*/
		if (X < BST->Data)
			BST->left = Insert(X, BST->left);
		else if (X > BST->Data)
			BST->right = Insert(X, BST->right);
	}
	return BST;
}Postition CreateTree()
{
	BinTree BST = NULL;
	BinTree Root = NULL;
	BinTree Left = NULL;
	BinTree Right = NULL;
	while (1) {
		int num;
		
		scanf_s("%d", &num);
		if (num == -1) {
			/*-1作为结束循环的标志*/
			break;
		}
		BST = (BinTree)malloc(sizeof(struct TreeNode));
		if (!BST) {
			printf("申请失败");
			break;
		}/*验空*/
		BST->Data = num;
		BST->left = BST->right = NULL;
		if (!Root) {
			Root = BST;
		}
		else {
			/*向右创建新的结点来储存数据*/
			if (num > BST->Data) {
				Right = (BinTree)malloc(sizeof(struct TreeNode));
				if (!Right) {
					printf("申请内存失败");
					break;
				}
				Right->Data = num;
				Right->left = Right->right = NULL;
				BST->right = Right;
			}
			else {
				/*向左创建结点并储存数据*/
				Left = (BinTree)malloc(sizeof(struct TreeNode));
				if (!Left) {
					printf("申请内存失败");
					break;
				}
				Left->Data = num;
				Left->left = Left->right = NULL;
				BST->left = Left;
			}
		}
	}
	return Root;/*返回根结点的地址*/
}