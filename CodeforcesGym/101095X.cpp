#include <bits/stdc++.h>

using namespace std;

int m, a[13], res1, res2, res;

int main() {

	scanf("%d", &m);
	for (int i = 1; i <= 12; ++i) {
		scanf("%d", a+i);
	}

	for (int i = 1; i < 12; ++i)
	for (int j = i + 1; j <= 12; ++j) {
		int tmp = m / a[i];
		tmp = tmp*a[j] - tmp*a[i];
		if (tmp > res || (tmp == res && (!res1 || a[i] < a[res1]))) {
			res = tmp;
			res1 = i;
			res2 = j;
		}
	}

	if (res > 0) {
		printf("%d %d %d\n", res1, res2, res);
	} else {
		printf("IMPOSSIBLE\n");
	}
	return 0;
}