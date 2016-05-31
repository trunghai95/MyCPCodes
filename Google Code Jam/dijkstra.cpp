#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int mat[5][5] = {{0, 1, 'i', 'j', 'k'}, {1, 1, 'i', 'j', 'k'}, 
{'i', 'i', -1, 'k', -'j'}, {'j', 'j', -'k', -1, 'i'}, {'k', 'k', 'j', -'i', -1}};

int mul(int x, int y)
{
	int sign = 1;
	if (x < 0) sign = -sign, x = -x;
	if (y < 0) sign = -sign, y = -y;
	for (int i = 1; i <= 4; ++i)
	if (mat[0][i] == x)
	{
		for (int j = 1; j <= 4; ++j)
		if (mat[0][j] == y)
			return sign*mat[i][j];
	}

	return -1000;
}

int test, len;
ll num;
char s[10010];

bool solvesmall()
{
	int all = 1;
	bool hasi = false, hask = false;
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			all = mul(all, s[j]);
			if (!hasi)
			{
				if (all == 'i')
					hasi = true;
			}
			else if (!hask && all == 'k')
				hask = true;
		}
	}

	if (hasi && hask && all == -1)
		return true;
	return false;
}

bool solvelarge()
{
	int all = 1;
	map<int, bool> has1, has2;
	for (int i = 0; i < len; ++i)
	{
		all = mul(all, s[i]);
		has1[all] = true;
	}

	all = 1;
	for (int i = len-1; i >= 0; --i)
	{
		all = mul(s[i], all);
		has2[all] = true;
	}

	if (all == 1 || (all == -1 && !(num&1)) || (all != -1 && num % 4 != 2))
		return false;

	if (has1['i'] && has2['k'])
		return true;

	if ((has1['i'] || has1[-'i']) && (has2['k'] || has2[-'k']))
		return true;

	if (all == -1)
		return false;

	if (abs(all) == 'i')
	{
		if ((has1[1] || has1[-1]) && (has2['j'] || has2[-'j']))
			return true;
		return false;
	}

	if (abs(all) == 'j')
	{
		if ((has1['k'] || has1[-'k']) && (has2['i'] || has2[-'i']))
			return true;
		return false;
	}

	if ((has1['j'] || has1[-'j']) && (has2[1] || has2[-1]))
		return true;
	return false;
}

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%d %lld %s", &len, &num, s);
		if (num < 10)
		{
			if (solvesmall())
				printf("Case #%d: YES\n", tt);
			else
				printf("Case #%d: NO\n", tt);
			continue;
		}

		if (solvelarge())
			printf("Case #%d: YES\n", tt);
		else
			printf("Case #%d: NO\n", tt);
	}
	return 0;
}