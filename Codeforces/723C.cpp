//WA

#include <bits/stdc++.h>

using namespace std;

int n, m, a[2010], cnt[2010];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
		if (a[i] <= m) {
			++cnt[a[i]];
		}
	}

	if (m == 1) {
		printf("%d %d\n", n, n - cnt[1]);
		for (int i = 1; i <= n; ++i) {
			printf("1 ");
		}
		printf("\n");
		return 0;
	}

	int res = 0;

	for (int i = 1; i <= n; ++i) {
		if (a[i] <= m && cnt[a[i]] <= n/m + 1) {
			continue;
		}

		int mni = 1;
		for (int j = 2; j <= m; ++j) {
			if (cnt[j] < cnt[mni]) {
				mni = j;
			}
		}

		if (cnt[mni] == n/m) {
			break;
		}

		if (a[i] <= m) {
			--cnt[a[i]];
		}

		a[i] = mni;
		++cnt[mni];
		++res;
	}

	for (int i = 1; i <= n; ++i) {
		if (a[i] <= m && cnt[a[i]] <= n/m) {
			continue;
		}

		int mni = 1;
		for (int j = 2; j <= m; ++j) {
			if (cnt[j] < cnt[mni]) {
				mni = j;
			}
		}

		if (cnt[mni] == n/m) {
			break;
		}

		if (a[i] <= m) {
			--cnt[a[i]];
		}

		a[i] = mni;
		++cnt[mni];
		++res;
	}

	printf("%d %d\n", n/m, res);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}