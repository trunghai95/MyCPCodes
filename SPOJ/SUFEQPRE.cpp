#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
const ll BASE = 29;

int test;
char s[1000010];
ll hashPre[1000010], hashSuf[1000010];

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%s", s);
		memset(hashPre, 0, sizeof(hashPre));
		memset(hashSuf, 0, sizeof(hashSuf));
		int n = strlen(s);

		for (int i = 1; i < n; ++i)
			hashPre[i] = (hashPre[i-1] * BASE + s[i-1] - 'a');

		ll poww = 1;
		for (int i = 1; i < n; ++i)
		{
			hashSuf[i] = (hashSuf[i-1] + (s[n - i] - 'a') * poww);
			poww = (poww * BASE);
		}

		int res = 0;

		for (int i = 1; i < n; ++i)
		if (hashPre[i] == hashSuf[i])
			++res;

		printf("Case %d: %d\n", tt, res);
	}
	return 0;
}