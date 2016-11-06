#include <bits/stdc++.h>

using namespace std;

int n, m, d[100010], a[100010], dd[100010];
bool ck[100010];

bool Try(int p) {
	memset(dd, 0, sizeof(dd));
	memset(ck, 0, sizeof(ck));

	int cnt = 0;

	for (int i = p; i >= 1; --i) {
		if (d[i] && !ck[d[i]]) {
			ck[d[i]] = true;
			dd[i] = d[i];
			++cnt;
		}
	}

	if (cnt < m) return false;

	int sum = 0;
	for (int i = 1; i <= p; ++i) {
		if (!dd[i]) {
			++sum;
		} else if (a[dd[i]] > sum) {
			return false;
		} else {
			sum -= a[dd[i]];
		}
	}
	return true;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", d+i);
	}

	for (int i = 1 ; i <= m; ++i) {
		scanf("%d", a+i);
	}

	int left = 1, right = n;
	while (left < right) {
		int mid = (left + right) / 2;
		if (Try(mid)) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}

	printf("%d\n", Try(left)?left:-1);
	return 0;
}