#include <bits/stdc++.h>

using namespace std;

struct Env
{
	int w, h, dp, prev, id;
	Env(): prev(-1) {}
	Env(int ww, int hh, int i): w(ww), h(hh), dp(1), prev(-1), id(i) {}
};

bool cmp(Env x, Env y)
{
	if (x.w == y.w)
		return x.h > y.h;
	return x.w > y.w;
}

int n, w, h;
vector<Env> v;

int main()
{
	scanf("%d %d %d", &n, &w, &h);

	for (int i = 1, x, y; i <= n; ++i)
	{
		scanf("%d %d", &x, &y);
		if (x > w && y > h)
			v.push_back(Env(x, y, i));
	}
	n = v.size();
	if (!n)
	{
		printf("0");
		return 0;
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		if (v[j].w > v[i].w && v[j].h > v[i].h && v[j].dp + 1 > v[i].dp)
		{
			v[i].dp = v[j].dp + 1;
			v[i].prev = j;
		}
	}

	int maxi = 0;
	for (int i = 1; i < n; ++i)
	if (v[i].dp > v[maxi].dp)
		maxi = i;

	printf("%d\n", v[maxi].dp);
	while (maxi != -1)
	{
		printf("%d ", v[maxi].id);
		maxi = v[maxi].prev;
	}

	return 0;
}