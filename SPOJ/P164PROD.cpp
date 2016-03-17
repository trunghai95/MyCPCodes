#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, c, b;
int sa[100], sb[100], sc[100], la, lc;

int main()
{
	cin >> a >> c;

	while (a)
	{
		sa[la] = a % 3;
		++la;
		a /= 3;
	}

	while (c)
	{
		sc[lc] = c % 3;
		++lc;
		c /= 3;
	}

	la = max(la, lc);

	for (int i = 0; i < la; ++i)
	{
		sb[i] = sc[i] - sa[i];
		if (sb[i] < 0)
			sb[i] += 3;
	}

	for (int i = la - 1; i >= 0; --i)
		b = b*3 + sb[i];

	cout << b;
	return 0;
}