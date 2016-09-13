#include <bits/stdc++.h>

using namespace std;

char s[100010];
int cnt[4];

int main() {
	scanf("%s", s);
	int len = strlen(s);

	for (int i = 0; i < len; ++i) {
		if (s[i] == 'L')
			++cnt[0];
		else if (s[i] == 'R')
			++cnt[1];
		else if (s[i] == 'U')
			++cnt[2];
		else if (s[i] == 'D')
			++cnt[3];
	}

	if (len & 1) {
		printf("-1\n");
		return 0;
	}

	cnt[0] = abs(cnt[0] - cnt[1]);
	cnt[2] = abs(cnt[2] - cnt[3]);

	printf("%d\n", (cnt[0] + cnt[2]) / 2);
	return 0;
}