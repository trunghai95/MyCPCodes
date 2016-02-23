#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char s[300010];
int len;
ll res;

int main()
{
	scanf("%s", s);
	len = strlen(s);

	for (int i = 0; i < len; ++i)
	{
		if ((s[i] - '0') % 4 == 0)
			++res;
	}

	for (int i = 1; i < len; ++i)
	{
		int tmp = (s[i-1] - '0')*10 + s[i] - '0';
		if (tmp % 4 == 0)
			res += i;
	}

	printf("%lld", res);
	return 0;
}