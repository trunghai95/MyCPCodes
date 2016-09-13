#include <bits/stdc++.h>

using namespace std;

int n, a[100010];

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}

	for (int i = 1; i <= n; ++i)
		printf("%d ", a[i] + a[i+1]);

	printf("\n");
	return 0;
}