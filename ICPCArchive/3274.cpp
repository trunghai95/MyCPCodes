#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define x first
#define y second

struct Segment {
	pii a, b;
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, maxx, maxy, dist[1200][1200];
Segment seg[510];
pii home, uni;
vector<int> xs, ys;
bool ck[1200][1200], isStreet[1200][1200];

void compress() {
	sort(xs.begin(), xs.end());
	map<int,int> mp;
	mp[xs[0]] = 1;
	maxx = 2;
	for (int i = 1; i < (int)xs.size(); ++i)
	if (xs[i] != xs[i-1]) {
		mp[xs[i]] = maxx++;
	}
	home.x = mp[home.x] * 2;
	uni.x = mp[uni.x] * 2;
	for (int i = 1; i <= n; ++i) {
		seg[i].a.x = mp[seg[i].a.x] * 2;
		seg[i].b.x = mp[seg[i].b.x] * 2;
	}

	sort(ys.begin(), ys.end());
	mp.clear();
	mp[ys[0]] = 1;
	maxy = 2;
	for (int i = 1; i < (int)ys.size(); ++i)
	if (ys[i] != ys[i-1]) {
		mp[ys[i]] = maxy++;
	}
	home.y = mp[home.y] * 2;
	uni.y = mp[uni.y] * 2;
	for (int i = 1; i <= n; ++i) {
		seg[i].a.y = mp[seg[i].a.y] * 2;
		seg[i].b.y = mp[seg[i].b.y] * 2;
	}

	maxx *= 2;
	maxy *= 2;
}

void checkStreets() {
	for (int i = 1; i <= n; ++i) {
		if (seg[i].a.x == seg[i].b.x) {
			for (int j = seg[i].a.y; j <= seg[i].b.y; ++j) {
				isStreet[seg[i].a.x][j] = true;
			}
		} else {
			for (int j = seg[i].a.x; j <= seg[i].b.x; ++j) {
				isStreet[j][seg[i].a.y] = true;
			}
		}
	}
}

bool valid(int x, int y) {
	return (x >= 0 && y >= 0 && x <= maxx && y <= maxy);
}

int main() {
	int tt = 0;
	while (true) {
		scanf("%d", &n);

		if (!n) {
			return 0;
		}

		xs.clear(), ys.clear();
		memset(isStreet, 0, sizeof(isStreet));

		for (int i = 1; i <= n; ++i) {
			scanf("%d %d %d %d", 
				&seg[i].a.x, &seg[i].a.y, &seg[i].b.x, &seg[i].b.y);
			if (seg[i].a > seg[i].b) swap(seg[i].a, seg[i].b);
			xs.push_back(seg[i].a.x);
			xs.push_back(seg[i].b.x);
			ys.push_back(seg[i].a.y);
			ys.push_back(seg[i].b.y);
		}

		scanf("%d %d %d %d", &home.x, &home.y, &uni.x, &uni.y);
		xs.push_back(home.x);
		xs.push_back(uni.x);
		ys.push_back(home.y);
		ys.push_back(uni.y);

		compress();
		checkStreets();

		memset(dist, -1, sizeof(dist));
		memset(ck, 0, sizeof(ck));
		priority_queue<piii, vector<piii>, greater<piii> > heap;
		heap.push(piii(0, home));
		dist[home.x][home.y] = 0;

		while (!heap.empty()) {
			piii u = heap.top();
			heap.pop();

			if (ck[u.y.x][u.y.y]) continue;
			ck[u.y.x][u.y.y] = true;
			if (u.y == uni) break;

			for (int d = 0; d < 4; ++d) {
				pii v(u.y.x + dx[d], u.y.y + dy[d]);
				int tmp = 0;
				if (!valid(v.x, v.y)) continue;
				if (isStreet[v.x][v.y]) v.x += dx[d], v.y += dy[d], tmp = 1;
				if (ck[v.x][v.y]) continue;
				if (dist[v.x][v.y] == -1)
					dist[v.x][v.y] = dist[u.y.x][u.y.y] + tmp;
				else
					dist[v.x][v.y] = min(dist[v.x][v.y], dist[u.y.x][u.y.y] + tmp);
				heap.push(piii(dist[v.x][v.y], v));
			}
		}

		printf("City %d\nPeter has to cross %d streets\n", 
			++tt, dist[uni.x][uni.y]);
	}
	return 0;
}