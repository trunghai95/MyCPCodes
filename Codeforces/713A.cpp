#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int n, cnt[300010];
char s[5];
ll x;

int code(ll x) {
	int res = 0, b = 1;
	while (x) {
		if (x % 10 % 2) {
			res += b;
		}

		x /= 10;
		b *= 2;
	}

	return res;
}

int main() {
	scanf("%d", &n);

	while (n --> 0) {
		scanf("%s %llu", s, &x);
		if (s[0] == '+') {
			++cnt[code(x)];
		} else if (s[0] == '-') {
			--cnt[code(x)];
		} else {
			printf("%d\n", cnt[code(x)]);
		}
	}
	return 0;
}