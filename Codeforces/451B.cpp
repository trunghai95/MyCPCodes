#include <bits/stdc++.h>

using namespace std;

int n, a[100010], lef, rig;

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);

	for (int i = 1; i < n; ++i)
	if (a[i] > a[i+1])
	{
		lef = i;
		break;
	}

	if (!lef)
	{
		printf("yes\n1 1");
		return 0;
	}

	for (int i = lef + 1; i <= n; ++i)
	if (a[i] > a[i-1])
	{
		rig = i-1;
		break;
	}

	if (!rig) rig = n;

	reverse(a+lef, a+rig+1);
	for (int i = 1; i < n; ++i)
	if (a[i] > a[i+1])
	{
		printf("no");
		return 0;
	}

	printf("yes\n%d %d", lef, rig);
	return 0;
}