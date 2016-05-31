#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll n;
bool ck[10];

bool check()
{
	for (int i = 0; i < 10; ++i)
	if (!ck[i])
		return false;
	return true;
}

void proc(ll x)
{
	while (x)
	{
		ck[x%10] = true;
		x /= 10;
	}
}

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%lld", &n);
		if (!n)
		{
			printf("Case #%d: INSOMNIA\n", tt);
			continue;
		}
		ll cur = 0;
		memset(ck, 0, sizeof(ck));

		do
		{
			cur += n;
			proc(cur);
		}
		while (!check());

		printf("Case #%d: %lld\n", tt, cur);
	}
	return 0;
}