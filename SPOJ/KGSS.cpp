#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
const int SQRTMAX = 316;

int n, a[MAXN + 5], mx[SQRTMAX+5][2], nzone, q, res1, res2, u, v;
char s[5];

void proc(const int& x) {
	if (x > res1) {
		res2 = res1;
		res1 = x;
	} else if (x > res2) {
		res2 = x;
	}
}

void findmax(const int& zone) {
	res1 = res2 = 0;

	for (int i = zone*SQRTMAX; i < (zone + 1)*SQRTMAX; ++i) {
		proc(a[i]);
	}

	mx[zone][0] = res1;
	mx[zone][1] = res2;
}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);

	nzone = (n - 1) / SQRTMAX;

	for (int i = 0; i < nzone; ++i) {
		findmax(i);
	}

	scanf("%d", &q);

	while (q --> 0) {
		scanf("%s %d %d", s, &u, &v);

		if (s[0] == 'U') {
			--u;
			a[u] = v;
			if (u/SQRTMAX != nzone)
				findmax(u/SQRTMAX);
		} else {
			--u, --v;
			res1 = 0, res2 = 0;
			int zoneu = u/SQRTMAX;
			int zonev = v/SQRTMAX;

			if (zoneu == zonev) {
				for (int i = u; i <= v; ++i)
					proc(a[i]);
			} else {
				for (int i = u; i < min(n, (zoneu + 1)*SQRTMAX); ++i)
					proc(a[i]);

				for (int i = v; i >= zonev*SQRTMAX; --i)
					proc(a[i]);

				for (int i = zoneu + 1; i < zonev; ++i) {
					proc(mx[i][0]);
					proc(mx[i][1]);
				}
			}

			printf("%d\n", res1+res2);
		}
	}
	return 0;
}