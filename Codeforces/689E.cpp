#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const ll MODD = 1e9 + 7;

int n, k;
vector<pii> p;
ll res, fac[200010], facinv[200010];

ll myPow(ll x, ll y)
{
	if (!y)
		return 1;
	ll tmp = myPow(x, y/2);
	tmp = tmp*tmp % MODD;
	if (y&1)
		tmp = tmp*x % MODD;
	return tmp;
}

void init()
{
	fac[0] = facinv[0] = 1;
	for (int i = 1; i <= 200000; ++i)
	{
		fac[i] = fac[i-1] * i % MODD;
		facinv[i] = myPow(fac[i], MODD - 2);
	}
}

ll C(ll x, ll y)
{
	return (fac[x] * facinv[y] % MODD) * facinv[x-y] % MODD;
}

int main()
{
	init();
	scanf("%d %d", &n, &k);

	for (int i = 0, u, v; i < n; ++i)
	{
		scanf("%d %d", &u, &v);

		p.push_back(pii(u,-1));
		p.push_back(pii(v+1,1));
	}

	sort(p.begin(), p.end());

	stack<int> st;
	st.push(p[0].first);

	for (int i = 1; i < (int)p.size(); ++i)
	{
		int dep = st.size();

		if (dep >= k)
			res = (res + C(dep, k) * (p[i].first - p[i-1].first)) % MODD;

		if (p[i].second < 0)
			st.push(p[i].first);
		else
			st.pop();
	}

	printf("%lld", res);
	return 0;
}