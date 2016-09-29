#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, -1, 1};

int test, n, m, x, y, curDir;
ll dist[110][110][4], k;
char s[3];

void solve() {
	scanf("%d %d %s %d %d %lld", &n, &m, s, &x, &y, &k);
	if (s[0] == 'S') {
		if (s[1] == 'E')
			curDir = 0;
		else
			curDir = 1;
	} else {
		if (s[1] == 'W')
			curDir = 2;
		else
			curDir = 3;
	}

	memset(dist, -1, sizeof(dist));

	ll cur = 0;
	while (true) {
		if (cur == k) {
			printf("%d %d\n", x, y);
			return;
		}

		ll dd = dist[x][y][curDir];
		if (dd != -1 && (k - dd) % (cur - dd) == 0) {
			// cout << curDir << '\n';
			printf("%d %d\n", x, y);
			return;
		}

		dist[x][y][curDir] = cur;

		int xx = x + dx[curDir];
		int yy = y + dy[curDir];

		if (xx > n) {
			xx = n;
			if (yy > m) {
				yy = m;
				curDir = 2;
			} else if (yy < 1) {
				yy = 1;
				curDir = 3;
			} else {
				if (curDir == 0) curDir = 3;
				else curDir = 2;
			}
		} else if (xx < 1) {
			xx = 1;
			if (yy > m) {
				yy = m;
				curDir = 1;
			} else if (yy < 1) {
				yy = 1;
				curDir = 0;
			} else {
				if (curDir == 3) curDir = 0;
				else curDir = 1;
			}
		} else {
			if (yy > m) {
				yy = m;
				if (curDir == 3) curDir = 2;
				else curDir = 1;
			} else if (yy < 1) {
				yy = 1;
				if (curDir == 2) curDir = 3;
				else curDir = 0;
			}
		}

		x = xx;
		y = yy;
		++cur;
	}
}

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		solve();
	}
	return 0;
}