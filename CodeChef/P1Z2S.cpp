#include <bits/stdc++.h>

using namespace std;

int n, a, sum;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		sum += a;
	}

	sum = sum / 2 + (sum & 1);
	sum = max(sum, n);

	printf("%d", sum);
	return 0;
}