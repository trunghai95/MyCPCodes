//WA
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, int> pli;

const ld PI = 3.141592653589793238462643383279502884197169399375;

int n;
ll r, h, bit[100010];
pli v[100010];

void update(int x, ll val)
{
	while (x <= 100000)
	{
		bit[x] = max(bit[x], val);
		x += x&(-x);
	}
}

ll get(int x)
{
	ll res = 0;
	while (x > 0)
	{
		res = max(res, bit[x]);
		x -= x&(-x);
	}

	return res;
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld %lld", &r, &h);
		v[i].first = r*r*h;
		v[i].second = i;
	}

	sort(v+1, v+1+n);

	for (int i = 1; i <= n; ++i)
	{
		ll tmp = get(v[i].second);
		update(v[i].second, tmp + v[i].first);
	}

	printf("%.12lf", (double)(PI*get(100000)));
	return 0;
}