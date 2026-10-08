#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode {
	int data;                       // 节点存储的数据
	struct TreeNode *left;          // 左子树指针
	struct TreeNode *right;         // 右子树指针
}TreeNode;

typedef struct Stack {
    TreeNode **arr;
    int top;
    int capacity;
} Stack;
Stack *createStack(int capacity) { //初始化Stack
    Stack *stack = malloc(sizeof(Stack));
    stack->arr = malloc(sizeof(TreeNode *) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}
int isEmpty(Stack *stack) { //判断是否为空
    return stack->top == -1;
}
void push(Stack *stack, TreeNode *node) {//压栈
    if (stack->top == stack->capacity - 1) {
        return;
    }
    stack->arr[++stack->top] = node;
}
TreeNode *pop(Stack *stack) {//弹栈
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->arr[stack->top--];
}

void preorderTraversal(TreeNode *root)
{
	Stack *s = createStack(7);
	push(s, root);
	while (!isEmpty(s))
	{
		TreeNode *r = pop(s);
		if (!r) continue;
		printf("%d ", r->data);
		push(s, r->right), push(s, r->left);
	}
}	// 补全这个函数

TreeNode *create_node(int data)
{
	TreeNode *r = (TreeNode *)malloc(sizeof(TreeNode));
	if (!r) exit(1);
	r->left = NULL, r->right = NULL;
	r->data = data;
	return r;
}

TreeNode *build(int x, int N)
{
	if (x > N) return NULL;
	TreeNode *r = create_node(x);
	r->data = x;
	r->left = build(2*x, N), r->right = build(2*x+1, N);
	return r;
}

void pre(TreeNode *r)
{
	if (!r) return;
	printf("%d ", r->data);
	pre(r->left), pre(r->right);
}

void mid(TreeNode *r)
{
	if (!r) return;
	mid(r->left);
	printf("%d ", r->data);
	mid(r->right);
}

void suf(TreeNode *r)
{
	if (!r) return;
	suf(r->left);
	suf(r->right);
	printf("%d ", r->data);
}

int max(int a, int b)
{
	return a>b? a: b;
}

int dep(TreeNode *r)
{
	if (!r) return 0;
	return 1+max(dep(r->left), dep(r->right));
}

int depth(TreeNode *r, int current_depth, int max_depth){
	if (!r) return max_depth; //返回最大深度
	max_depth = max(max_depth, current_depth);//更新最大深度
	int lmax = depth(r->left, current_depth+1, max_depth);
	int rmax = depth(r->right, current_depth+1, max_depth);
	return max(lmax, rmax);//返回左右子树最大深度
}


int main()
{
	TreeNode *root = NULL;
	root = build(1, 7);
	int cd = 1, md = 1;
	printf("%d %d\n", dep(root), depth(root, cd, md));
	pre(root);
	printf("\n");
	mid(root);
	printf("\n");
	suf(root);
	printf("\n");
	preorderTraversal(root);
	printf("\n");
	return 0;
}
