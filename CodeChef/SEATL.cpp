#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

struct Cmp
{
	bool operator()(pii x, pii y) { return x > y; }
};

struct Info
{
	map<int,int> cntD1, cntC1;
	set<pii, Cmp> cntD2, cntC2;
};

int test, n, m;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d", &n, &m);

		if (n == 1)
		{
			int cc[1000000], res = 0;
			memset(cc, 0, sizeof(cc));
			for (int i = 0; i < m; ++i)
				scanf("%d", &n), ++cc[n], res = max(res, cc[n]);
			printf("%d\n", res);
			continue;
		}

		if (m == 1)
		{
			int cc[1000000], res = 0;
			memset(cc, 0, sizeof(cc));
			for (int i = 0; i < n; ++i)
				scanf("%d", &m), ++cc[m], res = max(res, cc[m]);
			printf("%d\n", res);
			continue;
		}


		vector<vector<int> > a(n, vector<int>(m, 0));

		map<int, Info> info;

		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &a[i][j]);
			map<int,Info>::iterator infoIt = info.find(a[i][j]);
			if (infoIt == info.end())
				infoIt = (info.insert(pair<int, Info>(a[i][j], Info()))).first;

			int tmp = ++(*infoIt).second.cntD1[i];
			
			if (tmp == 1)
				(*infoIt).second.cntD2.insert(pii(1, i));
			else
			{
				(*infoIt).second.cntD2.erase((*infoIt).second.cntD2.find(pii(tmp-1, i)));
				(*infoIt).second.cntD2.insert(pii(tmp, i));
			}

			tmp = ++(*infoIt).second.cntC1[j];
			if (tmp == 1)
				(*infoIt).second.cntC2.insert(pii(1, j));
			else
			{
				(*infoIt).second.cntC2.erase((*infoIt).second.cntC2.find(pii(tmp-1, j)));
				(*infoIt).second.cntC2.insert(pii(tmp, j));
			}
		}

		map<int, Info>::iterator it = info.begin();

		int res = 0;

		while (it != info.end())
		{
			set<pii, Cmp>::iterator it1 = (*it).second.cntD2.begin(),
				it2 = (*it).second.cntC2.begin();
			int x = (*it1).first, y = (*it2).first;
			vector<int> v1, v2;

			while (it1 != (*it).second.cntD2.end() && (*it1).first == x)
			{
				v1.push_back((*it1).second);
				++it1;
			}

			while (it2 != (*it).second.cntC2.end() && (*it2).first == y)
			{
				v2.push_back((*it2).second);
				++it2;
			}

			int f = 1;

			for (int i = 0; i < v1.size() && f; ++i)
			for (int j = 0; j < v2.size() && f; ++j)
			{
				if (a[v1[i]][v2[j]] != (*it).first)
				{
					f = 0;
					break;
				}
			}

			res = max(res, x + y - f);
			++it;
		}

		printf("%d\n", res);
	}
	return 0;
}