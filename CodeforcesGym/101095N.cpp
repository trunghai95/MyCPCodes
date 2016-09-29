#include <bits/stdc++.h>

using namespace std;

char s[10], t[100];
int r, n, sign;

int main() {
	while (true) {
		scanf("%s", t);
		if (t[0] == 'e') {
			return 0;
		}

		for (int i = 0; t[i]; ++i)
		if (t[i] == '-') {
			t[i] = ' ';
		}

		sscanf(t, "%s %d", s, &r);

		if (s[0] == 'f') {
			scanf("%s", t);
			n = 0;
			r = -r;
			for (int i = 0; t[i]; ++i) {
				n = n * r + t[i] - '0';
			}
			printf("%d\n", n);
		} else {
			scanf("%d", &n);
			if (n == 0) {
				printf("0\n");
				continue;
			}
			sign = -1;
			if (n < 0) {
				sign = -sign;
				n = -n;
			}

			string res;
			while (n) {
				sign = -sign;
				if (n % r == 0) {
					res.push_back('0');
					n /= r;
					continue;
				}

				if (sign > 0) {
					res.push_back(n % r + '0');
					n /= r;
				} else {
					res.push_back((n/r + 1) * r - n + '0');
					n = n/r + 1;
				}
			}

			reverse(res.begin(), res.end());
			printf("%s\n", res.c_str());
		}
	}
	return 0;
}