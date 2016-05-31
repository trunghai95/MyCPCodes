#include <bits/stdc++.h>

using namespace std;

int n;
char s[100010];
int pos = -1;

int main()
{
	scanf("%s", s);
	n = strlen(s);

	for (int i = 0; i < n; ++i)
	if ((s[i] - '0') % 2 == 0)
	{
		if (s[n-1] > s[i])
		{
			swap(s[n-1], s[i]);
			printf("%s", s);
			return 0;
		}
		pos = i;
	}

	if (pos == -1)
		printf("-1");
	else
	{
		swap(s[pos], s[n-1]);
		printf("%s", s);
	}
	return 0;
}