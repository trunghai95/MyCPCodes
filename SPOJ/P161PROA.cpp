#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll x;
bool ck[1000010];
vector<ll> v;

void init()
{
	for (ll k = 2; k <= 1000000; ++k)
	if (!ck[k])
	{
		for (ll i = k*k; i <= 1000000; i += k)
			ck[i] = true;
		v.push_back(k*k);
	}
}

int main()
{
	init();

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &x);
		vector<ll>::iterator it = lower_bound(v.begin(), v.end(), x);

		if (it == v.end() || *it != x)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}