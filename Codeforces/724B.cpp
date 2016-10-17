#include <bits/stdc++.h>

using namespace std;

int n, m, a[30][30], b[30];

bool check() {
	for (int i = 2; i <= m; ++i) {
		if (b[i] < b[i-1])
			return false;
	}
	return true;
}

bool Try1(int u, int v, int k) {
	memcpy(b + 1, a[k] + 1, m*sizeof(int));
	swap(b[u], b[v]);

	for (int i = 1; i <= m; ++i)
	for (int j = i; j <= m; ++j) {
		swap(b[i], b[j]);
		if (check()) {
			return true;
		}
		swap(b[i], b[j]);
	}

	return false;
}

bool Try2(int u, int v, int k) {
	memcpy(b + 1, a[k] + 1, m*sizeof(int));

	for (int i = 1; i <= m; ++i)
	for (int j = i; j <= m; ++j) {
		swap(b[i], b[j]);
		swap(b[u], b[v]);
		if (check()) {
			return true;
		}
		swap(b[u], b[v]);
		swap(b[i], b[j]);
	}

	return false;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j) {
		scanf("%d", a[i] + j);
	}

	for (int i = 1; i <= m; ++i)
	for (int j = i; j <= m; ++j) {
		bool ok = true;
		for (int k = 1; ok && k <= n; ++k) {
			if (!Try1(i, j, k) || !Try2(i, j, k))
				ok = false;
		}

		if (ok) {
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");
	return 0;
}