#include <bits/stdc++.h>

using namespace std;

char s[100010], res[100010];
int n, k;

int main()
{
	scanf("%d %d %s", &n, &k, s);
	int mx = 0;

	for (int i = 0; i < n; ++i)
	{
		if (s[i] - 'a' > 'z' - s[i])
			res[i] = 'a';
		else
			res[i] = 'z';
		mx += abs(res[i] - s[i]);
	}

	if (mx < k)
	{
		printf("-1");
		return 0;
	}

	if (mx == k)
	{
		printf("%s", res);
		return 0;
	}

	for (int i = 0; i < n; ++i)
	{
		if (mx - abs(res[i] - s[i]) > k)
		{
			mx -= abs(res[i] - s[i]);
			res[i] = s[i];
		}
		else
		{
			int tmp = mx - k;
			if (res[i] == 'a')
				res[i] += tmp;
			else
				res[i] -= tmp;
			break;
		}
	}

	printf("%s", res);
	return 0;
}