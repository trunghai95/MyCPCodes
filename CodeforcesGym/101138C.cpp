#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 222;
const ll MODD = 1e9 + 7;
int n, m;
ll res;
bool e[MAXN][MAXN];

ll C(ll n, ll k) {
	if (k == 2) return n*(n-1)/2;
	return n*(n-1)*(n-2)/6;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0, u, v; i < m; ++i) {
		scanf("%d %d", &u, &v);
		e[u][v] = e[v][u] = true;
	}

	for (int i = 1; i <= n; ++i)
	for (int j = i + 1; j <= n; ++j)
	if (e[i][j]) {
		ll cnt1 = 0, cnt2 = 0, cnt12 = 0;
		for (int k = 1; k <= n; ++k) {
			if (e[i][k] && e[j][k]) ++cnt12;
			else if (e[i][k] && !e[j][k] && k != j) ++cnt1;
			else if (!e[i][k] && e[j][k] && k != i) ++cnt2;
		}

		res = (res + C(cnt1, 2) * C(cnt2 + cnt12, 3)) % MODD;
		if (cnt2 + cnt12 > 0)
			res = (res + (cnt1 * cnt12) * C(cnt2 + cnt12 - 1, 3)) % MODD;
		if (cnt2 + cnt12 > 1)
			res = (res + C(cnt12, 2) * C(cnt2 + cnt12 - 2, 3)) % MODD;

		swap(cnt1, cnt2);
		res = (res + C(cnt1, 2) * C(cnt2 + cnt12, 3)) % MODD;
		if (cnt2 + cnt12 > 0)
			res = (res + (cnt1 * cnt12) * C(cnt2 + cnt12 - 1, 3)) % MODD;
		if (cnt2 + cnt12 > 1)
			res = (res + C(cnt12, 2) * C(cnt2 + cnt12 - 2, 3)) % MODD;
	}

	printf("%lld\n", res);
	return 0;
}