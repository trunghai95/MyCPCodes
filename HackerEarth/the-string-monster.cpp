#include <bits/stdc++.h>

using namespace std;

int test, n, cntt[26], cnts[31][26], cntsuf[31][26], len[31], lent, curcnt[26];
char s[31][31], t[1000];

bool Try(int p)
{
	if (p > n)
		return false;

	bool f = true;

	// cout << p << '\n';

	for (int i = 0; i < 26; ++i)
	{
		if (curcnt[i] + cntsuf[p][i] < cntt[i] || curcnt[i] > cntt[i])
			return false;
		if (curcnt[i] != cntt[i])
			f = false;
	}

	if (f)
		return true;

	for (int i = p; i < n; ++i)
	{
		// cout << p-1 << ' ' << i << '\n';
		for (int j = 0; j < 26; ++j)
			curcnt[j] += cnts[i][j];
		if (Try(i+1))
			return true;
		for (int j = 0; j < 26; ++j)
			curcnt[j] -= cnts[i][j];
	}

	return false;
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		memset(cntt, 0, sizeof(cntt));
		memset(cnts, 0, sizeof(cnts));
		memset(cntsuf, 0, sizeof(cntsuf));
		memset(curcnt, 0, sizeof(curcnt));

		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%s", s[i]), len[i] = strlen(s[i]);
		scanf("%s", t);
		lent = strlen(t);

		for (int i = 0; i < lent; ++i)
			++cntt[t[i] - 'a'];

		for (int i = n-1; i >= 0; --i)
		{
			for (int j = 0; j < len[i]; ++j)
				++cnts[i][s[i][j] - 'a'];

			for (int j = 0; j < 26; ++j)
				cntsuf[i][j] = cnts[i][j] + cntsuf[i+1][j];
		}

		printf(Try(0) ? "YES\n" : "NO\n");
	}
	return 0;
}