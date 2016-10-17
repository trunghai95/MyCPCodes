#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, n, k, a[101][101];

struct Node {
	int data[101];
	int sum;

	Node() { memset(data, 0, sizeof(data)); sum = 0; }
	Node(const Node& node) {
		memcpy(this->data, node.data, sizeof(node.data));
		this->sum = node.sum;
	}

	ll hash() {
		ll res = 0;
		for (int i = 1; i <= n; ++i) {
			res = res * 101 + data[i];
		}
		return res;
	}
};

struct cmp {
	bool operator()(const Node& x, const Node& y) {
		return x.sum > y.sum;
	}
};

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d %d", &n, &k);

		for (int i = 1; i <= n; ++i) {
			scanf("%d", a[i]);
			for (int j = 1; j <= a[i][0]; ++j) {
				scanf("%d", a[i] + j);
			}
			sort(a[i]+1, a[i]+1+a[i][0]);
		}

		set<ll> alrd;

		Node u;
		for (int i = 1; i <= n; ++i) {
			u.data[i] = 1;
			u.sum += a[i][1];
		}

		priority_queue<Node, vector<Node>, cmp> heap;
		int cnt = 0;
		heap.push(u);

		while (true) {
			u = heap.top();
			heap.pop();

			ll h = u.hash();
			if (alrd.find(h) != alrd.end()) {
				continue;
			}

			alrd.insert(h);
			++cnt;
			printf("%d ", u.sum);
			if (cnt == k) {
				break;
			}

			for (int i = 1; i <= n; ++i)
			if (u.data[i] < a[i][0]) {
				Node v(u);
				v.sum += a[i][u.data[i] + 1] - a[i][u.data[i]];
				++v.data[i];

				h = v.hash();
				if (alrd.find(h) != alrd.end()) {
					continue;
				}
				heap.push(v);
			}
		}
		printf("\n");
	}
	return 0;
}