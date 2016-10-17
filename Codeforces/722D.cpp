#include <bits/stdc++.h>

using namespace std;

const int MAX_BIT = 30;

struct Node {
	int cnt;
	Node* child[2];
	Node() { memset(child, 0, sizeof(child)); cnt = 0; }
};

int n, a;
vector<int> res;
Node* root;

int popCount(int a) {
	int res = 0;
	while (a) {
		++res;
		a >>= 1;
	}
	return res;
}

void insert(Node *& node, const int& val, const int& pos) {
	if (node == NULL) {
		node = new Node();
	}

	++node->cnt;

	if (pos < 0) {
		return;
	}

	int bit = ((val >> pos) & 1);
	insert(node->child[bit], val, pos - 1);
}

void solve(Node *node, const int& val) {
	if ((int)res.size() >= n) {
		return;
	}

	if (node != root) {
		--node->cnt;
	}

	int sum = 0;
	if (node->child[0] != NULL)
		sum += node->child[0]->cnt;
	if (node->child[1] != NULL)
		sum += node->child[1]->cnt;
	if (sum > node->cnt) {
		if (node->child[1] != NULL) {
			node->child[1]->cnt = max(0, node->child[1]->cnt - (sum - node->cnt));
			sum = node->cnt;
		}
		if (node->child[0] != NULL) {
			node->child[0]->cnt = max(0, node->child[0]->cnt - (sum - node->cnt));
		}
	}

	if (node->child[0] != NULL && node->child[0]->cnt) {
		res.push_back(val << 1);
	}

	if (node->child[1] != NULL && node->child[1]->cnt) {
		res.push_back((val << 1) | 1);
	}

	if (node->child[0] != NULL && node->child[0]->cnt) {
		solve(node->child[0], val << 1);
	}

	if (node->child[1] != NULL && node->child[1]->cnt) {
		solve(node->child[1], (val << 1) | 1);
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		int p = popCount(a);
		insert(root, a, p - 1);
	}

	solve(root, 0);
	for (int i = 0; i < n; ++i) {
		printf("%d ", res[i]);
	}
	printf("\n");
	return 0;
}