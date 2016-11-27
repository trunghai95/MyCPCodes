#include <bits/stdc++.h>

using namespace std;

struct Node {
	int cntAdj;
	int par;
	vector<int> win;
	Node(): cntAdj(0) {}
};

const int MAXN = 2000009;
Node node[MAXN];
int n;

int main() {
	scanf("%d", &n);
	for (int v = 2; v <= n; ++v) {
		scanf("%d", &node[v].par);
		++node[node[v].par].cntAdj;
		++node[v].cntAdj;
	}

	for (int u = n; u >= 2; --u) {
		if (node[u].cntAdj == 1 || node[u].win.size() == 0) {
			node[node[u].par].win.push_back(u);
		}
	}

	int s = 2;
	if (node[1].cntAdj == 1) {
		node[2].win.push_back(1);
		s = 3;
	}

	for (int u = s; u <= n; ++u) {
		int v = node[u].par;
		int cntWin = (int)node[v].win.size();
		int p = lower_bound(node[v].win.begin(),node[v].win.end(),u,greater<int>()) - node[v].win.begin();
		if (p < (int)node[v].win.size() && node[v].win[p] == u)
			--cntWin;
		if (cntWin == 0) {
			node[u].win.push_back(v);
		}
	}

	for (int u = 1; u <= n; ++u) {
		if (node[u].win.size() == 0) {
			printf("%d\n", u);
		}
	}
	return 0;
}