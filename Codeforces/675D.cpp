#include <bits/stdc++.h>

using namespace std;

int n, a[100010], h[100010], p[100010];

struct cmp
{
	bool operator()(int x, int y) { return a[x] < a[y]; }
};

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);

	set<int, cmp> s;
	s.insert(0);

	for (int i = 1; i < n; ++i)
	{
		set<int, cmp>::iterator it = s.lower_bound(i);
		if (it == s.end())
		{
			--it;
			h[i] = h[*it] + 1;
			p[i] = *it;
		}
		else if (it == s.begin())
		{
			h[i] = h[*it] + 1;
			p[i] = *it;
		}
		else
		{
			set<int, cmp>::iterator it2 = it;
			--it;
			if (h[*it] > h[*it2])
			{
				h[i] = h[*it] + 1;
				p[i] = *it;
			}
			else
			{
				h[i] = h[*it2] + 1;
				p[i] = *it2;
			}
		}
		s.insert(i);
	}

	for (int i = 1; i < n; ++i)
		printf("%d ", a[p[i]]);
	return 0;
}