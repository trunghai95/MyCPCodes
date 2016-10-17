#include <bits/stdc++.h>

using namespace std;

int n, k, cnt[111], len;
char s[111];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		++cnt[strlen(s)];
	}
	scanf("%s", s);
	len = strlen(s);

	int res = 0;

	for (int i = 1; i < len; ++i) {
		res += cnt[i];
	}

	printf("%d ", res + res/k*5 + 1);
	res += cnt[len];
	printf("%d\n", res + (res-1)/k*5);
	return 0;
}