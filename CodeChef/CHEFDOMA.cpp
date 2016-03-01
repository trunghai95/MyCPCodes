// subtask 1, 2
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, a[500010], atmp[500010], cnt[500010], mx;

void zip()
{
	sort(atmp + 1, atmp + 1 + n);
	map<int,int> mp;
	mx = 0;
	mp[atmp[1]] = 0;
	for (int i = 2; i <= n; ++i)
	if (atmp[i] != atmp[i-1])
		mp[atmp[i]] = ++mx;

	for (int i = 1; i <= n; ++i)
		a[i] = mp[a[i]];
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i), atmp[i] = a[i];

	zip();

	if (mx == n - 1)
	{
		printf("%d", n);
		return 0;
	}

	if (mx == n - 2)
	{
		printf("%d", n*2 - 1);
		return 0;
	}

	ll res = n;
	for (int i = 2; i <= n; ++i)
	{
		memset(cnt, 0, sizeof(int)*(mx+1));
		cnt[a[i]] = 1;
		int last = a[i];

		for (int j = i - 1; j; --j)
		{
			++cnt[a[j]];
			if (last == -1)
			{
				int tmp = ((i - j + 1) >> 1);
				for (int iii = 0; iii <= mx; ++iii)
				if (cnt[iii] > tmp)
				{
					last = iii;
					++res;
					break;
				}
			}
			else if (a[j] == last)
				++res;
			else if (cnt[last] > ((i - j + 1) >> 1))
				++res;
			else
				last = -1;
		}
	}

	printf("%lld", res);

	return 0;
}