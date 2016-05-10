#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> fix;

int main()
{
	scanf("%d", &n);

	for (int i = 1, x; i <= n; ++i)
	{
		scanf("%d", &x);
		if (x == i)
			fix.push_back(x);
	}

	printf("%d\n", ((int)fix.size() >> 1) + ((int)fix.size() & 1));
	for (int i = 1; i < (int)fix.size(); i += 2)
	{
		printf("%d %d\n", fix[i-1], fix[i]);
	}

	if (fix.size() & 1)
	{
		if (fix.back() == 1)
			printf("1 2\n");
		else
			printf("1 %d\n", fix.back());
	}
	return 0;
}