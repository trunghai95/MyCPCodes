#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second
typedef long long ll;
const ll MODD = 1e9 + 7;

int h, w, n;
pii a[2010];
ll f[2010], fact[200010];

void init()
{
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= 200000; ++i)
		fact[i] = fact[i-1] * i % MODD;
}

ll myPow(ll a, ll b)
{
	if (!b)
		return 1;
	ll tmp = myPow(a, b>>1);
	tmp = tmp*tmp % MODD;
	if (b&1)
		tmp = tmp*a % MODD;
	return tmp;
}

ll C(ll a, ll b)
{
	ll nume = fact[a] * fact[b-a] % MODD;
	return fact[b] * myPow(nume, MODD-2) % MODD;
}

int main()
{
	init();
	scanf("%d %d %d", &h, &w, &n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &a[i].F, &a[i].S);
	a[n].F = h;
	a[n].S = w;
	sort(a, a+n+1);

	for (int i = 0; i <= n; ++i)
	{
		f[i] = C(a[i].F - 1, a[i].F + a[i].S - 2);
		for (int j = 0; j < i; ++j)
		if (a[j].F <= a[i].F && a[j].S <= a[i].S)
		{
			f[i] -= f[j] * C(a[i].F - a[j].F,
				a[i].F - a[j].F + a[i].S - a[j].S) % MODD;
			f[i] = (f[i] + MODD) % MODD;
		}
	}

	printf("%lld", f[n]);
	return 0;
}