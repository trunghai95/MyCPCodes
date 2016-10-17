#include <bits/stdc++.h>

using namespace std;

int n, x[201], y[201], r[201];
int p[201], lef[201], rig[201], rk[201];

int find(int a) {
	return (a == p[a]) ? a : (p[a] = find(p[a]));
}

bool join(int a, int b) {
	a = find(a);
	b = find(b);

	if (rk[a] < rk[b])
		swap(a, b);

	p[b] = a;
	rk[a] += rk[b];
	lef[a] = min(lef[a], lef[b]);
	rig[a] = max(rig[a], rig[b]);

	if (lef[a] < 0 && rig[a] > 200) {
		return true;
	}
	return false;
}

int dist(int x, int y, int a, int b) {
	return (x-a)*(x-a) + (y-b)*(y-b);
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		rk[i] = 1;

		scanf("%d %d %d", x+i, y+i, r+i);
		lef[i] = x[i] - r[i];
		rig[i] = x[i] + r[i];
		if (lef[i] < 0 && rig[i] > 200) {
			printf("%d\n", i-1);
			return 0;
		}

		for (int j = 1; j < i; ++j) {
			if (dist(x[i], y[i], x[j], y[j]) < (r[i] + r[j])*(r[i] + r[j])) {
				if (join(i, j)) {
					printf("%d\n", i-1);
					return 0;
				}
			}
		}
	}

	printf("%d\n", n - 1);
	return 0;
}