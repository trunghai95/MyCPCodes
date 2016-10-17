#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k, x[100010], y[100010];
ll res[100010];
vector<int> v[4][100010][2];
bool ck[4][100010][2];

int main() {
	memset(res, -1, sizeof(res));

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= k; ++i) {
		scanf("%d %d", x+i, y+i);
		int xx = 0;
		int yy = y[i] - x[i];
		if (yy >= 0) {
			v[3][yy][1].push_back(i);
		}

		xx = x[i] - y[i];
		if (xx >= 0) {
			v[0][xx][0].push_back(i);
		}

		xx = x[i] + y[i];
		if (xx <= n) {
			v[0][xx][1].push_back(i);
		}

		yy = x[i] + y[i] - n;
		if (yy <= m && yy >= 0) {
			v[1][yy][0].push_back(i);
		}

		yy = x[i] + y[i];
		if (yy <= m) {
			v[3][yy][0].push_back(i);
		}

		xx = x[i] + y[i] - m;
		if (xx <= n && xx >= 0) {
			v[2][xx][1].push_back(i);
		}

		yy = y[i] - x[i] + n;
		if (yy <= m && yy >= 0) {
			v[1][yy][1].push_back(i);
		}

		xx = x[i] - y[i] + m;
		if (xx <= n && xx >= 0) {
			v[2][xx][0].push_back(i);
		}
	}

	ll step = 0;
	int side = 0;
	int pos = 0;
	int dir = 0;

	while (!ck[side][pos][dir]) {
		ck[side][pos][dir] = true;
		for (int i = 0; i < (int)v[side][pos][dir].size(); ++i) {
			int p = v[side][pos][dir][i];
			if (res[p] == -1) {
				if (side == 0 || side == 2) {
					res[p] = step + abs(x[p] - pos);
				} else {
					res[p] = step + abs(y[p] - pos);
				}
			}
		}

		if (side == 0) {
			if (dir == 0) {
				if (pos + m <= n) {
					step += m; pos = pos + m; side = 2; dir = 1;
				} else {
					step += n - pos; pos = n - pos; side = 1;
				}
			} else {
				if (pos - m >= 0) {
					step += m; pos = pos - m; side = 2; dir = 0;
				} else {
					step += pos; side = 3;
				}
			}
		} else if (side == 1) {
			if (dir == 0) {
				if (pos + n <= m) {
					step += n; pos = pos + n; side = 3; dir = 1;
				} else {
					step += m - pos; pos = n - (m - pos); side = 2;
				}
			} else {
				if (pos - n >= 0) {
					step += n; pos = pos - n; side = 3; dir = 0;
				} else {
					step += pos; side = 0; pos = n - pos;
				}
			}
		} else if (side == 2) {
			if (dir == 0) {
				if (pos - m >= 0) {
					step += m; pos = pos - m; side = 0; dir = 1;
				} else {
					step += pos; pos = m - pos; side = 3;
				}
			} else {
				if (pos + m <= n) {
					step += m; pos = pos + m; side = 0; dir = 0;
				} else {
					step += n - pos; pos = m - (n - pos); side = 1;
				}
			}
		} else {
			if (dir == 0) {
				if (pos - n >= 0) {
					step += n; pos = pos - n; side = 1; dir = 1;
				} else {
					step += pos; side = 0;
				}
			} else {
				if (pos + n <= m) {
					step += n; pos = pos + n; side = 1; dir = 0;
				} else {
					step += m - pos; pos = m - pos; side = 2;
				}
			}
		}

		if ((side == 0 || side == 2) && (pos == 0 || pos == n))
			break;

		if ((side == 1 || side == 3) && (pos == 0 || pos == m))
			break;
	}

	for (int i = 1; i <= k; ++i) {
		printf("%lld\n", res[i]);
	}
	return 0;
}