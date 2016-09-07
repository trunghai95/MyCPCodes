#include <bits/stdc++.h>

using namespace std;

int test, n, a[100010], b[100010];
bool ca[100010], cb[100010];

int main() {

	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d", &n);
		memset(ca, 0, sizeof(ca));
		memset(cb, 0, sizeof(cb));

		for (int i = 1; i <= n; ++i)
			scanf("%d", a+i);
		for (int i = 1; i <= n; ++i)
			scanf("%d", b+i);

		int last = 1, cnt = 0;

		for (int i = 1; i <= n; ++i) {
			ca[a[i]] = true;
			cb[b[i]] = true;

			if (a[i] != b[i]) {
				if (cb[a[i]])
					--cnt;
				else
					++cnt;
				if (ca[b[i]])
					--cnt;
				else
					++cnt;
			}

			if (!cnt) {
				printf("%d-%d ", last, i);
				last = i+1;
			}
		}

		printf("\n");
	}
	return 0;
}