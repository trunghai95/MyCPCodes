#include <bits/stdc++.h>

using namespace std;

int n, a[10], gt[11], dist[2][3700000], cache[10];

int code(int *a) {
	int res = 0, cnt;

	for (int i = 0; i < n; ++i) {
		cnt = 0;
		for (int j = i + 1; j < n; ++j) {
			cnt += (a[j] < a[i]);
		}
		res += cnt * gt[n - i - 1];
	}

	return res;
}

struct Node {
	int data[10], val;

	Node(): val(0) {}
	Node(int *a) {
		memcpy(data, a, n*sizeof(int));
		val = code(data);
	}
	Node(int *a, int v): val(v) {
		memcpy(data, a, n*sizeof(int));
	}
};

int main() {
	gt[0] = 1;
	for (int i = 1; i <= 10; ++i)
		gt[i] = gt[i-1]*i;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
	}

	queue<Node> q;
	Node s(a);
	q.push(s);
	dist[0][s.val] = 1;

	while (!q.empty()) {
		Node u = q.front();
		q.pop();

		if (!u.val) {
			printf("%d\n", dist[0][u.val] - 1);
			return 0;
		}

		if (dist[0][u.val] >= 3)
			continue;

		for (int i = -1; i < n; ++i)
		for (int j = i; j < n; ++j)
		for (int k = j; k < n; ++k) {
			// cadb
			memcpy(cache, u.data + j + 1, (k - j) * sizeof(int));
			memcpy(cache + k - j, u.data, (i + 1) * sizeof(int));
			memcpy(cache + k - j + i + 1, u.data + k + 1, (n - 1 - k) * sizeof(int));
			memcpy(cache + n + i - j, u.data + i + 1, (j - i) * sizeof(int));

			int tmp = code(cache);
			if (!dist[0][tmp]) {
				dist[0][tmp] = dist[0][u.val] + 1;
				q.push(Node(cache, tmp));
			}
		}
	}

	for (int i = 0; i < n; ++i)
		s.data[i] = i;
	s.val = 0;
	q.push(s);
	dist[1][0] = 1;

	while (!q.empty()) {
		Node u = q.front();
		q.pop();
		if (dist[1][u.val] >= 4)
			continue;

		for (int i = -1; i < n; ++i)
		for (int j = i; j < n; ++j)
		for (int k = j; k < n; ++k) {
			// bdac
			memcpy(cache, u.data + i + 1, (j - i) * sizeof(int));
			memcpy(cache + j - i, u.data + k + 1, (n - 1 - k) * sizeof(int));
			memcpy(cache + j - i + n - 1 - k, u.data, (i + 1) * sizeof(int));
			memcpy(cache + n + j - k, u.data + j + 1, (k - j) * sizeof(int));

			int tmp = code(cache);
			if (!dist[1][tmp]) {
				dist[1][tmp] = dist[1][u.val] + 1;
				q.push(Node(cache, tmp));
			}
		}
	}

	int res = 6;
	for (int i = 0; i < gt[n]; ++i)
	if (dist[0][i] && dist[1][i])
		res = min(res, dist[0][i] + dist[1][i] - 2);

	printf("%d\n", res);

	return 0;
}