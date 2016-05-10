#include <bits/stdc++.h>

using namespace std;

bool Try(int a, int b, int c, int d, int e, int f)
{
	return c + e <= a && max(d, f) <= b;
}

int a, b, a1, b1, a2, b2;

int main()
{
	scanf("%d %d %d %d %d %d", &a, &b, &a1, &b1, &a2, &b2);

	if (Try(a,b,a1,b1,a2,b2) || Try(a,b,a1,b1,b2,a2) ||
		Try(a,b,b1,a1,a2,b2) || Try(a,b,b1,a1,b2,a2))
		printf("YES");
	else
	{
		swap(a, b);
		if (Try(a,b,a1,b1,a2,b2) || Try(a,b,a1,b1,b2,a2) ||
		Try(a,b,b1,a1,a2,b2) || Try(a,b,b1,a1,b2,a2))
			printf("YES");
		else
			printf("NO");
	}
	return 0;
}