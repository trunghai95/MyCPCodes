#include <bits/stdc++.h>

using namespace std;

typedef pair<string, string> pss;

int n;
map<string, int> cnt;
string s, t;
vector<pss> res;

int main() {

	cin >> n;

	while (n --> 0 && res.size() < 10) {
		cin >> s >> t;
		if (s == "SCH") {
			continue;
		}

		if (s == "MSU") {
			if (cnt[s] < 4) {
				++cnt[s];
				res.push_back(pss(s, t));
			}
		} else {
			if (cnt[s] < 2) {
				++cnt[s];
				res.push_back(pss(s, t));
			}
		}
	}

	cout << res.size() << '\n';
	for (int i = 0; i < (int)res.size(); ++i) {
		cout << res[i].first << ' ' << res[i].second << '\n';
	}
	return 0;
}