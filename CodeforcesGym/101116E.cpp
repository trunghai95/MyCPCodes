#include <bits/stdc++.h>

using namespace std;

const int MAXN = 40009;

int test, n1, n2, m;
bool U[MAXN], V[MAXN], ck[MAXN];
map<string, int> id;
string name[MAXN];
char s[20], t[20];

int getId(string& s) {
	if (id.find(s) == id.end()) {
		int tmp = (id[s] = id.size());
		name[tmp] = s;
		return tmp;
	}
	return id[s];
}

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		id.clear();
		memset(U, 0, sizeof(U));
		memset(V, 0, sizeof(V));
		memset(ck, 0, sizeof(ck));
		scanf("%d %d %d", &n1, &n2, &m);

		vector<int> adj[MAXN];
		queue<int> q;

		for (int i = 0; i < n1; ++i) {
			scanf("%s", s);
			string tmp(s);
			int d = getId(tmp);
			U[d] = true;
			q.push(d);
			ck[d] = true;
		}

		for (int i = 0; i < n2; ++i) {
			scanf("%s", s);
			string tmp(s);
			int d = getId(tmp);
			V[d] = true;
		}

		for (int i = 0; i < m; ++i) {
			scanf("%s %s", s, t);
			string tmp1(s);
			string tmp2(t);
			int u = getId(tmp1);
			int v = getId(tmp2);
			adj[u].push_back(v);
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int i = 0; i < (int)adj[u].size(); ++i) {
				int v = adj[u][i];
				if (!ck[v]) {
					ck[v] = true;
					q.push(v);
				}
			}
		}

		vector<string> res;

		for (int i = 1; i <= (int)id.size(); ++i) {
			if (ck[i] && V[i]) {
				res.push_back(name[i]);
			}
		}
		sort(res.begin(), res.end());
		for (int i = 0; i < (int)res.size(); ++i) {
			printf("%s ", res[i].c_str());
		}
		printf("\n");
	}
	return 0;
}