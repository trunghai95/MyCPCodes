#include <bits/stdc++.h>

using namespace std;

int n, m, a[111], b[111], res;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);

	scanf("%d", &m);

	for (int i = 0; i < m; ++i)
		scanf("%d", b+i);

	sort(b, b+m);

	int i = 0, j = 0;

	while (i < n) {
		while (j < m && b[j] < a[i] - 1)
			++j;

		if (abs(a[i] - b[j]) <= 1)
			++res, ++j;

		++i;
	}

	printf("%d\n", res);
	return 0;
}