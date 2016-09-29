#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, p[100010], mx;
ll cnt[100010], res;

void Try(int u, int v) {
	if (p[v] == mx) {
		res = min(res, (ll)mx+1);
		return;
	}

	if (p[v] + 1 == mx) {
		return;
	}

	if (p[u] == mx) {
		if (cnt[mx] == 1) {
			res = min(res, (mx - 1) * (cnt[mx - 1] + 1 + (p[v] + 1 == mx - 1)));
		} else {
			res = min(res, mx * (cnt[mx] - 1));
		}
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", p+i), ++cnt[p[i]], mx = max(mx, p[i]);

	res = mx * cnt[mx];

	for (int i = 0; i < n; ++i)
	if (p[i]) {
		if (i > 0) {
			Try(i, i-1);
		} else if (i < n-1) {
			Try(i, i+1);
		}
	}

	printf("%lld\n", res);
	return 0;
}