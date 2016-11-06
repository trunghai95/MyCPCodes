#include <bits/stdc++.h>

using namespace std;

char s[300];
int n;

int main() {
	while (scanf("%s", s) != EOF) {
		n = strlen(s);
		for (int i = 0; i < n; ++i) {
			char c = 0;
			if (s[i] >= '0' && s[i] <= '9') {
				c += (s[i] - '0') * 16;
			} else {
				c += (s[i] - 'A' + 10) * 16;
			}
			++i;
			if (s[i] >= '0' && s[i] <= '9') {
				c += (s[i] - '0');
			} else {
				c += (s[i] - 'A' + 10);
			}

			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}