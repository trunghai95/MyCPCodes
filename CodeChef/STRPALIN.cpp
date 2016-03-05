#include <bits/stdc++.h>

using namespace std;

char a[1010], b[1010];
int test;

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%s %s", a, b);
		int lena = strlen(a), lenb = strlen(b);
		bool f = false;

		for (int i = 0; i < lena && !f; ++i)
		for (int j = 0; j < lenb && !f; ++j)
		if (a[i] == b[j])
			f = true;

		if (f)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}