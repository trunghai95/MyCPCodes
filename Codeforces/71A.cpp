#include <bits/stdc++.h>

using namespace std;

char s[1000];
int n;

int main()
{
	scanf("%d", &n);

	while (n--)
	{
		scanf("%s", s);
		int len = strlen(s);
		if (len <= 10)
			printf("%s\n", s);
		else
			printf("%c%d%c\n", s[0], len - 2, s[len - 1]);
	}
	return 0;
}