#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node *nxt;
} Node;

Node *head, *tail;

Node *create(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) exit(1);
    n->val = val;
    n->nxt = NULL;
    return n;
}

void addToHead(Node *h, int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) exit(1);
    n->val = val;
    n->nxt = h->nxt;
    h->nxt = n;
}

Node *findTail(Node *h) {
    Node *t = h;
    while (t->nxt) t = t->nxt;
    tail = t;
    return t;
}

void addToTail(Node **t, int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) exit(1);
    n->val = val;
    n->nxt = NULL;
    (*t)->nxt = n;
    *t = n;
}
int find(Node *h, int val) {
    int i = 0;
    for (Node *n = h; n; n = n->nxt, i++)
        if (n->val == val) return i;
    return -1; //未找到返回-1
}

bool del(Node *h, int n) {
    if (!h || n < 1) return false;
    Node *p = h, *t = h->nxt;
    int i = 1;
    while (t && i < n) {
        p = t;
        t = t->nxt;
        i++;
    }
    if (!t) return false;
    p->nxt = t->nxt;
    free(t);
    return true;
}

void reverse(Node *h) {
    if (!h || !h->nxt) return;
    tail = h->nxt;
    Node *pre = NULL, *cur = h->nxt;
    while (cur)
    {
	    Node *tmp = cur->nxt;
	    cur->nxt = pre;
	    pre = cur, cur = tmp;
    }
    head->nxt = pre;
}

void print(Node *h) {
    for (Node *n = h; n; n = n->nxt)
        printf("%d ", n->val);
    printf("\n");
}

int main() {
    head = create(0);
    for (int i = 1; i <= 5; i++)
        addToHead(head, i);
    findTail(head);
    for (int i = 1; i <= 5; i++)
        addToTail(&tail, i);
    print(head);
    printf("%d\n", find(head, 2));
    printf("%d\n", find(head, 12));
    del(head, 2);
    print(head);
    reverse(head);
    print(head);
    reverse(head);
    print(head);
    return 0;
}
