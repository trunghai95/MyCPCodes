#include <bits/stdc++.h>

using namespace std;

int n, b, p;

int main()
{
	cin >> n >> b >> p;
	b = b*2 + 1;
	int m = n;
	int x = 0;

	while (m > 1)
	{
		int match = (int)(log(m)/log(2));
		m -= match;
		x += match*b;
	}

	cout << x << ' ' << p*n;
	return 0;
}