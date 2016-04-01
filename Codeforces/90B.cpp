#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[200][200];
bool f[200][200];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);

	for (int i = 0; i < n; ++i)
	{
		for (int j1 = 0; j1 < m; ++j1)
		for (int j2 = j1+1; j2 < m; ++j2)
		if (s[i][j1] == s[i][j2])
			f[i][j1] = f[i][j2] = true;
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j1 = 0; j1 < n; ++j1)
		for (int j2 = j1+1; j2 < n; ++j2)
		if (s[j1][i] == s[j2][i])
			f[j1][i] = f[j2][i] = true;
	}

	for (int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j)
	if (!f[i][j])
		printf("%c", s[i][j]);
	return 0;
}