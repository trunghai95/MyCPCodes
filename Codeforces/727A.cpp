#include <bits/stdc++.h>

using namespace std;

int a, b;
vector<int> res;

int main() {
	scanf("%d %d", &a, &b);

	res.push_back(b);
	while (b > a) {
		if (b&1) {
			if (b % 10 == 1) {
				b = b/10;
			} else {
				printf("NO\n");
				return 0;
			}
		} else {
			b = b/2;
		}

		res.push_back(b);
	}

	if (b != a) {
		printf("NO\n");
	} else {
		printf("YES\n%d\n", (int)res.size());
		for (int i = res.size() - 1; i >= 0; --i) {
			printf("%d ", res[i]);
		}
		printf("\n");
	}
	return 0;
}