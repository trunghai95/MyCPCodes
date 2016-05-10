#include <bits/stdc++.h>

using namespace std;

int n, t1, t2;

int main()
{
	scanf("%d", &n);

	t1 = 0;
	while (n--)
	{
		scanf("%d", &t2);
		if (t2 - t1 > 15)
		{
			printf("%d", t1 + 15);
			return 0;
		}
		t1 = t2;
	}

	printf("%d", min(t1 + 15, 90));
	return 0;
}