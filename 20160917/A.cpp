#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int w, h, a[110][110];

int get(int x, int y) {
	int res = a[x][y];
	for (int i = 0; i < 4; ++i)
		res = max(res, a[x+dx[i]][y+dy[i]]);
	return res;
}

int main() {
	scanf("%d %d", &h, &w);

	for (int i = 1; i <= h; ++i)
	for (int j = 1; j <= w; ++j)
		scanf("%d", a[i]+j);

	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j)
			printf("%d ", get(i, j));
		printf("\n");
	}
	return 0;
}