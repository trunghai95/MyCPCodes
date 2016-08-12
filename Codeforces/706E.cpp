#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node *r, *d;
	int val;

	Node() { r = d = NULL; val = 0; }
};

int n, m, q, a, b, c, d, h, w;
Node node[1010][1010];

Node* getNode(int x, int y)
{
	Node* res = &node[0][0];

	for (int i = 1; i <= x; ++i)
		res = res->d;
	for (int i = 1; i <= y; ++i)
		res = res->r;

	return res;
}

void printMat()
{
	Node *root = &node[0][0];

	for (int i = 1; i <= n; ++i)
	{
		root = root->d;
		Node *row = root;

		for (int j = 1; j <= m; ++j)
		{
			row = row->r;
			printf("%d ", row->val);
		}

		printf("\n");
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);

	for (int i = 0; i <= n; ++i)
	{
		node[i][0].r = &node[i][1];
		node[i][0].d = &node[i+1][0];
	}

	for (int j = 0; j <= m; ++j)
	{
		node[0][j].r = &node[0][j+1];
		node[0][j].d = &node[1][j];
	}

	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	{
		scanf("%d", &node[i][j].val);
		node[i][j].r = &node[i][j+1];
		node[i][j].d = &node[i+1][j];
	}

	while (q--)
	{
		scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &h, &w);

		if (h == 1)
		{
			Node *n1 = getNode(a, b-1), *n2 = getNode(c, d-1);

			for (int i = 0; i < w; ++i)
			{
				n1 = n1->r;
				n2 = n2->r;
				swap(n1->val, n2->val);
			}
			continue;
		}
		else if (w == 1)
		{
			Node *n1 = getNode(a-1, b), *n2 = getNode(c-1, d);

			for (int i = 0; i < h; ++i)
			{
				n1 = n1->d;
				n2 = n2->d;
				swap(n1->val, n2->val);
			}
			continue;
		}

		Node *r1 = getNode(a-1, b-1), *r2 = getNode(c-1, d-1);
		Node *r3 = getNode(a-1, b+w-1), *r4 = getNode(c-1, d+w-1);
		Node *r5 = getNode(a+h-1, b-1), *r6 = getNode(c+h-1, d-1);

		Node *n1 = r1, *n2 = r2;
		for (int i = 0; i < h; ++i)
		{
			n1 = n1->d, n2 = n2->d;
			swap(n1->r, n2->r);
		}
		n1 = r1, n2 = r2;
		for (int i = 0; i < w; ++i)
		{
			n1 = n1->r, n2 = n2->r;
			swap(n1->d, n2->d);
		}
		n1 = r3, n2 = r4;
		for (int i = 0; i < h; ++i)
		{
			n1 = n1->d, n2 = n2->d;
			swap(n1->r, n2->r);
		}
		n1 = r5, n2 = r6;
		for (int i = 0; i < w; ++i)
		{
			n1 = n1->r, n2 = n2->r;
			swap(n1->d, n2->d);
		}
	}

	printMat();

	return 0;
}