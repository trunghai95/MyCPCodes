#include <bits/stdc++.h>

using namespace std;

int n, l[100010], r[100010], mx, res, suml, sumr;

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", l+i, r+i);
		suml += l[i];
		sumr += r[i];
	}

	mx = abs(suml - sumr);
	res = 0;

	for (int i = 1; i <= n; ++i) {
		int tmp = abs((suml - l[i] + r[i]) - (sumr - r[i] + l[i]));
		if (tmp > mx) {
			mx = tmp;
			res = i;
		}
	}

	printf("%d\n", res);
	return 0;
}