#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x1, my1, x2, y2;

int main()
{
	cin >> x1 >> my1 >> x2 >> y2;

	ll w = x2 - x1;

	cout << w/2 * (y2 - my1) / 2 + (w/2 + 1) * (y2 - my1 + 2) / 2;
	return 0;
}