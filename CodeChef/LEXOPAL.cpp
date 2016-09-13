#include <bits/stdc++.h>

using namespace std;

int test, n;
char s[13000];

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%s", s);
		n = strlen(s);
		bool f = true;

		for (int i = 0; f && i <= n/2; ++i) {
			int j = n - i - 1;
			if (s[i] == '.') {
				if (s[j] == '.')
					s[i] = s[j] = 'a';
				else
					s[i] = s[j];
			} else if (s[j] == '.') {
				s[j] = s[i];
			} else if (s[i] != s[j]) {
				f = false;
			}
		}

		if (f)
			printf("%s\n", s);
		else
			printf("-1\n");
	}
	return 0;
}