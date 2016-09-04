#include <bits/stdc++.h>

using namespace std;

int test, n, a[20];

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d", &n);

		int sum = 0, mx = 0, mxi = 0;
		
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a+i);
			sum += a[i];
			if (a[i] > mx)
				mx = a[i], mxi = i;
			else if (a[i] == mx)
				mxi = -1;

		}

		if (mxi != -1) {
			if (mx*2 > sum)
				printf("majority winner %d\n", mxi);
			else
				printf("minority winner %d\n", mxi);
		} else {
			printf("no winner\n");
		}

	}
	return 0;
}