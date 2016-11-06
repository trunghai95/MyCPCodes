#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b;

bool isPrime(const ll &n) {
	if (n < 2) return false;
	if (n == 2) return true;
	for (ll i = 2; i*i <= n; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	cin >> a >> b;

	if (a == 2) {
		if (isPrime(b-2)) {
			cout << a << "->" << b << '\n';
		} else if (isPrime(b+2)) {
			cout << a << "->" << b+2 << "->" << b << '\n';
		} else {
			cout << "Unlucky Benny\n";
		}
	} else if (a + 2 == b) {
		cout << a << "->" << b << '\n';
	} else if (a == 3 && b == 7) {
		cout << "3->5->7\n";
	} else if (isPrime(a-2)) {
		if (isPrime(b-2)) {
			cout << a << "->2->" << b << '\n';
		} else if (isPrime(b+2)) {
			cout << a << "->2->" << b+2 << "->" << b << '\n';
		} else {
			cout << "Unlucky Benny\n";
		}
	} else if (isPrime(a+2)) {
		if (isPrime(b-2)) {
			cout << a << "->" << a+2 << "->2->" << b << '\n';
		} else if (isPrime(b+2)) {
			cout << a << "->" << a+2 << "->2->" << b+2 << "->" << b << '\n';
		} else {
			cout << "Unlucky Benny\n";
		}
	} else {
		cout << "Unlucky Benny\n";
	}
	return 0;
}