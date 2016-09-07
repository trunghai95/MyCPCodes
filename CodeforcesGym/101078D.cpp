#include <bits/stdc++.h>

using namespace std;

int test, n;

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d", &n);
		int a = n/2 + 1;
		int res = n - a + 1;
		a = (n-1) / 3 + 1;
		a = n - a + 1;
		if ((a&1) && (n&1)) {
			a = a/2 + 1;
		} else {
			a /= 2;
		}
		res += a;
		printf("%d\n", res);
	}
	return 0;
}