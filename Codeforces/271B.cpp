#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, a[501][501];
vector<int> primes;
bool notPr[150010];

void init()
{
	notPr[1] = true;
	for (int i = 2; i <= 150000; ++i)
	if (!notPr[i])
	{
		primes.push_back(i);
		for (ll j = (ll)i*i; j <= 150000L; j += i)
			notPr[j] = true;
	}
}

int main()
{
	init();

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j)
	{
		scanf("%d", a[i]+j);
		if (!notPr[a[i][j]])
			a[i][j] = 0;
		else
		{
			int nearest = *lower_bound(primes.begin(), primes.end(), a[i][j]);
			a[i][j] = nearest - a[i][j];
		}
	}

	int res = 1e9;

	for (int i = 0; i < n; ++i)
	{
		int tmp = 0;
		for (int j = 0; j < m; ++j)
			tmp += a[i][j];
		res = min(res, tmp);
	}

	for (int j = 0; j < m; ++j)
	{
		int tmp = 0;
		for (int i = 0; i < n; ++i)
			tmp += a[i][j];
		res = min(res, tmp);
	}

	printf("%d", res);
	return 0;
}