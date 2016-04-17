#include <bits/stdc++.h>

using namespace std;

void calcZ(char* s, int* z, int n)
{
	int L = 0, R = 0;

	for (int i = 1; i < n; ++i)
	{
		if (i > R)
		{
			L = R = i;
			while (R < n && s[R] == s[R-L]) ++R;
			z[i] = R - L;
			--R;
		}
		else
		{
			int k = i - L;
			if (z[k] < R - i + 1)
				z[i] = z[k];
			else
			{
				L = i;
				while (R < n && s[R] == s[R - L]) ++R;
				z[i] = R - L;
				--R;
			}
		}
	}
}

char s[1510], good[30];
int k, z[1510], f[1510];
int res;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> s >> good >> k;
	
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
	{
		calcZ(s+i, z+i, len - i);
		for (int j = i+1; j < len; ++j)
			f[j] = max(f[j], z[j]);
	}

	for (int i = 0; i < len; ++i)
	{
		int badCnt = 0;
		for (int j = i; j < len; ++j)
		{
			badCnt += (good[s[j] - 'a'] == '0');
			if (badCnt > k)
				break;
			if (j - i + 1 > f[i])
				++res;
		}
	}

	cout << res;
	return 0;
}