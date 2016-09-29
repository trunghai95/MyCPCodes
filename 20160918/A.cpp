#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll a[100010], b[100010];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%lld", a+i);
	for (int i = 0; i < n; ++i)
		scanf("%lld", b+i);

	sort(a, a+n);
	sort(b, b+n, greater<ll>());

	ll res = 0;
	for (int i = 0; i < n; ++i)
		res += a[i] * b[i];

	printf("%lld\n", res);
	return 0;
}