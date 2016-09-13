#include <bits/stdc++.h>

using namespace std;

struct Node {
	int val;
	Node *child[26];

	Node(): val(0) {
		memset(child, 0, sizeof(child));
	}
};

int n, m, res;
char s[510];
Node* root;

void update(Node *&node, const int& pos, const int& cnt) {
	if (node == NULL)
		node = new Node();

	if (s[pos] == 0) {
		node->val += cnt;
		return;
	}

	update(node->child[s[pos] - 'A'], pos+1, cnt);
}

int visit(Node *&node, const int& pos) {
	for (int i = 0; i < 26; ++i)
	if (node->child[i] != NULL) {
		node->val += visit(node->child[i], pos+1);
	}

	if (pos >= m && node->val > 0) {
		++res;
		--node->val;
	}

	int res = node->val;

	delete node;
	node = NULL;

	return res;
}

int main() {

	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0)
			return 0;

		for (int i = 0, cnt; i < n; ++i) {
			scanf("%d %s", &cnt, s);
			update(root, 0, cnt);
		}

		res = 0;
		visit(root, 0);

		printf("%d\n", res);
	}

	return 0;
}