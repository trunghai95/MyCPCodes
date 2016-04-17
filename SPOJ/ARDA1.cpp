#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const ll BASE = 29;

int n1, n2, m1, m2, b[310];
char s[2010][2010], p[310][310];
ll hs[2010][2010], hp[310];
vector<pii> res;

void preKMP()
{
	int i = 0, j = b[0] = -1;
	while (i < n2)
	{
		while (j >= 0 && hp[i] != hp[j]) j = b[j];
		++i, ++j;
		b[i] = j;
	}
}

void searchKMP(int r)
{
	int i = 0, j = 0;
	while (i < m2)
	{
		while (j >= 0 && hp[j] != hs[r][i]) j = b[j];
		++i, ++j;
		if (j == n2)
			res.push_back(pii(r+1, i-j+1));
	}
}

int main()
{
	scanf("%d %d", &n1, &n2);
	for (int i = 0; i < n1; ++i)
		scanf("%s", p[i]);
	scanf("%d %d", &m1, &m2);
	for (int i = 0; i < m1; ++i)
		scanf("%s", s[i]);

	for (int j = 0; j < n2; ++j)
	{
		for (int i = 0; i < n1; ++i)
			hp[j] = hp[j] * BASE + p[i][j];
	}

	ll poww = 1;
	for (int i = 0; i < n1; ++i)
		poww *= BASE;

	for (int j = 0; j < m2; ++j)
	{
		for (int i = 0; i < n1; ++i)
			hs[0][j] = hs[0][j] * BASE + s[i][j];
		for (int i = n1; i < m1; ++i)
		{
			hs[i-n1+1][j] = hs[i-n1][j] * BASE - s[i-n1][j] * poww + s[i][j];
		}
	}

	preKMP();
	for (int i = 0; i < m1; ++i)
		searchKMP(i);

	if (res.empty())
		printf("NO MATCH FOUND...");
	else
	{
		for (int i = 0; i < res.size(); ++i)
			printf("(%d,%d)\n", res[i].first, res[i].second);
	}
	return 0;
}