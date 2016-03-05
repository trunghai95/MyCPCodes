//wa
#include <bits/stdc++.h>

using namespace std;

int d;
char s[1000010];

int main()
{
	scanf("%d", &d);

	while (d--)
	{
		scanf("%s", s);
		int len = strlen(s);
		bool f = true;

		for (int i = 0; i < len/2; ++i)
		if (s[i] != s[i + len/2 + (len&1)])
		{
			f = false;
			break;
		}

		if (f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}