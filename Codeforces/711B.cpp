#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, ex, ey;
ll a[510][510], sum1, sum2;

int main() {
	scanf("%d", &n);

	sum1 = sum2 = -1;

	for (int i = 1; i <= n; ++i) {
		ll tmp = 0;
		for (int j = 1; j <= n; ++j) {
			scanf("%lld", a[i] + j);
			tmp += a[i][j];
			if (!a[i][j])
				ex = i, ey = j;
		}

		if (ex == i)
			sum1 = tmp;
		else if (sum2 == -1)
			sum2 = tmp;
		else if (sum2 != tmp) {
			printf("-1\n");
			return 0;
		}
	}

	if (n == 1) {
		printf("1\n");
		return 0;
	}

	if (sum2 <= sum1) {
		printf("-1\n");
		return 0;
	}

	a[ex][ey] = sum2 - sum1;

	for (int j = 1; j <= n; ++j) {
		ll tmp = 0;
		for (int i = 1; i <= n; ++i)
			tmp += a[i][j];
		if (sum2 != tmp) {
			printf("-1\n");
			return 0;
		}
	}

	ll tmp = 0;
	for (int i = 1; i <= n; ++i)
		tmp += a[i][i];
	if (sum2 != tmp) {
		printf("-1\n");
		return 0;
	}

	tmp = 0;
	for (int i = 1; i <= n; ++i)
		tmp += a[i][n-i+1];
	if (sum2 != tmp) {
		printf("-1\n");
		return 0;
	}

	printf("%lld\n", a[ex][ey]);
	return 0;
}