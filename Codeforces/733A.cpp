#include <bits/stdc++.h>

using namespace std;

char s[200];

int main() {
	s[0] = 'A';
	scanf("%s", s+1);
	int len = strlen(s);
	s[len] = 'A';
	s[len+1] = 0;
	++len;

	int last = 0;
	int res = 0;
	for (int i = 1; i < len; ++i) {
		if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' 
			|| s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
			res = max(res, i - last);
			last = i;
		}
	}

	printf("%d\n", res);
	return 0;
}