#include <bits/stdc++.h>

using namespace std;

int n, k, x;
char s[10];

int main()
{
	scanf("%d %d", &n, &k);
	int maxsafe = k-1, minbroke = 2;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d %s", &x, s);
		if (!strcmp(s, "SAFE"))
			minbroke = max(minbroke, x+1);
		else
			maxsafe = min(maxsafe, x-1);
	}

	printf("%d %d", minbroke, maxsafe);
	return 0;
}