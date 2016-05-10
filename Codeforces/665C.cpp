#include <bits/stdc++.h>

using namespace std;

char s[200010];
int n;

char inc(char c)
{
	return (c - 'a' + 1) % 26 + 'a';
}

int main()
{
	scanf("%s", s);
	n = strlen(s);

	for (int i = 1; i < n - 1; ++i)
	if (s[i] == s[i-1])
	{
		s[i] = inc(s[i]);
		if (s[i] == s[i+1])
			s[i] = inc(s[i]);
		++i;
	}

	if (s[n-1] == s[n-2])
		s[n-1] = inc(s[n-1]);
	printf("%s", s);
	return 0;
}