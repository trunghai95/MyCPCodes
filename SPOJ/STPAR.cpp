#include <iostream>
#include <stdio.h>

using namespace std;

int a[1010], b[1010], x, sza, szb, n;

bool solve() {
	sza = szb = 0;

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);

		if (x == a[sza] + 1) {
			a[++sza] = x;
			while (szb > 0 && b[szb] == a[sza] + 1) {
				a[++sza] = b[szb];
				--szb;
			}
		} else {
			b[++szb] = x;
		}
	}

	return (sza == n);
}

int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}

		if (solve()) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	return 0;
}