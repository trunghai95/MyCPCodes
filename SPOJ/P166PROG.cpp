#include <bits/stdc++.h>

using namespace std;

int n;
char s1[10010], s2[10010];

int main()
{
	cin >> n >> s1 >> s2;

	int res = 0;

	for (int i = 0; i < n; ++i)
	{
		int tmp = abs(s1[i] - s2[i]);
		res += min(tmp, 10 - tmp);
	}

	cout << res;
	return 0;
}