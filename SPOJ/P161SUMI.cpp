#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k, cnt[26];
char s[100010];
ll res;

int main()
{
	scanf("%d %d %s", &n, &k, s);

	int len = strlen(s);

	for (int i = 0; i < len; ++i)
		++cnt[s[i] - 'A'];

	sort(cnt, cnt+26);

	for (int i = 25; i >= 0; --i)
	{
		if (cnt[i] >= k)
		{
			res += (ll)k*k;
			printf("%lld", res);
			return 0;
		}
		res += (ll)cnt[i]*cnt[i];
		k -= cnt[i];
	}
	return 0;
}