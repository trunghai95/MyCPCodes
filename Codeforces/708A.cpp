#include <bits/stdc++.h>

using namespace std;

int n, i;
char s[100010];

int main() {
	scanf("%s", s);
	n = strlen(s);

	for (i = 0; i < n; ++i) {
		if (s[i] != 'a')
			break;
	}

	if (i == n)
		s[n-1] = 'z';

	for (; i < n && s[i] != 'a'; ++i)
		s[i] -= 1;

	printf("%s\n", s);
	return 0;
}