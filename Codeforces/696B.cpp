#include <bits/stdc++.h>

using namespace std;

int n, p[100010], cnttot[100010];
double res[100010];
vector<int> child[100010];

int dfs(int p)
{
	int res = 0;
	for (int i = 0; i < (int)child[p].size(); ++i)
		res += dfs(child[p][i]);
	cnttot[p] = res + 1;
	return res;
}

int main()
{
	scanf("%d", &n);

	for (int i = 2; i <= n; ++i)
		scanf("%d", p+i), child[p[i]].push_back(i);

	res[1] = 1;

	for (int i = 1; i <= n; ++i)
		printf("%.6lf ", res[i]);
	return 0;
}