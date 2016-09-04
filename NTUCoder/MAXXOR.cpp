#include <bits/stdc++.h>

using namespace std;

const int MAX_BIT = 30;

struct Node {
	Node* child[2];
	Node() { child[0] = child[1] = NULL; }
};

int n, a[1010];
Node* root;

void update(Node* &node, int val, int pos) {
	if (node == NULL)
		node = new Node();

	if (pos < 0)
		return;

	int bit = (val >> pos) & 1;
	update(node->child[bit], val, pos-1);
}

int find(Node* node, int val, int pos) {
	if (pos < 0)
		return 0;

	int bit = (val >> pos) & 1;

	if (node->child[1-bit] != NULL)
		return ((1 << pos) | find(node->child[1-bit], val, pos-1));
	return find(node->child[bit], val, pos-1);
}

int main() {
	scanf("%d", &n);

	update(root, 0, MAX_BIT);

	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
		for (int j = 0; j < i; ++j)
			update(root, a[i]^a[j], MAX_BIT);
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		res = max(res, find(root, a[i], MAX_BIT));
	}

	printf("%d\n", res);
	return 0;
}