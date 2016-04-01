#include <bits/stdc++.h>

using namespace std;

int n, x, y, lastx, lasty, lastDir, dir;

int main()
{
	scanf("%d %d %d %d %d", &n, &lastx, &lasty, &x, &y);
	if (x == lastx)
	{
		if (y > lasty)
			lastDir = 0;
		else
			lastDir = 2;
	}
	else
	{
		if (x > lastx)
			lastDir = 1;
		else
			lastDir = 3;
	}

	lastx = x, lasty = y;
	int cnt = 0;

	for (int i = 1; i < n; ++i)
	{
		scanf("%d %d", &x, &y);

		if (x == lastx)
		{
			if (y > lasty)
				dir = 0;
			else
				dir = 2;
		}
		else
		{
			if (x > lastx)
				dir = 1;
			else
				dir = 3;
		}

		if ((dir + 1) % 4 == lastDir)
			++cnt;
		lastDir = dir;

		lastx = x, lasty = y;
	}

	printf("%d", cnt);
	return 0;
}