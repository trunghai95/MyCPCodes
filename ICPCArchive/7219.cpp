#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

int test, n, a[111][3];

int main() {
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt) {
		scanf("%d", &n);

		priority_queue<int, vector<int>, greater<int> > heap[3];

		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 3; ++j) {
				scanf("%d", a[i] + j);
			}
			if (a[i][0]) {
				heap[0].push(i);
			} else if (a[i][1]) {
				heap[1].push(i);
			} else if (a[i][2]) {
				heap[2].push(i);
			}
		}

		pii cur[3];
		for (int i = 0; i < 3; ++i)
			cur[i].F = cur[i].S = -1;

		int time = 0;

		while (true) {
			bool done = true;
			for (int i = 0; i < 3; ++i) {
				if (cur[i].F == -1) {
					if (!heap[i].empty()) {
						int p = heap[i].top();
						heap[i].pop();
						cur[i].F = p;
						cur[i].S = time + a[p][i];
						done = false;
					}
				} else if (cur[i].S == time) {
					for (int j = i + 1; j < 3; ++j) {
						if (a[cur[i].F][j]) {
							heap[j].push(cur[i].F);
							break;
						}
					}
					if (!heap[i].empty()) {
						int p = heap[i].top();
						heap[i].pop();
						cur[i].F = p;
						cur[i].S = time + a[p][i];
						done = false;
					} else {
						cur[i].F = cur[i].S = -1;
					}
				} else {
					done = false;
				}
			}

			if (done) break;

			++time;
		}

		printf("Case #%d: %d\n", tt, time);
	}
	return 0;
}