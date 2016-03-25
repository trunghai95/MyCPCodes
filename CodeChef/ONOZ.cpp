#include <bits/stdc++.h>

using namespace std;

int test, h, m;

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> h >> m;

		int res = 1;

		for (int i = 1; i <= 9; ++i)
		{
			int ii = i*10 + i;
			if (i < h && i < m) ++res;
			if (ii < h && i < m) ++res;
			if (i < h && ii < m) ++res;
			if (ii < h && ii < m) ++res;
		}

		cout << res << '\n';
	}
	return 0;
}