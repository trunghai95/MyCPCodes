#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main()
{
	cin >> a >> b >> c;
	bool res;
	if (!c)
		res = (a == b);
	else
		res = ((b - a) % c == 0 && (b - a) / c >= 0);

	cout << (res?"YES":"NO");
	return 0;
}