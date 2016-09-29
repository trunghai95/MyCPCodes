#include <bits/stdc++.h>

using namespace std;

int test;
int a[2], b[2], ta, tb, r1, r2;

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d %d %d %d %d %d", a, b, a+1, b+1, &ta, &tb);

		r1 = r2 = -1;

		for (int i = 1; ; ++i) {
			if (a[0] * i >= ta || b[0] * i >= tb) {
				break;
			}

			int aa = ta - a[0] * i;
			if (aa % a[1] != 0) {
				continue;
			}

			int j = aa / a[1];
			if (i * b[0] + j * b[1] == tb) {
				// cout << i << ' ' << j << '\n';
				if (r1 != -1) {
					r1 = r2 = -1;
					break;
				}
				r1 = i, r2 = j;
			}
		}

		if (r1 == -1) {
			printf("?\n");
		} else {
			printf("%d %d\n", r1, r2);
		}
	}
	return 0;
}