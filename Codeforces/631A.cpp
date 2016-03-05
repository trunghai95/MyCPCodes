#include <bits/stdc++.h>

using namespace std;

int n, a[1000], b[1000], ora, orb;

void read(int *x, int &orx)
{
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", x+i);
		orx |= x[i];
	}
}

int main()
{
	scanf("%d", &n);

	read(a, ora);
	read(b, orb);

	printf("%d", ora + orb);
	return 0;
}