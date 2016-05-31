#include <bits/stdc++.h>

using namespace std;

int a[3], b[3];

bool check(int x, int y, int z)
{
	return x*x + y*y == z*z;
}

int main()
{
	for (int i = 0; i < 3; ++i)
		cin >> a[i];
	for (int i = 0; i < 3; ++i)
		cin >> b[i];

	sort(a, a+3);
	sort(b, b+3);

	if (check(a[0],a[1],a[2]) && a[0] == b[0] && a[1] == b[1] && a[2] == b[2])
		printf("YES");
	else
		printf("NO");
	return 0;
}