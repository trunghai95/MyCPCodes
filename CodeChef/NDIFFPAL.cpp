#include <bits/stdc++.h>

using namespace std;

int test, n;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; ++i)
			printf("%c", 'a' + i%26);
		printf("\n");
	}
	return 0;
}