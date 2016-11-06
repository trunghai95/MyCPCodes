#include <bits/stdc++.h>

using namespace std;

int test, a, b, c, d;
char sign[] = {'=', '+', '-'};

int main() {
	int tt = 0;
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d %d %d %d", &a, &b, &c, &d);

		bool done = false;

		printf("Case #%d: ", ++tt);
		for (int i = 0; !done && i < 3; ++i)
		for (int j = 0; !done && j < 3; ++j)
		for (int k = 0; !done && k < 3; ++k) {
			if (!i && !j && !k) {
				if (a == b && b == c && c == d) {
					done = true;
				}
			} else if (!i && !j) {
				if (a == b && b == c + d * (k == 1?1:-1)) {
					done = true;
				}
			} else if (!i && !k) {
				if (a == d && a == b + c * (j == 1?1:-1)) {
					done = true;
				}
			} else if (!j && !k) {
				if (c == d && c == a + b * (i == 1?1:-1)) {
					done = true;
				}
			} else if (!i) {
				if (a == b + c * (j == 1?1:-1) + d * (k == 1?1:-1)) {
					done = true;
				}
			} else if (!j) {
				if (a + b * (i == 1?1:-1) == c + d * (k == 1?1:-1)) {
					done = true;
				}
			} else if (!k) {
				if (a + b * (i == 1?1:-1) + c * (j == 1?1:-1) == d) {
					done = true;
				}
			}

			if (done) {
				printf("%d %c %d %c %d %c %d\n", a, sign[i], b, sign[j], c, sign[k], d);
				break;
			}
		}
	}
	return 0;
}