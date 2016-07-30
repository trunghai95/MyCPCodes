#include <bits/stdc++.h>

using namespace std;

int n, sum, res;

int main()
{
	scanf("%d", &n);
	while (1)
	{
		sum += res + 1;
		if (sum > n)
		{
			printf("%d\n", res);
			return 0;
		}
		n -= sum;
		++res;
	}
	return 0;
}