#include <bits/stdc++.h>

using namespace std;

int x;

int main()
{
	printf("1\n3 1 2 2\n3 3 3 4\n");
	fflush(stdout);
	scanf("%d", &x);
	if (x == 1)
		x = 1;
	else if (x == 2)
		x = 2;
	else if (x == -2)
		x = 3;
	else if (x == -1)
		x = 4;
	else x = 5;

	printf("2\n%d\n", x);
	return 0;
}