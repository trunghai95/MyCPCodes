#include <bits/stdc++.h>

using namespace std;

char s[200010], sr[200010], stmp[200010];
int n;

int main()
{
	scanf("%s", s);
	strcpy(sr, s);
	n = strlen(s);
	reverse(sr, sr + n);

	if (strcmp(s, sr))
	{
		int pos = -1;
		for (int i = 0; i < n; ++i)
		if (s[i] != sr[i])
		{
			pos = i;
			break;
		}

		strcpy(stmp, s);

		for (int i = pos; i < n; ++i)
			s[i] = s[i+1];
		strcpy(sr, s);
		n = strlen(s);
		reverse(sr, sr + n);
		if (!strcmp(s, sr))
		{
			printf("YES\n%d", pos + 1);
			return 0;
		}

		pos = n - pos;
		strcpy(s, stmp);

		for (int i = pos; i < n; ++i)
			s[i] = s[i+1];
		strcpy(sr, s);
		reverse(sr, sr + n);
		if (!strcmp(s, sr))
		{
			printf("YES\n%d", pos + 1);
			return 0;
		}

		printf("NO");
	}
	else
		printf("YES\n%d", (n >> 1) + 1);
	return 0;
}