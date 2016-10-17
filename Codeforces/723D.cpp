#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define F first
#define S second

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, k;
char s[60][60];
vector<piii> lakes;

bool valid(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int bfs(int x, int y) {
	queue<pii> q;
	q.push(pii(x, y));
	s[x][y] = '#';
	int res = 0;

	while (!q.empty()) {
		pii u = q.front();
		q.pop();

		if (res != -1) {
			++res;
		}

		for (int i = 0; i < 4; ++i) {
			pii v(u.F + dx[i], u.S + dy[i]);
			if (valid(v.F, v.S)) {
				if (s[v.F][v.S] == '.') {
					s[v.F][v.S] = '#';
					q.push(v);
				}
			} else {
				res = -1;
			}
		}
	}

	return res;
}

void bfs2(int x, int y) {
	queue<pii> q;
	q.push(pii(x, y));
	s[x][y] = '*';

	while (!q.empty()) {
		pii u = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			pii v(u.F + dx[i], u.S + dy[i]);
			if (valid(v.F, v.S) && s[v.F][v.S] == '#') {
				s[v.F][v.S] = '*';
				q.push(v);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	if (s[i][j] == '.') {
		int tmp = bfs(i, j);
		if (tmp != -1) {
			lakes.push_back(piii(tmp, pii(i, j)));
		}
	}

	sort(lakes.begin(), lakes.end(), greater<piii>());

	while ((int)lakes.size() > k) {
		cnt += lakes.back().F;
		bfs2(lakes.back().S.F, lakes.back().S.S);
		lakes.pop_back();
	}

	printf("%d\n", cnt);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i][j] == '#')
				printf(".");
			else
				printf("*");
		}
		printf("\n");
	}

	return 0;
}