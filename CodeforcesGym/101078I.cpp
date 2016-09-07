#include <bits/stdc++.h>

using namespace std;

int test;
char s[1000010];

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%s", s);
		int n = strlen(s);

		list<char> lis;
		list<char>::iterator it = lis.begin();

		for (int i = 0; i < n; ++i) {
			if (s[i] == '<') {
				if (it != lis.begin())
					--it;
			} else if (s[i] == '>') {
				if (it != lis.end())
					++it;
			} else if (s[i] == '-') {
				if (it != lis.begin()) {
					--it;
					it = lis.erase(it);
				}
			} else {
				lis.insert(it, s[i]);
			}
		}

		for (it = lis.begin(); it != lis.end(); ++it) {
			printf("%c", *it);
		}

		printf("\n");
	}
	return 0;
}