#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second

ll n, b, res;
pll a[100010];

int main() {

	scanf("%lld %lld", &n, &b);

	for (int i = 0; i < n; ++i)
		scanf("%lld %lld", &a[i].F, &a[i].S);

	sort(a, a+n);

	for (int i = 0; i < n; ++i) {
		if (b <= 0) {
			break;
		}

		ll tmp = min(b / a[i].F, a[i].S);
		b -= tmp*a[i].F;
		res += tmp;
	}

	printf("%lld\n", res);
	return 0;
}