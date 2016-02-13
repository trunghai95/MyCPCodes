#include <bits/stdc++.h>

using namespace std;

int x, y, n;
string s;

void f(int i)
{
	if (s[i] == 'U')
		--y;
	else if (s[i] == 'D')
		++y;
	else if (s[i] == 'L')
		--x;
	else if (s[i] == 'R')
		++x;
}

int main()
{
	cin >> n >> s;
	int res = 0;

	for (int i = 0; i < n; ++i)
	{
		x = y = 0;
		f(i);

		for (int j = i + 1; j < n; ++j)
		{
			f(j);
			if (x == 0 && y == 0)
				++res;
		}
	}

	cout << res;
	return 0;
}