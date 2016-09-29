#include <bits/stdc++.h>

using namespace std;

int n, cnt1, cnt2, cnt3;
string s;

int main() {
	cin >> n;
	getline(cin, s);

	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		if (s.find("blue") != string::npos && s.find("black") != string::npos) {
			++cnt1;
		} else if (s.find("white") != string::npos && s.find("gold") != string::npos) {
			++cnt2;
		} else {
			++cnt3;
		}
	}

	cout << fixed << setprecision(12);
	cout << 100.0*cnt1/n << '\n' << 100.0*cnt2/n << '\n' << 100.0*cnt3/n << '\n';
	return 0;
}