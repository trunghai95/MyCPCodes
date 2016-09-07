#include <bits/stdc++.h>

using namespace std;

char s[500000], t[10];
int n, len;

int f(int x) {
	if (x < 10) return 1;
	if (x < 100) return 2;
	if (x < 1000) return 3;
	if (x < 10000) return 4;
	if (x < 100000) return 5;
	return 6;
}

void init() {
	for (int i = 1; i <= 100000; ++i) {
		sprintf(s + len, "%d", i);
		len += f(i);
	}
}

int main() {
	init();
	scanf("%s", t);
	n = strlen(t);

	for (int i = 0; i <= len - n; ++i) {
		bool flag = true;

		for (int j = 0; flag && j < n; ++j)
		if (t[j] != s[i+j])
			flag = false;

		if (flag) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	return 0;
}