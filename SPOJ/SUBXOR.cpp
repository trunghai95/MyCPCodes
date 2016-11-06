#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXBIT = 22;

struct Node {
	Node* child[2];
	int cnt;

	Node(): cnt(0) {
		memset(child, 0, sizeof(child));
	}
};

int test, n, k, a[100010];
ll res;
Node* root;

void add(Node *&node, int val, int pos) {
	if (node == NULL) node = new Node();
	++(node->cnt);
	if (pos < 0) return;

	int bit = ((val >> pos) & 1);
	add(node->child[bit], val, pos-1);
}

int get(Node *node, int val, int pos) {
	if (node == NULL || pos < 0) return 0;

	int bitval = ((val >> pos) & 1);
	int bitk = ((k >> pos) & 1);
	int res = 0;

	if (bitk == 1) {
		if (node->child[bitval])
			res += node->child[bitval]->cnt;
		res += get(node->child[1-bitval], val, pos-1);
	} else {
		res += get(node->child[bitval], val, pos-1);
	}

	return res;
}

void clear(Node *&node) {
	if (node == NULL) return;
	clear(node->child[0]);
	clear(node->child[1]);
	delete node;
	node = NULL;
}

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d %d", &n, &k);
		res = 0;
		add(root, 0, MAXBIT);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a+i);
			a[i] ^= a[i-1];
			res += get(root, a[i], MAXBIT);
			add(root, a[i], MAXBIT);
		}

		printf("%lld\n", res);
		clear(root);
	}
	return 0;
}