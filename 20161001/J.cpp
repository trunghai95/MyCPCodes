#include <bits/stdc++.h>

using namespace std;

int n;
map<string, int> id;
string name[40], str;
vector<int> adj[40];
int pre[40];
bool ck[40];

int getId(const string& s) {
	if (id.find(s) == id.end()) {
		int tmp = (id[s] = id.size());
		name[tmp] = s;
		return tmp;
	}
	return id[s];
}

int main() {

	cin >> n;
	getline(cin, str);

	for (int i = 0; i < n; ++i) {
		getline(cin, str);
		stringstream sstr(str);
		sstr >> str;
		int u = getId(str);
		while (sstr >> str) {
			int v = getId(str);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	cin >> str;
	int s = getId(str);
	cin >> str;
	int t = getId(str);

	memset(pre, -1, sizeof(pre));
	queue<int> q;
	q.push(s);
	ck[s] = true;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (u == t) {
			break;
		}

		for (int i = 0; i < (int)adj[u].size(); ++i) {
			int v = adj[u][i];
			if (!ck[v]) {
				ck[v] = true;
				q.push(v);
				pre[v] = u;
			}
		}
	}

	if (pre[t] == -1) {
		cout << "no route found\n";
		return 0;
	}

	vector<int> res;
	while (t != -1) {
		res.push_back(t);
		t = pre[t];
	}

	for (int i = res.size() - 1; i >= 0; --i) {
		cout << name[res[i]] << ' ';
	}
	cout << '\n';
	return 0;
}