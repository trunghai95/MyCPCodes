#include <bits/stdc++.h>

using namespace std;

char s[5];

int solve() {
	if (s[0] == 'a' || s[0] == 'h') {
		if (s[1] == '1' || s[1] == '8')
			return 3;
		else return 5;
	}

	if (s[1] == '1' || s[1] == '8')
		return 5;

	return 8;
}

int main() {
	scanf("%s", s);
	printf("%d\n", solve());
	return 0;
}