#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
int a, b, t, k;
ll f[200010], sum[200010], g[200010], res;

ll& F(int x) { return f[x+100001]; }
ll& G(int x) { return g[x+100001]; }
ll& SUM(int x) { return sum[x + 100001]; }

int main() {

	scanf("%d %d %d %d", &a, &b, &k, &t);

	F(0) = 1;

	for (int i = 0; i < t; ++i) {
		int mx = k*i;

		for (int j = -mx; j <= mx; ++j) {
			G(j - k) += F(j);
			G(j + k + 1) -= F(j);
		}

		mx += k;
		for (int j = -mx; j <= mx; ++j)
			G(j) = (G(j) + G(j-1) + MODD) % MODD;
		memcpy(f, g, sizeof(g));
		memset(g, 0, sizeof(f));
	}

	for (int i = k*t; i >= -k*t; --i) {
		SUM(i) = (SUM(i+1) + F(i)) % MODD;
		// cout << i << ' ' << SUM(i) << '\n';
	}

	for (int i = -k*t; i <= k*t; ++i) {
		int tmp = max(b+i-a+1, -k*t);
		if (tmp > k*t)
			continue;
		res = (res + F(i) * SUM(tmp)) % MODD;
	}

	printf("%lld\n", res);

	return 0;
}