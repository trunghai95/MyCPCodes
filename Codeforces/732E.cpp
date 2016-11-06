#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

int n, m, a, resa[200010], resb[200010], c, u;
pii b[200010];
map<int, vector<int> > mp;

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		mp[a].push_back(i);
	}

	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i].F);
		b[i].S = i;
	}

	sort(b+1, b+1+m, greater<pii>());

	int cur = 0;

	while (true) {
		bool allDone = true;

		for (int i = 1; i <= m; ++i)
		if (b[i].F) {
			allDone = false;
			vector<int> &v = mp[b[i].F];

			if (!v.empty()) {
				resa[v.back()] = b[i].S;
				resb[b[i].S] = cur;
				v.pop_back();
				++c;
				u += cur;
				b[i].F = 0;
			} else {
				if (b[i].F == 1) b[i].F = 0;
				else b[i].F = (b[i].F + 1) / 2;
			}
		}

		if (allDone) break;
		++cur;
	}

	printf("%d %d\n", c, u);
	for (int i = 1; i <= m; ++i) {
		printf("%d ", resb[i]);
	}
	printf("\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d ", resa[i]);
	}
	printf("\n");
	return 0;
}