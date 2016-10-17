#include <bits/stdc++.h>

using namespace std;

int n, a[5010], s12, s23, s13;

int get(int i, int j) {
	printf("? %d %d\n", i, j);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}

int main() {

	scanf("%d", &n);

	s12 = get(1, 2);
	s23 = get(2, 3);
	s13 = get(1, 3);

	a[1] = (s12 + s13 - s23) / 2;
	a[2] = s12 - a[1];
	a[3] = s13 - a[1];

	for (int i = 4; i <= n; ++i) {
		a[i] = get(1, i) - a[1];
	}

	printf("!");
	for (int i = 1; i <= n; ++i) {
		printf(" %d", a[i]);
	}
	printf("\n");
	return 0;
}