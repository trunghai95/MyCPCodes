//WA

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;
#define F first
#define S second

int n, m, res[200010];
ll a[760], sum[760];
pli b[200010];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a+i);
	}

	for (int i = 1; i <= m; ++i) {
		scanf("%lld", &b[i].F);
		b[i].S = i;
	}

	sort(b+1, b+1+m, greater<pli>());
	b[0].F = -1;

	for (int i = 1; i <= m; ++i) {
		res[b[i].S] = res[b[i-1].S];

		if (b[i].F == b[i-1].F) {
			continue;
		}

		priority_queue<pli, vector<pli>, greater<pli> > heap;
		int cnt = 0;

		sum[0] = b[i].F;
		for (int j = 1; j <= n; ++j) {
			if (a[j] < 0) {
				heap.push(pli(a[j], j));
			}
			sum[j] = sum[j-1] + a[j];

			while (sum[j] < 0) {
				pli u = heap.top();
				heap.pop();
				sum[j] -= u.F;
				a[u.S] = 0;
				++cnt;
			}
		}

		res[b[i].S] += cnt;
	}

	for (int i = 1; i <= m; ++i)
		printf("%d\n", res[i]);
	return 0;
}