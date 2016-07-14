#include <bits/stdc++.h>

using namespace std;

int test, n, rescnt;
string s, res;

int count()
{
	int c[300], res = 0;
	memset(c, 0, sizeof(c));

	for (int i = 0; i < (int)s.length(); ++i)
		++c[s[i]];

	for (int i = 'A'; i <= 'Z'; ++i)
		res += (c[i] > 0);

	return res;
}

int main()
{
	cin >> test;

	for (int ii = 1; ii <= test; ++ii)
	{
		cin >> n;
		cin.ignore();

		rescnt = 0;
		res = "";

		for (int i = 0; i < n; ++i)
		{
			getline(cin, s);
			int tmp = count();
			if (tmp > rescnt)
			{
				rescnt = tmp;
				res = s;
			}
			else if (tmp == rescnt && s < res)
				res = s;
		}

		cout << "Case #" << ii << ": " << res << '\n';
	}
	return 0;
}