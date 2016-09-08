#include <bits/stdc++.h>

using namespace std;

int test, cnt[2], n;
char s[100010];

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%s", s);

		cnt[0] = cnt[1] = 0;

		n = strlen(s);

		for (int i = 0; i < n; ++i) {
			++cnt[s[i] - '0'];
		}

		if (cnt[0] == 1 || cnt[1] == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}