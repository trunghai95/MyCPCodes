#include <bits/stdc++.h>

using namespace std;

int test, n, m, a[30];

int main() {
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt) {
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; ++i) {
			scanf("%d", a+i);
		}

		sort(a, a+n);

		int sum = 0, pen = 0;
		for (int i = 0; i < n; ++i) {
			sum += a[i];
			pen += sum;
			if (sum > m) {
				printf("Case %d: %d %d %d\n", tt, i, sum - a[i], pen - sum);
				break;
			}
		}

		if (sum <= m) {
			printf("Case %d: %d %d %d\n", tt, n, sum, pen);
		}
	}
	return 0;
}