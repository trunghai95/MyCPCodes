#include <bits/stdc++.h>

using namespace std;

int n, q, res;
string u, v;
string op[300][300];

bool Try(string s)
{
	if (s.length() == 1)
	{
		if (s[0] == 'a')
			return true;
		return false;
	}

	if (op[s[0]][s[1]].empty())
		return false;

	return Try(op[s[0]][s[1]] + string(s.begin() + 2, s.end()));
}

int main()
{
	cin >> n >> q;

	for (int i = 0; i < q; ++i)
	{
		cin >> u >> v;
		op[u[0]][u[1]] = v;
	}

	u = string();
	for (int i = 0; i < n; ++i)
		u = u + string("a");
	v = u;

	while (1)
	{
		res += Try(u);
		int i = u.length() - 1;
		++u[i];

		while (1)
		{
			if (u[i] > 'f')
				u[i] = 'a', ++u[i-1];
			if (--i == 0)
				break;
		}

		if (u[0] > 'f')
			break;
	}

	cout << res;

	return 0;
}