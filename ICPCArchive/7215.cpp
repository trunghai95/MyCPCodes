#include <bits/stdc++.h>

using namespace std;

int test, n, grundy[1001];
bool ck[1001];

int main() {
	grundy[0] = 0;
	grundy[1] = 1;

	for (int i = 2; i <= 1000; ++i) {
		memset(ck, 0, sizeof(ck));

		ck[grundy[i-2]] = true;

		for (int j = 0; j <= i - j - 3; ++j) {
			ck[grundy[j] ^ grundy[i - j - 3]] = true;
		}

		for (int j = 0; j <= 1000; ++j) {
			if (!ck[j]) {
				grundy[i] = j;
				break;
			}
		}
	}
	
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt) {
		scanf("%d", &n);
		if (n > 1000) {
			n = n % 34 + 68;
		}

		printf("Case #%d: ", tt);
		if (!grundy[n]) {
			printf("UCOK\n");
		} else {
			printf("UDIN\n");
		}
	}
	return 0;
}