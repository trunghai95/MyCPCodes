#include <bits/stdc++.h>

using namespace std;

int a[3], b[3];

int main()
{
	cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
	sort(a, a+3);
	sort(b, b+3);

	for (int i = 0; i < 3; ++i)
	if (a[i] != b[i])
	{
		printf("NO\n");
		return 0;
	}

	if (a[0]*a[0] + a[1]*a[1] == a[2]*b[2])
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}