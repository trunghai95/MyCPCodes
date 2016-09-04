#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

int main() {

	while (true) {
		scanf("%lld", &n);

		if (n == 0) {
			return 0;
		}

		if (n < 3) {
			printf("No such base\n");
			continue;
		}

		if (n == 3) {
			printf("4\n");
			continue;
		}

		n -= 3;
		ll res = 4;

		while (res*res <= n) {
			if (n % res == 0)
				break;
			++res;
		}

		if (n % res != 0) {
			if (n % 3 == 0)
				res = n/3;
			else if (n % 2 == 0)
				res = n/2;
		}

		if (n % res == 0 && res >= 4)
			printf("%lld\n", res);
		else if (n >= 4)
			printf("%lld\n", n);
		else
			printf("No such base\n");
	}
	return 0;
}