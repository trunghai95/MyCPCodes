#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef map<ll,ll>::iterator ite;

int n;
map<ll, ll> cnt;
ll res, a;
vector<ll> pows, spec;

void init()
{
	pows.push_back(2);
	for (int i = 0; i < 32; ++i)
		pows.push_back(pows.back() << 1);
}

int main()
{
	init();
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &a);
		++cnt[a];
	}

	for (ite it1 = cnt.begin(); it1 != cnt.end(); ++it1)
	{
		for (int i = 0; i < (int)pows.size(); ++i)
		{
			ll u = pows[i] - it1->first;
			ite it2 = cnt.find(u);
			if (u == it1->first)
				res += it1->second * (it1->second - 1);
			else if (it2 != cnt.end())
				res += it2->second * it1->second;
		}
	}

	res /= 2;
	printf("%lld\n", res);
	return 0;
}