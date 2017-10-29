#include <bits/stdc++.h>

using namespace std;

int test, a[4], p, q;

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		for (int i = 0; i < 4; ++i) {
			scanf("%d", a+i);
		}

		scanf("%d %d", &p, &q);

		printf("%d\n", a[0]*a[1]*a[2]*a[3]/(p*q));
	}
	return 0;
}