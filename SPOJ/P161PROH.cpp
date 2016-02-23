#include <bits/stdc++.h>

using namespace std;

int n;
bool ck[3010];

int main()
{
	scanf("%d", &n);

	for (int i = 0, x; i < n; ++i)
	{
		scanf("%d", &x);
		ck[x] = true;
	}

	for (int i = 1; i <= 3001; ++i)
	if (!ck[i])
	{
		printf("%d", i);
		return 0;
	}
	return 0;
}