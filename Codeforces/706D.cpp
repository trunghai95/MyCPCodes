#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node* child[2];
	int cnt;
	Node() { child[0] = child[1] = NULL; cnt = 0; }
};

#define MAX_BIT 30

int n, x;
char type[3];
Node* root;

void add(Node* node = root, int pos = MAX_BIT)
{
	if (pos < 0)
		return;

	int bit = (x >> pos) & 1;
	if (node->child[bit] == NULL)
		node->child[bit] = new Node();
	++node->child[bit]->cnt;
	add(node->child[bit], pos - 1);
}

void remove(Node* node = root, int pos = MAX_BIT)
{
	if (pos < 0)
		return;

	int bit = (x >> pos) & 1;
	remove(node->child[bit], pos - 1);
	if (--node->child[bit]->cnt == 0)
	{
		delete node->child[bit];
		node->child[bit] = NULL;
	}
}

int query(Node* node = root, int pos = MAX_BIT)
{
	if (pos < 0)
		return 0;

	int bit = (x >> pos) & 1;
	if (node->child[1 - bit] != NULL)
		return query(node->child[1 - bit], pos - 1) | (1 << pos);
	return query(node->child[bit], pos - 1);
}

int main()
{
	root = new Node();

	add();

	scanf("%d", &n);

	while (n--)
	{
		scanf("%s %d", type, &x);

		if (type[0] == '+')
			add();
		else if (type[0] == '-')
			remove();
		else
			printf("%d\n", query());
	}
	return 0;
}