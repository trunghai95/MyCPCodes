#include <bits/stdc++.h>

using namespace std;

char s[50];
bool ck[300];
int n;

bool solve() {
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
	if (!ck[s[i]])
		return false;
	return true;
}

int main() {

	scanf("%s %d", s, &n);

	int len = strlen(s);
	for (int i = 0; i < len; ++i)
		ck[s[i]] = true;

	while (n --> 0) {
		scanf("%s", s);
		if (solve())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}