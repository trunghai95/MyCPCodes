// C++11
#include <bits/stdc++.h>

using namespace std;

const int MAXA = 1000000;

typedef pair<int,int> pii;

int test, n, m;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d", &n, &m);

		unordered_map<int, vector<pii> > rows, cols;

		vector<vector<int> > a(n, vector<int>(m, 0));

		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &a[i][j]);
			vector<pii>& raij = rows[a[i][j]];
			if (raij.empty() || raij.back().first != i)
				raij.push_back(pii(i, 1));
			else
				++raij.back().second;
		}

		for (int j = 0; j < m; ++j)
		for (int i = 0; i < n; ++i)
		{
			vector<pii>& caij = cols[a[i][j]];
			if (caij.empty() || caij.back().first != j)
				caij.push_back(pii(j, 1));
			else
				++caij.back().second;
		}

		int res = 0;

		for (unordered_map<int, vector<pii> >::iterator k = rows.begin(); k != rows.end(); ++k)
		{
			vector<int> rr, cc;
			vector<pii>& rk = (*k).second, &ck = cols[(*k).first];

			int mxr = 0, mxc = 0;

			for (int i = 0; i < rk.size(); ++i)
				mxr = max(mxr, rk[i].second);

			for (int i = 0; i < ck.size(); ++i)
				mxc = max(mxc, ck[i].second);

			for (int i = 0; i < rk.size(); ++i)
			if (rk[i].second == mxr)
				rr.push_back(rk[i].first);

			for (int i = 0; i < ck.size(); ++i)
			if (ck[i].second == mxc)
				cc.push_back(ck[i].first);

			int f = 1;

			for (int i = 0; i < rr.size() && f; ++i)
			for (int j = 0; j < cc.size(); ++j)
			if (a[rr[i]][cc[j]] != (*k).first)
			{
				f = 0;
				break;
			}

			res = max(res, mxr + mxc - f);
		}

		printf("%d\n", res);
	}
	return 0;
}