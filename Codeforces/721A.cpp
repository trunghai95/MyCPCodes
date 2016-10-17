#include <bits/stdc++.h>

using namespace std;

int n;
char s[111];
vector<int> res;

int main() {
	scanf("%d %s", &n, s+1);

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == 'B') {
			++cnt;
		} else if (s[i-1] == 'B') {
			res.push_back(cnt);
			cnt = 0;
		}
	}

	if (s[n] == 'B')
		res.push_back(cnt);

	printf("%d\n", (int)res.size());
	for (int i = 0; i < (int)res.size(); ++i) {
		printf("%d ", res[i]);
	}
	printf("\n");
	return 0;
}