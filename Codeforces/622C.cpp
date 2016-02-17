#include <bits/stdc++.h>

using namespace std;

/*
// Sqrt-decompostition - O(n*log(n) + m*sqrt(n))

typedef pair<int,int> pii;
const int BLKSZ = 448;
int n, m, a[200010], blknum, lef, rig, x;
pii as[200010];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i), as[i] = pii(a[i], i);

	blknum = n / BLKSZ;

	for (int i = 1; i < blknum; ++i)
		sort(as + i*BLKSZ, as + (i+1)*BLKSZ);

	for (int ii = 0; ii < m; ++ii)
	{
		scanf("%d %d %d", &lef, &rig, &x);
		--lef, --rig;
		int lefblk = lef / BLKSZ;
		int rigblk = rig / BLKSZ;

		bool found = false;

		if (lefblk == rigblk)
		{
			for (int i = lef; i <= rig; ++i)
			if (a[i] != x)
			{
				printf("%d\n", i+1);
				found = true;
				break;
			}
		}
		else
		{
			for (int i = lefblk + 1; i < rigblk; ++i)
			{
				if (as[i*BLKSZ].first != x)
				{
					printf("%d\n", as[i*BLKSZ].second+1);
					found = true;
					break;
				}

				if (as[(i+1)*BLKSZ - 1].first != x)
				{
					printf("%d\n", as[(i+1)*BLKSZ - 1].second+1);
					found = true;
					break;
				}
			}

			for (int i = lef; i < (lefblk+1)*BLKSZ && !found; ++i)
			if (a[i] != x)
				printf("%d\n", i+1), found = true;

			for (int i = rigblk*BLKSZ; i <= rig && !found; ++i)
			if (a[i] != x)
				printf("%d\n", i+1), found = true;
		}

		if (!found) printf("-1\n");
	}
	return 0;
}
*/

// O(n+m)

int n, m, a[200010], p[200010], lef, rig, x;

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);

		if (a[i] == a[i-1])
			p[i] = p[i-1];
		else
			p[i] = i-1;
	}

	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &lef, &rig, &x);

		if (a[rig] != x)
			printf("%d\n", rig);
		else if (p[rig] >= lef)
			printf("%d\n", p[rig]);
		else
			printf("-1\n");
	}
	return 0;
}