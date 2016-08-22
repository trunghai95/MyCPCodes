#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node {
	ll x, y, r, tu, mau;
};

int n;
Node node[1010];
vector<int> adj[1010];
int ck[1010];

void reduce(ll &x, ll &y) {
	ll g = __gcd(x, y);
	x /= g;
	y /= g;
}

void solve() {
	queue<int> q;
	q.push(1);
	ck[1] = 1;
	node[1].tu = node[1].mau = 1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < (int)adj[u].size(); ++i) {
			int v = adj[u][i];
			ll g = __gcd(node[u].r, node[v].r);
			if (!ck[v]) {
				q.push(v);
				ck[v] = -ck[u];
				node[v].tu = node[u].r / g * node[u].tu;
				node[v].mau = node[v].r / g * node[u].mau;
				reduce(node[v].tu, node[v].mau);
			} else {
				if (ck[u] == ck[v]) {
					printf("The input gear cannot move.\n");
					return;
				} else {
					ll t1, m1, t2, m2;
					t1 = node[u].tu * node[u].r / g;
					t2 = node[v].tu * node[v].r / g;
					m1 = node[u].mau;
					m2 = node[v].mau;
					reduce(t1, m1);
					reduce(t2, m2);
					if (t1 != t2 || m1 != m2) {
						printf("The input gear cannot move.\n");
						return;
					}
				}
			}
		}
	}

	if (!ck[n]) {
		printf("The input gear is not connected to the output gear.\n");
	} else {
		printf("%lld:%lld\n", node[n].tu*ck[n], node[n].mau);
	}
}

ll dist(const Node& a, const Node& b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%lld %lld %lld", &node[i].x, &node[i].y, &node[i].r);

		for (int j = 1; j < i; ++j)
		if (dist(node[i], node[j]) == (node[i].r + node[j].r)*(node[i].r + node[j].r)) {
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}

	solve();
	return 0;
}