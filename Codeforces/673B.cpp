#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, lef, rig;

int main()
{
	scanf("%d %d", &n, &m);

	lef = 2, rig = n;
	while (m--)
	{
		scanf("%d %d", &u, &v);
		if (u > v) swap(u, v);
		lef = max(lef, u+1);
		rig = min(rig, v);
	}

	if (lef > rig)
		printf("0");
	else
		printf("%d", rig - lef + 1);
	return 0;
}