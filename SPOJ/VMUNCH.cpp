// 20...

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

int n, m, res;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char s[110][110], dist[110][110];

bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
	scanf("%d %d", &n, &m);

	queue<pii> q;
	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
		for (int j = 0; j < m; ++j)
		if (s[i][j] == 'C')
			dist[i][j] = 0, q.push(pii(i, j));
	}

	while (!q.empty()) {
		pii u = q.front();
		q.pop();

		if (s[u.F][u.S] == 'B') {
			printf("%d\n", dist[u.F][u.S]);
			return 0;
		}

		for (int i = 0; i < 4; ++i) {
			pii v(u.F + dx[i], u.S + dy[i]);

			if (valid(v.F, v.S) && dist[v.F][v.S] == -1) {
				q.push(v);
				dist[v.F][v.S] = dist[u.F][u.S] + 1;
			}
		}
	}

	printf("0\n");
	return 0;
}