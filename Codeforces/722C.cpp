#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second

int n;
ll a[100010], sum[100010];
set<pii> st;
map<ll, int, greater<ll> > mp;

ll getsum(int x, int y) {
	return sum[y] - sum[x-1];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a+i);
		sum[i] = sum[i-1] + a[i];
	}

	st.insert(pii(1, n));
	++mp[getsum(1, n)];

	for (int i = 1, x; i < n; ++i) {
		scanf("%d", &x);
		set<pii>::iterator it = st.lower_bound(pii(x+1, 0));
		--it;
		pii u = *it;
		st.erase(it);

		if (--mp[getsum(u.F, u.S)] == 0) {
			mp.erase(getsum(u.F, u.S));
		}

		if (x > u.F) {
			++mp[getsum(u.F, x-1)];
			st.insert(pii(u.F, x-1));
		}

		if (x < u.S) {
			++mp[getsum(x+1, u.S)];
			st.insert(pii(x+1, u.S));
		}

		printf("%lld\n", mp.begin()->F);
	}

	printf("0\n");
	return 0;
}