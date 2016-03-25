#include <bits/stdc++.h>

using namespace std;

int k, n;
char s[100010];
vector<int> v;

int main()
{
	scanf("%d %d %s", &n, &k, s);

	for (int i = 0; i < n; ++i)
	if (s[i] == '0')
		v.push_back(i);

	queue<int> q;
	int p = 0;
	int res = 1000000000;

	while (q.size() <= k)
		q.push(v[p]), ++p;

	while (1)
	{
		int a = q.front(), b = q.back();
		int m = (a + b) / 2;

		vector<int>::iterator it = lower_bound(v.begin() + p - k - 1,
			v.begin() + p, m);
		res = min(res, max((*it) - a, b - (*it)));

		if (it != v.begin() + p - k - 1)
		{
			--it;
			res = min(res, max((*it) - a, b - (*it)));
		}

		if (p >= v.size())
			break;
		q.pop();
		q.push(v[p++]);
	}

	printf("%d", res);
	return 0;
}