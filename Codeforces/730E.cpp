#include <bits/stdc++.h>

using namespace std;

struct Team {
	int a, d, id;

	bool operator<(Team t) {
		if (t.a != this->a) {
			return (this->a < t.a);
		}

		return this->id > t.id;
	}
};

bool cmp(Team a, Team b) {
	if (a.d < 0 && b.d < 0) {
		return b < a;
	}

	if (a.d > 0 && b.d > 0) {
		return a < b;
	}

	return a.d < b.d;
}

int n;
Team t[111];

int rank(Team a) {
	int res = 1;
	for (int i = 1; i <= n; ++i) {
		res += (a < t[i]);
	}

	return res;
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &t[i].a, &t[i].d);
		t[i].id = i;
	}

	sort(t+1, t+1+n, cmp);

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		int tmp = rank(t[i]);
		t[i].a += t[i].d;
		res += abs(tmp - rank(t[i]));
	}

	printf("%d\n", res);
	return 0;
}