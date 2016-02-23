#include <bits/stdc++.h>

using namespace std;

int n, cntf[400], cntm[400];
char s[20];

int main()
{
	scanf("%d", &n);

	for (int i = 0, x, y; i < n; ++i)
	{
		scanf("%s %d %d", s, &x, &y);

		if (s[0] == 'F')
		for (int i = x; i <= y; ++i)
			++cntf[i];
		else
		for (int i = x; i <= y; ++i)
			++cntm[i];
	}

	int res = 0;
	for (int i = 1; i <= 366; ++i)
		res = max(res, min(cntf[i], cntm[i]));

	printf("%d", res*2);
	return 0;
}