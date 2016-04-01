#include <bits/stdc++.h>

using namespace std;

int test, n, r, g, b;
char s[100010];

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %s", &n, s);
		r = g = b = 0;
		for (int i = 0; i < n; ++i)
		{
			r += (s[i] == 'R');
			g += (s[i] == 'G');
			b += (s[i] == 'B');
		}

		printf("%d\n", n - max(r, max(g,b)));
	}
	return 0;
}