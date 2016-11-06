#include <bits/stdc++.h>

using namespace std;

int n;
char s[2600];

bool solve(char from, char to, char mid, int pos) {
	if (pos == 0) return true;

	if (s[pos] == from) {
		return solve(from, mid, to, pos-1);
	} else if (s[pos] == to) {
		return solve(mid, to, from, pos-1);
	} else {
		return false;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %s", &n, s + 1);

	if (solve('A', 'B', 'C', n))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}