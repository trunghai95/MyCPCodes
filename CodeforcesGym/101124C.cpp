#include <bits/stdc++.h>

using namespace std;

typedef pair<string, string> pss;

string name[] = {"king", "queen", "bishop", "knight", "rook", "pawn"};
int maxPc[] = {1, 1, 2, 2, 2, 8};
int k1, k2, cnt[2][10];
string s, t;
vector<pss> res;

int main() {

	cin >> k1 >> k2;

	for (int i = 0; i < k1; ++i) {
		cin >> s >> t;
		int type = 0;
		for (int i = 0; i < 6; ++i)
		if (name[i] == t) {
			type = i;
			break;
		}

		if (s == "white") {
			++cnt[0][type];
		} else {
			++cnt[1][type];
		}
	}

	for (int i = 0; i < k2; ++i) {
		cin >> s >> t;
		int type = 0;
		for (int i = 0; i < 6; ++i)
		if (name[i] == t) {
			type = i;
			break;
		}
		int color = (s == "black");

		if (cnt[color][type] < maxPc[type]) {
			++cnt[color][type];
			res.push_back(pss(s, t));
		}
	}

	if (k1 + res.size() < 32) {
		cout << "impossible\n";
	} else {
		for (int i = 0; i < (int)res.size(); ++i) {
			cout << res[i].first << ' ' << res[i].second << '\n';
		}
	}
	return 0;
}