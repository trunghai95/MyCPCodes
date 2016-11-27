#include <bits/stdc++.h>

using namespace std;

int test, n, a[60], f[60][60];

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a+i);
		}
		a[0] = a[n+1] = 1;
		memset(f, 0, sizeof(f));

		++n;

		for (int j = 0; j <= n; ++j)
		for (int i = j-2; i >= 0; --i)
		for (int k = i+1; k < j; ++k) {
			f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[k] * min(a[i], a[j]));
		}

		// for (int i = 0; i <= n; ++i)
		// for (int j = i+1; j <= n; ++j)
		// 	cout << i << ' ' << j << ' ' << f[i][j] << '\n';


		printf("%d\n", f[0][n]);
	}
	return 0;
}