#include <bits/stdc++.h>

using namespace std;

int main()
{
	int lef = 1, rig = 1000000;
	char s[5];

	while (lef < rig)
	{
		int mid = (lef + rig) / 2 + 1;
		printf("%d\n", mid);
		fflush(stdout);
		scanf("%s", s);
		if (s[0] == '<')
			rig = mid - 1;
		else
			lef = mid;
	}

	printf("! %d", lef);
	return 0;
}