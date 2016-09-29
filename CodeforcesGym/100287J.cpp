#include <bits/stdc++.h>

using namespace std;

char s[200];
int len, type;

int main() {
	freopen("java_c.in", "r", stdin);
	freopen("java_c.out", "w", stdout);
	scanf("%s", s);
	len = strlen(s);

	if ((s[0] >= 'A' && s[0] <= 'Z') || s[0] == '_' || s[len-1] == '_') {
		printf("Error!\n");
		return 0;
	}

	for (int i = 1; i < len; ++i) {
		if (s[i] == '_') {
			if (type == 2 || s[i-1] == '_') {
				printf("Error!\n");
				return 0;
			}
			type = 1;
		} else if (s[i] >= 'A' && s[i] <= 'Z') {
			if (type == 1) {
				printf("Error!\n");
				return 0;
			}
			type = 2;
		}
	}

	if (type == 0) {
		printf("%s\n", s);
	} else if (type == 1) {
		printf("%c", s[0]);
		for (int i = 1; i < len; ++i) {
			if (s[i] == '_') {
				continue;
			} else if (s[i-1] == '_') {
				printf("%c", s[i] - 'a' + 'A');
			} else {
				printf("%c", s[i]);
			}
		}
		printf("\n");
	} else if (type == 2) {
		printf("%c", s[0]);
		for (int i = 1; i < len; ++i) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				printf("_%c", s[i] - 'A' + 'a');
			} else {
				printf("%c", s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}