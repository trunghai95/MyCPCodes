#include <bits/stdc++.h>

using namespace std;

int t;
char s[10];

int main() {
	scanf("%d %s", &t, s);

	if (s[3] >= '6') {
		s[3] = '0';
	}

	if (t == 12) {
		if (s[0] > '1' || (s[0] == '1' && s[1] > '2')) {
			if (s[1] == '0') {
				s[0] = '1';
			} else {
				s[0] = '0';
			}
		}

		if (s[0] == '0' && s[1] == '0') {
			s[0] = '1';
		}
	} else {
		if (s[0] > '2' || (s[0] == '2' && s[1] > '3')) {
			s[0] = '0';
		}
	}

	printf("%s\n", s);
	return 0;
}