#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, dist;
char s1[200010], s2[200010];
map<pii,int> stRv;
map<int,int> st1;
vector<int> dif;

int main()
{
	scanf("%d %s %s", &n, s1, s2);

	for (int i = 0; i < n; ++i)
	if (s1[i] != s2[i])
	{
		++dist;
		dif.push_back(i);
		stRv[pii(s2[i], s1[i])] = i;
		st1[s2[i]] = i;
	}

	if (dist <= 1)
	{
		printf("%d\n-1 -1\n", dist);
		return 0;
	}

	int res = 0, r1 = -1, r2 = -1;
	for (int i = 0; i < dif.size(); ++i)
	{
		map<pii,int>::iterator it = stRv.find(pii(s1[dif[i]], s2[dif[i]]));
		if (it != stRv.end())
		{
			printf("%d\n%d %d\n", dist - 2, dif[i] + 1, (*it).second + 1);
			return 0;
		}

		if (!res)
		{
			map<int,int>::iterator it2 = st1.find(s1[dif[i]]);
			if (it2 != st1.end())
			{
				res = 1;
				r2 = dif[i] + 1;
				r1 = (*it2).second + 1;
			}
		}
	}

	printf("%d\n%d %d\n", dist-res, r1, r2);

	return 0;
}