#include <bits/stdc++.h>

using namespace std;

int y, res, a, b, c;

int main() {
	cin >> y >> a;
	b = c = a;

	while (a < y) {
		++res;
		a = min(y, b+c-1);
		if (a > b)
			swap(a, b);
		if (b > c)
			swap(b, c);
	}

	cout << res << '\n';
	return 0;
}