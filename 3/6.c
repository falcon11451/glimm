#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TREE_SIZE 100
#define SeqBiTree SBT
/*
 *  * 顺序存储二叉树结点
 *   *  - data：结点数据
 *    * - used：当前位置是否有结点
 *     */
typedef struct {
	int data;
	bool used;
} SeqTreeNode;

/*
 *  * 顺序存储二叉树
 *   * - nodes：结点数组
 *    * - size：数组最大容量
 *     */
typedef struct {
	SeqTreeNode nodes[MAX_TREE_SIZE];
	int size;
} SeqBiTree;

void init(SeqBiTree *sbt)
{
	sbt->size = 0;
	for (int i = 0; i < MAX_TREE_SIZE; i++)
		sbt->nodes[i].data = 0, sbt->nodes[i].used = false;
}

void set_root(SBT *t, int val)
{
	t->nodes[1].data = val;
	t->nodes[1].used = true;
	t->size++;
}

//合并set_left_child和set_right_child
void set_child(SeqBiTree *t, int parent_node, int val, int opt) // opt:0左1右
{
	if (opt)
	{
		t->nodes[parent_node*2+1].data = val;
		t->nodes[parent_node*2+1].used = true;
		t->size++;
	}
	else
	{
		t->nodes[parent_node*2].data = val;
		t->nodes[parent_node*2].used = true;
		t->size++;
	}
}

void level_order(SeqBiTree *t)
{
	for (int i = 0; 1<<i <= t->size; i++)
	{
		for (int j = 1<<i; j < 1<<(i+1); j++)
		{
			if (!t->nodes[j].used) printf("-1 ");
			else printf("%d ", t->nodes[j].data);
		}
		printf("\n");
	}
}

signed main()
{
	SBT *sbt = (SBT *)malloc(sizeof(SBT));
	init(sbt);
	set_root(sbt, 1);
	set_child(sbt, 1, 2, 0);
	set_child(sbt, 1, 3, 1);
	set_child(sbt, 2, 4, 0);
	set_child(sbt, 2, 5, 1);
	set_child(sbt, 3, 6, 0);
	set_child(sbt, 3, 7, 1);
	level_order(sbt);
	free(sbt);
	sbt = NULL;	
	return 0;
}
