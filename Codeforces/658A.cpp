#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, c, p[100], t[100];

int main()
{
	scanf("%d %d", &n, &c);

	for (int i = 1; i <= n; ++i)
		scanf("%d", p+i);
	for (int i = 1; i <= n; ++i)
		scanf("%d", t+i);

	ll res1 = 0, res2 = 0, cur = 0;

	for (int i = 1; i <= n; ++i)
	{
		res1 += max(0LL, p[i] - c*(cur + t[i]));
		cur += t[i];
	}

	cur = 0;
	for (int i = n; i >= 1; --i)
	{
		res2 += max(0LL, p[i] - c*(cur + t[i]));
		cur += t[i];
	}

	if (res1 > res2)
		printf("Limak");
	else if (res1 < res2)
		printf("Radewoosh");
	else
		printf("Tie");
	return 0;
}