#include <bits/stdc++.h>

using namespace std;

int n, a[1000010];

int main()
{
	scanf("%d", &n);

	for (int i = 1; i < n; i += 2)
		a[i/2 + 1] = a[n - i/2] = i;

	for (int i = 2; i < n; i += 2)
		a[n + i/2] = a[n*2 - i/2] = i;

	for (int i = 1; i <= (n<<1); ++i)
	{
		if (!a[i])
			printf("%d ", n);
		else
			printf("%d ", a[i]);
	}
	return 0;
}