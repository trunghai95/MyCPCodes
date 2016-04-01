#include <bits/stdc++.h>

using namespace std;

char s[100010];
int f[100010], i, n;

int main()
{
	cin >> s;
	n = strlen(s);
	f[n-1] = n - 1;

	for (i = n - 2; i >= 0; --i)
	{
		if (s[i] < s[f[i+1]])
			f[i] = f[i+1];
		else
			f[i] = i;
	}

	i = 0;
	while (i < n)
	{
		cout << s[f[i]];
		i = f[i];
		if (i == f[i])
			++i;
	}
	return 0;
}