#include <bits/stdc++.h>

using namespace std;

int n, a[1010], b[1010], res;

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	for (int i = 1; i <= n; ++i)
		scanf("%d", b+i);

	for (int i = 1; i <= n; ++i)
	{
		int tmpa = a[i];
		int tmpb = b[i];
		res = max(res, tmpa + tmpb);
		for (int j = i+1; j <= n; ++j)
		{
			tmpa |= a[j];
			tmpb |= b[j];
			res = max(res, tmpa + tmpb);
		}
	}

	printf("%d", res);
	return 0;
}