#include <bits/stdc++.h>

using namespace std;

int test, len;
char s[111], a[111][111];

bool Try(int n, int m) {
	memset(a, 0, sizeof(a));

	int curx = 1, cury = 1, i = 0, dx = 0, dy = 1, newx, newy;
	while (i < len) {
		a[curx][cury] = s[i];
		if (a[curx][cury] != a[1][cury]) {
			return false;
		}
		newx = curx + dx;
		newy = cury + dy;
		if (newx > n || newy > m || newx < 1 || newy < 1 || a[newx][newy] != 0) {
			if (dx == 1) dx = 0, dy = -1;
			else if (dx == -1) dx = 0, dy = 1;
			else if (dy == 1) dx = 1, dy = 0;
			else if (dy == -1) dx = -1, dy = 0;
			newx = curx + dx;
			newy = cury + dy;
		}
		curx = newx;
		cury = newy;
		++i;
	}

	return true;
}

int main() {
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt) {
		scanf("%s", s);
		len = strlen(s);
		int res = -1;

		for (int i = 2; i*i <= len; ++i)
		if (len % i == 0) {
			int j = len / i;
			if (Try(i, j) || Try(j, i)) {
				res = i+j;
			}
		}

		printf("Case %d: %d\n", tt, res);
	}
	return 0;
}