#include <bits/stdc++.h>

using namespace std;

int test, n, x, y;

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d", &n);
		int res = 0;

		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &x, &y);
			int dist = x*x + y*y;

			if (dist > 40000)
				continue;

			int pt = 11, cur = 0;

			while (true) {
				--pt, cur += 20;
				if (cur > 200) {
					pt = 0;
					break;
				}
				if (dist <= cur*cur) {
					break;
				}
			}
			res += pt;
		}

		printf("%d\n", res);
	}
	return 0;
}