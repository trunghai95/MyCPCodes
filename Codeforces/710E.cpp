#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const int MAX = 10000001;

struct cmp {
	bool operator()(const pli& x, const pli& y) {
		return x.first > y.first;
	}
};

int n;
ll x, y, dist[MAX];
bool ck[MAX];

int main() {
	clock_t A = clock();
	scanf("%d %lld %lld", &n, &x, &y);

	memset(dist, -1, sizeof(dist));
	priority_queue<pli, vector<pli>, cmp> heap;

	heap.push(pli(0, 0));
	dist[0] = 0;

	while (!heap.empty()) {
		int u = heap.top().second;
		heap.pop();

		if (u == n) {
			printf("%lld\n", dist[n]);
			cout << (clock() - A) / 1000 << '\n';
			return 0;
		}

		if (ck[u])
			continue;

		ck[u] = true;

		int v = u+1;
		if (v <= n && (dist[v] == -1 || dist[v] > dist[u] + x)) {
			dist[v] = dist[u] + x;
			heap.push(pli(dist[v], v));
		}

		v = u-1;
		if (v > 0 && (dist[v] == -1 || dist[v] > dist[u] + x)) {
			dist[v] = dist[u] + x;
			heap.push(pli(dist[v], v));
		}

		v = u*2;
		if (v <= n) {
			if (dist[v] == -1 || dist[v] > dist[u] + y) {
				dist[v] = dist[u] + y;
				heap.push(pli(dist[v], v));
			}
		} else {
			if (dist[n] == -1 || dist[n] > dist[u] + y + x*(v - n)) {
				dist[n] = dist[u] + y + x*(v - n);
				heap.push(pli(dist[n], n));
			}
		}
	}

	return 0;
}