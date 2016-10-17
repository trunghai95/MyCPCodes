#include <bits/stdc++.h>

using namespace std;

string s, t;
string day[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int get(string &a) {
	for (int i = 0; i < 7; ++i) {
		if (day[i] == a)
			return i;
	}
	return 6;
}

int main() {
	cin >> s >> t;
	int ss = get(s);
	int tt = get(t);

	if (ss == tt || (ss + 2) % 7 == tt || (ss + 3) % 7 == tt) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}