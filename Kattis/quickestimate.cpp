#include <bits/stdc++.h>

using namespace std;

int test;
char s[1000];

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%s", s);
		printf("%d\n", strlen(s));
	}
	return 0;
}