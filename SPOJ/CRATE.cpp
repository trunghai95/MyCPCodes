#include <bits/stdc++.h>

using namespace std;

struct Person {
	int a, b, id;
	bool operator<(const Person& p) const {
		if (a == p.a)
			return b < p.b;
		return a < p.a;
	}
};

const int MAX = 100001;
int n, bit[MAX + 10], res[300010], cnt;
Person p[300010];

void update(int x) {
	while (x <= MAX) {
		++bit[x];
		x += x&(-x);
	}
}

int get(int x) {
	int res = 0;

	while (x > 0) {
		res += bit[x];
		x -= x&(-x);
	}

	return res;
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		p[i].id = i;
		scanf("%d %d", &p[i].a, &p[i].b);
		++p[i].a, ++p[i].b;
	}

	sort(p+1, p+n+1);
	for (int i = 1; i <= n; ++i) {
		res[p[i].id] = get(p[i].b);

		if (p[i].a == p[i-1].a && p[i].b == p[i-1].b) {
			res[p[i].id] -= ++cnt;
		} else {
			cnt = 0;
		}

		update(p[i].b);
	}

	for (int i = 1; i <= n; ++i)
		printf("%d\n", res[i]);
	return 0;
}