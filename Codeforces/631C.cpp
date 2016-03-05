#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define F first
#define S second

int n, m, a[200010], rr1, rr2;
pii srt[200010];
vector<pii> lastsort;

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);

	for (int i = 0; i < m; ++i)
		scanf("%d %d", &srt[i].F, &srt[i].S);

	lastsort.push_back(srt[m-1]);
	for (int i = m - 2; i >= 0; --i)
	{
		
		if (srt[i].S > lastsort.back().S)
		{
			if (srt[i].F == lastsort.back().F)
				lastsort.pop_back();
			lastsort.push_back(srt[i]);
			
		}
	}

	vector<int> v(a, a+lastsort.back().S);
	sort(v.begin(), v.end());

	int lef = 0, rig = v.size() - 1, ii = lastsort.back().S - 1;

	for (int i = lastsort.size() - 1; i >= 0; --i)
	{
		int tmp = lastsort[i].S - (i ? lastsort[i-1].S : 0);
		

		if (lastsort[i].F == 2)
		{
			while (tmp--)
				a[ii--] = v[lef++];
		}
		else
		{
			while (tmp--)
				a[ii--] = v[rig--];
		}
	}

	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);

	return 0;
}