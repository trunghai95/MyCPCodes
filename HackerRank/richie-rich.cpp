#include <bits/stdc++.h>

using namespace std;

int n, k;
char a[100010];

int main()
{
	scanf("%d %d %s", &n, &k, a);

	for (int i = 0, j; i < n/2; ++i)
	if (a[i] != a[(j = n-i-1)])
	{
		if (!k)
		{
			printf("-1");
			return 0;
		}
		--k;
	}

	for (int i = 0, j; i < n/2; ++i)
	{
		if (a[i] != a[(j = n-i-1)])
		{
			if (a[i] == '9' || a[j] == '9')
				a[i] = a[j] = '9';
			else if (k)
			{
				--k;
				a[i] = a[j] = '9';
			}
			else
			{
				if (a[i] > a[j])
					a[j] = a[i];
				else
					a[i] = a[j];
			}
		}
		else if (a[i] != '9' && k > 1)
		{
			k -= 2;
			a[i] = a[j] = '9';
		}
	}

	if (k && (n&1))
		a[n/2] = '9';

	printf("%s", a);
	return 0;
}