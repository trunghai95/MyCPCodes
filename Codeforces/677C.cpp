#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;

char s[100010];

int trans(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 10;
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 36;
	if (c == '-')
		return 62;
	return 63;
}

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	ll res = 1;

	for (int i = 0; i < len; ++i)
	{
		int tmp = trans(s[i]);

		for (int j = 0; j < 6; ++j)
		{
			if (!(tmp&1))
				res = res*3 % MODD;
			tmp >>= 1;
		}
	}

	printf("%lld", res);
	return 0;
}