//WA
#include <bits/stdc++.h>

using namespace std;

int n, a[500010], res, sum;

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	sort(a+1, a+1+n);

	for (int i = 1; i <= n; ++i)
	{
		sum += a[i];
		if (sum >= n - i - 1)
		{
			if (sum == n - i - 1)
				printf("%d", n - i - 1);
			else
				printf("%d", n - i);
			break;
		}
	}

	return 0;
}