#include <bits/stdc++.h>

using namespace std;

int len1, len2, cur;
char s1[20], s2[20];

int main() {

	scanf("%s", s1);
	printf("%s\n", s1);
	len1 = strlen(s1);

	while (scanf("%s", s2) != EOF) {
		len2 = strlen(s2);

		int mm = min(cur+1, len2);
		for (int i = 0; i < mm; ++i) {
			if (s1[i] != s2[i]) {
				cur = i - 1;
				break;
			}
			printf(" ");
		}

		++cur;
		printf("%s\n", s2);

		strcpy(s1, s2);
		len1 = len2;
	}
	return 0;
}