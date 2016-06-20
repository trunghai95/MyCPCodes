#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool leap(ll y)
{
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

ll y;

int main()
{
	cin >> y;
	ll sum = leap(y)?366:365;
	bool l = leap(y);

	while (1)
	{
		++y;
		sum += leap(y)?366:365;

		if (sum % 7 == 0 && leap(y+1) == l)
			break;
	}

	cout << y+1;
	return 0;
}