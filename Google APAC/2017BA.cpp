#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll l, r;

int main() {
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt) {
		scanf("%lld %lld", &l, &r);
		l = min(l, r);
		l = l*(l+1)/2;
		printf("Case #%d: %lld\n", tt, l);
	}
	return 0;
}