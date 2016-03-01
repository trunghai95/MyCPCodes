#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll a[500010];
ll preA[500010], preB[500010];
char s[500010];

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%lld", a+i);

	scanf("%s", s + 1);

	for (int i = 1; i <= n; ++i)
	{
		if (s[i] == 'A')
			preA[i] = preA[i-1] + a[i], preB[i] = preB[i-1];
		else
			preA[i] = preA[i-1], preB[i] = preB[i-1] + a[i];
	}

	ll res = max(preA[n], preB[n]);
	for (int i = 1; i < n; ++i)
	{
		ll tmp = max(preA[i] + preB[n] - preB[i], preB[i] + preA[n] - preA[i]);
		res = max(res, tmp);
	}

	printf("%lld", res);
	return 0;
}