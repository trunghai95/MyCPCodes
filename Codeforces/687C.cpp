// chua xong

#include <bits/stdc++.h>

using namespace std;

int res[510];
int n, k, c[510], sum, check[510];
bool ck[510];
vector<int> v[510];

void proc()
{
	memset(check, -1, sizeof(check));

	for (int i = 0; i < n; ++i)
	{
		check[0] = i;

		for (int j = k; j >= c[i]; --j)
		if (check[j - c[i]] != -1)
			check[j] = i, v[j].push_back(i), 
				v[j].insert(v[j].end(), v[j - c[i]].begin(), v[j - c[i]].end());

		if (check[k] == i)
		{
			ck[i] = true;
		}
	}

	for (int i = 0; i < (int)v[k].size(); ++i)
		cout << c[v[k][i]] << ' ';
	cout << '\n';

	for (int i = 0; i < (int)v[k].size(); ++i)
	{
		if (res[k] == -1)
			res[k] = v[k][i];
		// cout << v[k][i] << ' ' << check[k] << '\n';
		for (int j = c[v[k][i]]; j <= k; ++j)
		{
			if (res[j - c[v[k][i]]] != v[k][i]
				&& res[j - c[v[k][i]]] != -1 && res[j] == -1)
				res[j] = v[k][i];
			// cout << j << ' ' << res[j] << ' ' << res[j-c[v[k][i]]] << '\n';
		}
	}
}

int main()
{
	memset(res, -1, sizeof(res));
	res[0] = 600;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i)
		scanf("%d", c+i), sum += c[i];
	proc();

	int cnt = 0;
	for (int i = 0; i <= k; ++i)
		cnt += (res[i] != -1);
	printf("%d\n", cnt);
	for (int i = 0; i <= k; ++i)
	if (res[i] != -1)
		printf("%d ", i);
	return 0;
}