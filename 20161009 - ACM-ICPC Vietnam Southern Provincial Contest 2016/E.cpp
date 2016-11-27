#include <bits/stdc++.h>

using namespace std;

int a, b, c, nday, res;

int main() {

	scanf("%d %d %d", &a, &b, &c);
	nday = (a + b*2 + c*3) / 6;

	for (int i = 1; i <= nday; ++i) {
		cout << i << ' ' << a << ' ' << b << ' ' << c << '\n';
		if (a) {
			--a;
		} else if (b) {
			--b; ++a; ++res;
			cout << "a\n";
		} else {
			--c; ++b; ++res;
			cout << "b\n";
		}

		if (b) {
			--b;
		} else if (a > 1) {
			a -= 2;
		} else {
			++res; --c; ++a;
			cout << "d\n";
		}

		if (c) {
			--c;
		} else if (a && b) {
			--a; --b;
		} else if (a) {
			a -= 3;
		} else {
			b -= 2; ++a; ++res;
			cout << "c\n";
		}
	}

	printf("%d %d\n", nday, res);
	return 0;
}