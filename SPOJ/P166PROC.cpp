#include <bits/stdc++.h>

using namespace std;

int n, cntHor[111], cntVer[111], res;
char s[111];

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);

		for (int j = 0; j < n; ++j)
		if (s[j] == 'C')
		{
			res += cntHor[i] + cntVer[j];
			++cntHor[i], ++cntVer[j];
		}
	}

	printf("%d", res);
	return 0;
}