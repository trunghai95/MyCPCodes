#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX1 1000000
#define MAX2 2000000

int n, m, cntx[2000009], cnty[2000009], curx, cury;
ll dist;
char s[300009];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0, x, y; i < n; ++i)
	{
		scanf("%d %d", &x, &y);
		++cntx[x + MAX1], ++cnty[y + MAX1];
		dist += abs(x) + abs(y);
	}

	for (int i = 1; i <= MAX2; ++i)
		cntx[i] += cntx[i-1], cnty[i] += cnty[i-1];

	scanf("%s", s);

	for (int i = 0; i < m; ++i)
	{
		if (s[i] == 'U')
		{
			dist += cnty[cury + MAX1]*2 - n;
			++cury;
		}
		else if (s[i] == 'D')
		{
			dist += n - cnty[cury - 1 + MAX1]*2;
			--cury;
		}
		else if (s[i] == 'R')
		{
			dist += cntx[curx + MAX1]*2 - n;
			++curx;
		}
		else
		{
			dist += n - cntx[curx - 1 + MAX1]*2;
			--curx;
		}
		printf("%lld\n", dist);
	}
	return 0;
}