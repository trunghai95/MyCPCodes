//WA
#include <bits/stdc++.h>

using namespace std;

int x[5], y[5], sum, cnt, c[5];

bool Try1()
{
	for (int i = 1; i < 5; ++i)
	if (x[i] != x[i-1])
		return false;
	return true;
}

bool Try(int p)
{
	if (p == 4)
	{
		c[4] = cnt;
		if (c[0] == 1 && c[1] == 1 && c[2] == 1 && c[3] == 1)
			return false;
		// if (c[0] == 5 || c[1] == 5 || c[2] == 5 || c[3] == 5 || c[4] == 5)
		// 	return false;
		memcpy(x, y, sizeof(x));
		while (1)
		{
			for (int i = 0; i < 5; ++i)
			{
				x[i] = x[i] - c[i] + 1;
				if (x[i] < 0)
					return false;
			}
			if (Try1())
			{
				for (int i = 0; i < 5; ++i)
					cout << c[i] << ' ';
				cout << '\n';
				return true;
			}
		}
	}

	for (int i = 0; i <= cnt; ++i)
	{
		c[p] = i;
		cnt -= i;
		if (Try(p+1))
			return true;
		cnt += i;
	}

	return false;
}

int main()
{
	for (int i = 0; i < 5; ++i)
		cin >> y[i], sum += y[i];

	if (sum % 5)
	{
		cout << -1;
		return 0;
	}

	memcpy(x, y, sizeof(x));

	cnt = 5;
	if (Try1() || Try(0))
		cout << sum / 5;
	else
		cout << -1;
	return 0;
}