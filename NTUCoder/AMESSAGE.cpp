#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node* child[2];
	int cnt, childCnt;
	Node(): cnt(0), childCnt(0) { memset(child, 0, sizeof(child)); }
};

void update(Node *root, int* arr, int n)
{
	if (n == 0)
	{
		++(root->cnt);
		return;
	}

	if (root->child[arr[0]] == NULL)
		root->child[arr[0]] = new Node();

	update(root->child[arr[0]], arr+1, n-1);
	++(root->childCnt);
}

int get(Node *root, int* arr, int n)
{
	if (n == 0)
		return root->cnt + root->childCnt;

	if (root->child[arr[0]] != NULL)
		return root->cnt + get(root->child[arr[0]], arr+1, n-1);
	else
		return root->cnt;
}

int arr[10010], m, n, l;
Node* root;

int main()
{
	root = new Node();
	scanf("%d %d", &m, &n);

	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &l);

		for (int j = 0; j < l; ++j)
			scanf("%d", arr+j);

		update(root, arr, l);
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &l);

		for (int j = 0; j < l; ++j)
			scanf("%d", arr+j);

		printf("%d\n", get(root, arr, l));
	}
	return 0;
}