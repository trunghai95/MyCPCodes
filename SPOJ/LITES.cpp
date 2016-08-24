#include <bits/stdc++.h>

using namespace std;

int n, m, lef, rig, type, it[400010];
bool lazy[400010];

void update(int node, int lef, int rig, int l, int r) {

	int lc = node<<1;
	int rc = (node<<1) + 1;
	int mid = (lef + rig) / 2;

	if (lazy[node]) {
		it[node] = (rig - lef + 1) - it[node];
		lazy[node] = false;
		lazy[lc] = !lazy[lc];
		lazy[rc] = !lazy[rc];
	}

	if (lef > r || rig < l || lef > rig)
		return;

	if (lef >= l && rig <= r) {
		it[node] = (rig - lef + 1) - it[node];
		lazy[lc] = !lazy[lc];
		lazy[rc] = !lazy[rc];
		return;
	}

	update(lc, lef, mid, l, r);
	update(rc, mid+1, rig, l, r);

	it[node] = it[lc] + it[rc];
}

int get(int node, int lef, int rig, int l, int r) {
	int lc = node<<1;
	int rc = (node<<1) + 1;
	int mid = (lef + rig) / 2;

	if (lazy[node]) {
		it[node] = (rig - lef + 1) - it[node];
		lazy[node] = false;
		lazy[lc] = !lazy[lc];
		lazy[rc] = !lazy[rc];
	}

	if (lef > r || rig < l || lef > rig)
		return 0;

	if (lef >= l && rig <= r) {
		return it[node];
	}

	return get(lc, lef, mid, l, r) + get(rc, mid+1, rig, l, r);
}

int main() {
	scanf("%d %d", &n, &m);

	while (m --> 0) {
		scanf(" %d %d %d", &type, &lef, &rig);
		if (type) {
			printf("%d\n", get(1, 1, n, lef, rig));
		} else {
			update(1, 1, n, lef, rig);
		}
	}
	return 0;
}