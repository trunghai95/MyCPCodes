#include <bits/stdc++.h>

using namespace std;

int n, m, f[60], res = 2e9;

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) {
		scanf("%d", f+i);
	}

	sort(f, f+m);

	for (int i = 0; i <= m - n; ++i)
		res = min(res, f[i + n - 1] - f[i]);

	printf("%d\n", res);
	return 0;
}