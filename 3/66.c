#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;                       // 节点存储的数据
    struct TreeNode *left;          // 左子树指针
    struct TreeNode *right;         // 右子树指针
} TreeNode;

TreeNode *create(int val)
{
	TreeNode *r = (TreeNode *)malloc(sizeof(TreeNode));
	if (!r) exit(1);
	r->data = val;
	r->left = NULL, r->right = NULL;
	return r;
}

signed main()
{
	TreeNode *root = create(1);
	root->left = create(2), root->right = create(3);
	root->left->left = create(4), root->left->right = create(5);
	root->right->left = create(6), root->right->right = create(7);
	return 0;
}
