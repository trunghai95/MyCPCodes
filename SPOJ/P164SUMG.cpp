#include <bits/stdc++.h>

using namespace std;

char s[100];
int res;

int main()
{
	scanf("%s", s);
	int len = strlen(s);

	for (char c = 'a'; c <= 'z'; ++c)
	{
		++res;
		for (int i = 0; i < len; ++i)
			res += (c != s[i]);
	}

	printf("%d\n", res);
	return 0;
}