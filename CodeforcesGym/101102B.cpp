#include <bits/stdc++.h>

using namespace std;

int cc[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dg[8] = {-1, -1, 1, 7, 4, 5, 9, 8};
int test, n, sum, a, b, c;
char s[100010];

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d %s", &n, s);
		sum = 0;
		if (n == 1) {
			for (int i = 9; i >= 0; --i) {
				if (cc[i] == cc[s[0] - '0']) {
					printf("%d\n", i);
					break;
				}
			}
			continue;
		}

		for (int i = 0; i < n; ++i)
			sum += cc[s[i] - '0'];

		cout << sum << ' ' << n << '\n';

		for (a = n; a >= 0; --a) {
			b = sum - 2*n - 4*a;
			c = n - a - b;
			cout << a << ' ' << b << ' ' << c << '\n';
			if (b >= 0 && c >= 0)
				break;
		}

		while (a --> 0) {
			printf("9");
		}
		while (b --> 0) {
			printf("7");
		}
		while (c --> 0) {
			printf("1");
		}
		printf("\n");
	}
	return 0;
}