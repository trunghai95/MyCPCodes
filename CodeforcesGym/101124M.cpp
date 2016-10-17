#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

int main() {

	while (cin >> n) {
		bool f = 0;
		while (n > 1) {
			if (!f) {
				n = (n/9) + (n%9 != 0);
			} else {
				n = (n/2) + (n%2 != 0);
			}
			f = !f;
		}

		if (f) {
			cout << "Stan wins.\n";
		} else {
			cout << "Ollie wins.\n";
		}
	}
	return 0;
}