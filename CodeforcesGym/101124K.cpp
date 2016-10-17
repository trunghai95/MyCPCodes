#include <bits/stdc++.h>

using namespace std;

double speed, lastpos;
int t, lastt;
string S;

int main() {
	while (getline(cin, S)) {
		S[2] = S[5] = ' ';
		int h, m, s;
		stringstream ss(S);
		ss >> h >> m >> s;
		t = s + m*60 + h*3600;

		if (S.length() > 8) {
			lastpos += speed * (1.0*t - lastt) / 3600;
			ss >> speed;
			lastt = t;
		} else {
			double res = lastpos + speed * (1.0*t - lastt) / 3600;
			printf("%02d:%02d:%02d %.2lf km\n", h, m, s, res);
		}
	}
	return 0;
}