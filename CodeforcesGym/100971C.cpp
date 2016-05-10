#include <bits/stdc++.h>

using namespace std;

int n, a[200010];

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);

	int mn = a[n-1] - a[0] + 1, mx = a[0] + a[1] - 1;
	if (mn > mx)
		printf("NO");
	else
		printf("YES\n%d", mn);
	return 0;
}