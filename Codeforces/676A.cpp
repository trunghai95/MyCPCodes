#include <bits/stdc++.h>
using namespace std;

int n, p1, p2, x;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &x);
		if (x == 1) p1 = i;
		if (x == n) p2 = i;
	}
	printf("%d", max(abs(p1-p2), max(n-p1, max(n-p2, max(p1-1, p2-1)))));
	return 0;
}