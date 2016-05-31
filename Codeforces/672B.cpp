#include <bits/stdc++.h>

using namespace std;

int n, cnt[300];
char s[100010];

int main()
{
	scanf("%d %s", &n, s);

	if (n > 26)
		return printf("-1"), 0;

	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		if (++cnt[s[i]] > 1)
			++res;
	}

	printf("%d", res);
	return 0;
}