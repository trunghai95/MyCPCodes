#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

#define DEBUG(x) cout << #x << ": " << x << '\n'

int n, a;
int x[4], y[4];
int rx[4], ry[4];

int check(int a, int b, int c, int d) {
	printf("? %d %d %d %d\n", a, b, c, d);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}

int main() {
	scanf("%d", &n);

	int lo = 1, hi = n;
	while (lo < hi) {
		int mid = (lo + hi) / 2 + 1;
		a = check(mid, 1, n, n);

		if (a < 2) {
			hi = mid - 1;
		} else {
			lo = mid;
		}
	}
	x[0] = lo;

	lo = x[0], hi = n;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		a = check(x[0], 1, mid, n);
		if (a < 2) {
			lo = mid + 1;
		} else {
			hi = mid;
		}
	}
	x[3] = lo;

	lo = x[0], hi = x[3];
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		a = check(x[0], 1, mid, n);
		if (a < 1) {
			lo = mid + 1;
		} else {
			hi = mid;
		}
	}
	x[1] = lo;

	lo = x[0], hi = x[3];
	while (lo < hi) {
		int mid = (lo + hi) / 2 + 1;
		a = check(mid, 1, x[3], n);
		if (a < 1) {
			hi = mid - 1;
		} else {
			lo = mid;
		}
	}
	x[2] = lo;

	if (x[1] >= x[2]) {
		swap(x[1], x[2]);
		a = check(x[1], 1, x[2], n);
		if (a == 1) {
			rx[2] = x[1], rx[3] = x[2];
			rx[0] = x[0], rx[1] = x[3];
		} else {
			rx[0] = x[0], rx[1] = x[2];
			rx[2] = x[1], rx[3] = x[3];
		}
	} else {
		rx[0] = x[0], rx[1] = x[1];
		rx[2] = x[2], rx[3] = x[3];
	}

	if (rx[0] <= rx[2] && rx[1] >= rx[3]) {
		// cai nay chua cai kia
		lo = 1, hi = n;
		while (lo < hi) {
			int mid = (lo + hi) / 2 + 1;
			a = check(1, mid, n, n);
			if (a < 2) {
				hi = mid - 1;
			} else {
				lo = mid;
			}
		}
		y[0] = lo;

		lo = 1, hi = n;
		while (lo < hi) {
			int mid = (lo + hi) / 2 + 1;
			a = check(1, mid, n, n);
			if (a < 1) {
				hi = mid - 1;
			} else {
				lo = mid;
			}
		}
		y[2] = lo;

		lo = 1, hi = n;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			a = check(1, 1, n, mid);
			if (a < 2) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}
		y[3] = lo;

		lo = 1, hi = n;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			a = check(1, 1, n, mid);
			if (a < 1) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}
		y[1] = lo;

		a = check(rx[2], y[0], rx[3], y[1]);
		if (a == 1) swap(y[0], y[2]), swap(y[1], y[3]);
		memcpy(ry, y, sizeof(y));
	} else {
		lo = 1, hi = n;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			a = check(rx[0], 1, rx[1], mid);
			if (a < 1) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}
		ry[1] = lo;

		lo = 1, hi = ry[1];
		while (lo < hi) {
			int mid = (lo + hi) / 2 + 1;
			a = check(rx[0], mid, rx[1], ry[1]);
			if (a < 1) {
				hi = mid - 1;
			} else {
				lo = mid;
			}
		}
		ry[0] = lo;

		lo = 1, hi = n;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			a = check(rx[2], 1, rx[3], mid);
			if (a < 1) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}
		ry[3] = lo;

		lo = 1, hi = ry[3];
		while (lo < hi) {
			int mid = (lo + hi) / 2 + 1;
			a = check(rx[2], mid, rx[3], ry[3]);
			if (a < 1) {
				hi = mid - 1;
			} else {
				lo = mid;
			}
		}
		ry[2] = lo;
	}

	printf("!");
	for (int i = 0; i < 4; ++i)
		printf(" %d %d", rx[i], ry[i]);
	printf("\n");

	return 0;
}