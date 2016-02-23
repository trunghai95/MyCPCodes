#include <bits/stdc++.h>

using namespace std;

int test, d, n;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d", &d, &n);

		n = n*(n+1)/2;

		while (--d)
			n = n*(n+1)/2;

		printf("%d\n", n);
	}
	return 0;
}