#include <bits/stdc++.h>

using namespace std;

int n, a, cnt;

bool solve()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &a), cnt += a;

	if (n == 1)
		return cnt == 1;
	return (n - cnt == 1);
}

int main()
{
	if (solve())
		printf("YES");
	else
		printf("NO");
	return 0;
}