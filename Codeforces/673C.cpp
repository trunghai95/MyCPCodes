#include <bits/stdc++.h>

using namespace std;

int n, t[5010], cnt[5010], res[5010];

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", t+i);
		++res[t[i]];
		cnt[t[i]] = 1;
		int mx = 1, mxt = t[i];

		for (int j = i-1; j > 0; --j)
		{
			if (++cnt[t[j]] > mx)
				mx = cnt[t[j]], mxt = t[j];
			else if (cnt[t[j]] == mx && t[j] < mxt)
				mx = cnt[t[j]], mxt = t[j];
			++res[mxt];
		}
	}

	for (int i = 1; i <= n; ++i)
		printf("%d ", res[i]);
	return 0;
}