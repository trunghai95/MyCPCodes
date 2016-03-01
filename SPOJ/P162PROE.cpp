#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, i;
ll res;
char s[5000];
map<int,int> cnt;

int main()
{
	scanf("%d %s", &n, s);
	int len = strlen(s);
	for (i = 0; i < len; ++i)
	{
		s[i] -= '0';
		if (!s[i] || n % s[i] == 0)
			++cnt[s[i]];
		int sum = s[i];
		for (int j = i - 1; j >= 0; --j)
		{
			sum += s[j];
			if (!sum || n % sum == 0)
				++cnt[sum];
		}
	}

	if (!n)
	{
		ll tmp = len*(len+1)/2;
		ll cnt0 = cnt[0];
		res = tmp*tmp - (tmp - cnt0)*(tmp - cnt0);
		// res = (ll)cnt0 * tmp - cnt[0];
	}
	else
	{
		for (i = 1; i < n/i; ++i)
		if (n % i == 0)
			res += 2LL * cnt[i] * cnt[n/i];
		if (i * i == n)
			res += cnt[i] * cnt[i];
	}

	printf("%lld", res);
	return 0;
}