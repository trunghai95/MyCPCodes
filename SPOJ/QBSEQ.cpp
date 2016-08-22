#include <bits/stdc++.h>

using namespace std;

int n, a[1010], k, f[1010][50];

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
		a[i] %= k;
	}

	int res = 0;

	for (int i = 0; i < n; ++i) {
		f[i][a[i]] = 1;
		for (int j = 0; j < i; ++j)
		for (int r = 0; r < k; ++r)
		if (f[j][r]) {
			f[i][(r + a[i]) % k] = max(f[i][(r + a[i]) % k], f[j][r] + 1);
		}

		res = max(res, f[i][0]);
	}

	printf("%d\n", res);

	return 0;
}