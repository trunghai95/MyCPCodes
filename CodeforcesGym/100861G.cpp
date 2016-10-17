#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, x[1010], y[1010];
set<pii> s;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", x+i, y+i);
	}

	if (n <= 3) {
		printf("0\n");
		return 0;
	}

	for (int i = 1; i <= n; ++i)
	for (int j = i+1; j <= n; ++j) {
		int xx = x[i] + x[j];
		int yy = y[i] + y[j];
		if (s.find(pii(xx, yy)) != s.end()) {
			printf("1\n");
			return 0;
		}
		s.insert(pii(xx, yy));
	}

	printf("2\n");
	return 0;
}