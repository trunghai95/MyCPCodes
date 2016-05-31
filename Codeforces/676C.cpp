#include <bits/stdc++.h>

using namespace std;

int n, k;
char s[100010];

int solve(char a)
{
	int lef = 0, rig = -1, cnt = 0, res = 0;

	while (rig < n)
	{
		while (rig < n && cnt <= k)
			++rig, cnt += (s[rig] != a);
		res = max(res, rig - lef);
		if (rig >= n)
			break;
		while (lef <= rig && cnt > k)
		{
			cnt -= (s[lef] != a);
			++lef;
		}
	}
	return res;
}

int main()
{
	scanf("%d %d %s", &n, &k, s);
	printf("%d", max(solve('a'), solve('b')));
	return 0;
}