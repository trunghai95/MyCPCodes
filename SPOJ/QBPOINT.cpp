// O(n^2 logn)
// TLE

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, x[2000], y[2000];
int res;

int gcd(int x, int y) {
	if (!x)
		return y;
	return gcd(y % x, x);
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d", x+i, y+i);
		map<pii, int> cnt;
		for (int j = 0; j < i; ++j) {
			int xx = x[j] - x[i], yy = y[j] - y[i];
			if (xx == 0) {
				yy = 1;
			} else if (yy == 0) {
				xx = 1;
			} else {
				int g = gcd(xx, yy);
				xx /= g;
				yy /= g;
			}

			++cnt[pii(xx, yy)];
		}

		map<pii, int>::iterator it = cnt.begin();

		while (it != cnt.end()) {
			res += (it->second * (it->second - 1) >> 1);
			++it;
		}
	}

	printf("%d\n", res);
	return 0;
}