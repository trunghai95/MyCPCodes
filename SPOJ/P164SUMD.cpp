#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
char s[1000010];
vector<int> v;
ll res;

int main()
{
	scanf("%d %s", &k, s+1);

	n = strlen(s+1);

	for (int i = 1; i <= n; ++i)
	if (s[i] == '1')
		v.push_back(i);

	if (v.size() < k)
	{
		printf("0\n");
		return 0;
	}

	for (int i = 0; i + k <= (int)v.size(); ++i)
	{
		int j = i + k - 1;
		ll lef, rig;

		if (i == 0)
			lef = v[i];
		else
			lef = v[i] - v[i-1];

		if (j == (int)v.size() - 1)
			rig = n - v[j] + 1;
		else
			rig = v[j+1] - v[j];

		res += lef * rig;
	}

	printf("%lld\n", res);
	return 0;
}