#include <bits/stdc++.h>

using namespace std;

typedef pair<int,string> pis;

int n, m, reg, pnt;
vector<pis> lis[10010];
string s;

bool cmp(pis x, pis y) { return x.first > y.first; }

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> s >> reg >> pnt;
		lis[reg].push_back(pis(pnt, s));
	}

	for (int i = 1; i <= m; ++i)
	{
		sort(lis[i].begin(), lis[i].end(), cmp);
		if (lis[i].size() == 2 || lis[i][1].first != lis[i][2].first)
			cout << lis[i][0].second << ' ' << lis[i][1].second << '\n';
		else
			cout << "?\n";
	}
	return 0;
}