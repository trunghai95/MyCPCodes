#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define row first
#define col second

int test, n, k, mxtrain[3];
char mp[3][200];
bool ck[3][200];

bool avail(int row, int col)
{
	return col >= n || mp[row][col] == '.';
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		memset(mxtrain, -1, sizeof(mxtrain));
		memset(ck, 0, sizeof(ck));
		scanf("%d %d", &n, &k);

		pii start;
		start.col = 0;

		for (int i = 0; i < 3; ++i)
		{
			scanf("%s", mp[i]);
			if (mp[i][0] == 's')
				start.row = i;
			for (int j = n-1; j >= 0; ++j)
			if (mp[i][j] != '.')
			{
				mxtrain[i] = j;
				break;
			}
		}

		queue<pii> q;
		q.push(start);
		ck[start.row][start.col] = true;
		bool f = false;

		while (!q.empty())
		{
			pii u = q.front(); q.pop();

			if (u.col > mxtrain[u.row])
			{
				f = true;
				break;
			}

			pii tmp;

			tmp.row = u.row, tmp.col = u.col + 3;
			if (!ck[tmp.row][tmp.col] && avail(u.row, u.col + 1)
				&& avail(u.row, u.col + 2) && avail(u.row, u.col + 3))
			{
				ck[tmp.row][tmp.col] = true;
				q.push(tmp);
			}

			tmp.row = u.row - 1;
			if (tmp.row >= 0 && !ck[tmp.row][tmp.col] && avail(u.row, u.col + 1)
				&& avail(u.row - 1, u.col + 1) && avail(u.row - 1, u.col + 2)
				&& avail(u.row - 1, u.col + 3))
			{
				ck[tmp.row][tmp.col] = true;
				q.push(tmp);
			}

			tmp.row = u.row + 1;
			if (tmp.row < 3 && !ck[tmp.row][tmp.col] && avail(u.row, u.col + 1)
				&& avail(u.row + 1, u.col + 1) && avail(u.row + 1, u.col + 2)
				&& avail(u.row + 1, u.col + 3))
			{
				ck[tmp.row][tmp.col] = true;
				q.push(tmp);
			}
		}

		if (f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}