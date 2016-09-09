#include <bits/stdc++.h>

using namespace std;

struct Node {
	Node* child[26];
	bool isEnd;

	Node() {
		memset(child, 0, sizeof(child));
		isEnd = false;
	}
};

const int MODD = 1337377;
char s[300010], t[111];
int n, len, res[300010];
Node *root;

void update(Node* &node, int pos) {
	if (node == NULL)
		node = new Node();

	if (t[pos] == 0) {
		node->isEnd = true;
		return;
	}

	int a = t[pos] - 'a';
	update(node->child[a], pos+1);
}

void proc(Node* node, int pos, int poss) {
	if (s[poss + pos] == 0 || node == NULL)
		return;

	int a = s[poss + pos] - 'a';
	if (node->child[a] != NULL && node->child[a]->isEnd) {
		res[pos + poss + 1] = (res[pos + poss + 1] + res[poss]) % MODD;
	}
	proc(node->child[a], pos+1, poss);
}

int main() {
	scanf("%s %d", s, &n);
	len = strlen(s);

	for (int i = 0; i < n; ++i) {
		scanf("%s", t);
		update(root, 0);
	}

	res[0] = 1;
	for (int i = 0; i < len; ++i) {
		proc(root, 0, i);
	}

	printf("%d\n", res[len]);
	return 0;
}