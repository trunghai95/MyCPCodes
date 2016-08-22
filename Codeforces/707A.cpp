#include <bits/stdc++.h>

using namespace std;

int n, m;
char s;

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j) {
		scanf("%s", s);
		if (s[0] != 'W' && s[0] != 'B' && s[0] != 'G') {
			printf("#Color\n");
			return 0;
		}
	}
	printf("#Black&White\n");
	return 0;
}