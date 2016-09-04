#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll h, w, resh, resw;

int main() {

	cin >> h >> w;

	ll tmph = 1, tmpw;

	while (tmph <= h) {
		tmpw = min(tmph*5/4, w);
		if (tmpw * 5 < tmph * 4) {
			tmph *= 2;
			continue;
		}
		if (tmph*tmpw > resh*resw)
			resh = tmph, resw = tmpw;
		else if (tmph*tmpw == resh*resw && tmph > resh)
			resh = tmph, resw = tmpw;

		tmph *= 2;
	}

	tmpw = 1;

	while (tmpw <= w) {
		tmph = min(tmpw*5/4, h);
		if (tmph * 5 < tmpw * 4) {
			tmpw *= 2;
			continue;
		}
		if (tmph*tmpw > resh*resw)
			resh = tmph, resw = tmpw;
		else if (tmph*tmpw == resh*resw && tmph > resh)
			resh = tmph, resw = tmpw;

		tmpw *= 2;
	}

	cout << resh << ' ' << resw << '\n';

	return 0;
}