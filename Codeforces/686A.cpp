#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x, tmp;
int n, cnt;
char s[5];

int main()
{
	scanf("%d %lld", &n, &x);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s %lld", s, &tmp);
		if (s[0] == '+')
			x += tmp;
		else
		{
			if (tmp <= x)
				x -= tmp;
			else
				++cnt;
		}
	}

	printf("%lld %d", x, cnt);
	return 0;
}