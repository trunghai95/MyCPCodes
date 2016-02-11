#include <bits/stdc++.h>

using namespace std;

bool ck[100010];
int n, x;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		ck[x] = true;
	}

	for (int i = 1; i <= n; ++i)
	if (!ck[i])
		printf("%d ", i);
	return 0;
}