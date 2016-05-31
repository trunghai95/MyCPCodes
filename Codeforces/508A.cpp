#include <bits/stdc++.h>

using namespace std;

int n, m, k;
bool black[1010][1010];

const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1};

int main()
{
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1, x, y; i <= k; ++i)
	{
		scanf("%d %d", &x, &y);
		black[x][y] = true;

		for (int j = 0; j < 4; ++j)
		{
			if (black[x+dx[j]][y+dy[j]] && black[x][y+dy[j]] && black[x+dx[j]][y])
				return printf("%d", i), 0;
		}
	}

	printf("0");
	return 0;
}