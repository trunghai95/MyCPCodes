#include <bits/stdc++.h>

using namespace std;

int k, len;
char s[100010];
int pos[100010];

int main() {
	scanf("%d %s", &k, s+1);
	len = strlen(s+1);

	memset(pos, -1, sizeof(pos));

	for (int i = 1; i <= len; ++i)
	if (s[i] == '1') {
		int m = i % k;
		m = (m - 1 + k) % k;

		if (pos[m] != -1) {
			printf("%d %d\n", pos[m], i);
			return 0;
		}

		pos[i % k] = i;
	}

	printf("0 0\n");
	return 0;
}