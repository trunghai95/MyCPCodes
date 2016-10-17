#include <bits/stdc++.h>

using namespace std;

int n, k, a[510], b[510], res = 2e9, resp;

void Try(int p) {
	memcpy(b, a, sizeof(a));

	int cnt = 0;

	for (int i = p+1; i <= n; ++i) {
		if (b[i] + b[i-1] < k) {
			cnt += k - b[i] - b[i-1];
			b[i] = k - b[i-1];
		}
	}

	for (int i = p-1; i >= 1; --i) {
		if (b[i] + b[i+1] < k) {
			cnt += k - b[i] - b[i+1];
			b[i] = k - b[i+1];
		}
	}

	if (cnt < res) {
		res = cnt;
		resp = p;
	}
}

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}

	for (int i = 1; i <= n; ++i) {
		Try(i);
	}

	for (int i = resp+1; i <= n; ++i) {
		if (a[i] + a[i-1] < k) {
			a[i] = k - a[i-1];
		}
	}

	for (int i = resp-1; i >= 1; --i) {
		if (a[i] + a[i+1] < k) {
			a[i] = k - a[i+1];
		}
	}

	printf("%d\n", res);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}

	printf("\n");
	return 0;
}