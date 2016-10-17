#include <bits/stdc++.h>

using namespace std;

int n, p[111];
string s;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	getline(cin, s);

	for (int k = 1; k <= n; ++k) {
		getline(cin, s);
		int cnt = 0;
		for (int i = 0; i < (int)s.length(); ++i) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'
				|| s[i] == 'u' || s[i] == 'y') {
				++cnt;
			}
		}

		if (cnt != p[k]) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	return 0;
}