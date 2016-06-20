#include <bits/stdc++.h>

using namespace std;

int test, c, n;
char s[5];
bool check[125502];

int solve(vector<int> &v, int &sum)
{
	memset(check, 0, sizeof(check));
	check[0] = true;

	int sz = v.size(), cursum = 0;
	for (int i = 0; i < sz; ++i)
	{
		if (cursum <= sum/2)
			cursum += v[i];
		for (int j = sum; j >= v[i]; --j)
			check[j] = check[j] | check[j - v[i]];
	}

	int res = sum;
	for (int i = 1; i < sum; ++i)
	if (check[i])
	{
		// cout << sum << ' ' << i << '\n';
		res = min(res, abs(sum - 2*i));
	}
	return res;
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		vector<int> a, b;
		scanf("%d %d", &n, &c);
		a.push_back(c);
		int suma = c;
		int sumb = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%s %d", s, &c);
			if (i&1)
				b.push_back(c), sumb += c;
			else
				a.push_back(c), suma += c;
		}
		if (n < 3)
		{
			printf("NO\n");
			continue;
		}
		printf("%d\n", solve(a, suma) + solve(b, sumb));
	}
	return 0;
}