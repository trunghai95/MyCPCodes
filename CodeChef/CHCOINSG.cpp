#include <bits/stdc++.h>

using namespace std;

int t, n;

int main()
{
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d", &n);
		if (n % 6)
			printf("Chef\n");
		else
			printf("Misha\n");
	}
	return 0;
}