#include <bits/stdc++.h>

using namespace std;

struct Segment
{
	int id, left, right;
};

bool cmp(Segment s1, Segment s2) { return s1.left > s2.left; }

int n, res[200010], bit[400010];
map<int,int> mp;
Segment s[200010];

void update(int x)
{
	while (x <= 400000)
	{
		++bit[x];
		x += x&(-x);
	}
}

int get(int x)
{
	int res = 0;
	while (x > 0)
	{
		res += bit[x];
		x -= x&(-x);
	}
	return res;
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		s[i].id = i;
		scanf("%d %d", &s[i].left, &s[i].right);
		mp[s[i].left], mp[s[i].right];
	}

	int cnt = 0;
	for (map<int,int>::iterator ite = mp.begin(); ite != mp.end(); ++ite)
		(*ite).second = ++cnt;

	for (int i = 1; i <= n; ++i)
	{
		s[i].left = mp[s[i].left];
		s[i].right = mp[s[i].right];
	}

	sort(s+1, s+1+n, cmp);

	for (int i = 1; i <= n; ++i)
	{
		// printf("%d %d %d\n", s[i].id, s[i].left, s[i].right);
		res[s[i].id] = get(s[i].right);
		update(s[i].right);
	}

	for (int i = 1; i <= n; ++i)
		printf("%d\n", res[i]);

	return 0;
}