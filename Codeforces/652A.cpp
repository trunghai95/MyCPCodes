#include <bits/stdc++.h>

using namespace std;

int h1, h2, a, b, res;

int main()
{
	cin >> h1 >> h2 >> a >> b;

	if (a <= b)
	{
		if (a*8 + h1 >= h2)
			cout << 0;
		else
			cout << -1;
		return 0;
	}

	while (1)
	{
		if (a*8 + h1 >= h2)
		{
			cout << res;
			return 0;
		}

		++res;
		h1 = h1 + a*12 - b*12;
	}
	return 0;
}