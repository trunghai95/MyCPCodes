#include <bits/stdc++.h>

using namespace std;

int n, t;
char s[60];

int main() {
	scanf("%d %d %s", &n, &t, s);

	while (t --> 0) {
		for (int i = 1; i < n; ++i)
		if (s[i] == 'G' && s[i-1] == 'B') {
			swap(s[i], s[i-1]);
			++i;
		}
	}

	printf("%s\n", s);
	return 0;
}