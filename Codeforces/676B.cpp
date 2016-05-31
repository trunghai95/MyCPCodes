#include <bits/stdc++.h>
using namespace std;

const int UNIT = 2048;
int n, t, f[11][11], res;

int main()
{
	scanf("%d %d", &n, &t);
	f[1][1] = t*UNIT;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= i; ++j)
	if (f[i][j] >= UNIT)
	{
		++res;
		f[i + 1][j] += (f[i][j] - UNIT) / 2;
		f[i+1][j+1] += (f[i][j] - UNIT) / 2;
	}
	printf("%d", res);
	return 0;
}