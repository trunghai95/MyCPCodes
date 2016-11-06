#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

int n, a, b, c, res1, res2, mx;
map<pii,pii> mp;

pii getPair(int a, int b) {
	return pii(min(a, b), max(a, b));
}

int main() {
	scanf("%d %d %d %d", &n, &a, &b, &c);

	mx = min(a, min(b, c));
	res1 = 1;
	res2 = -1;

	mp[getPair(a, b)] = pii(c, 1);
	mp[getPair(b, c)] = pii(a, 1);
	mp[getPair(a, c)] = pii(b, 1);

	for (int i = 2; i <= n; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		pii &ab = mp[getPair(a, b)];
		pii &bc = mp[getPair(c, b)];
		pii &ca = mp[getPair(a, c)];
		int tmp = min(a, min(b, c));
		if (tmp > mx) {
			mx = tmp;
			res1 = i;
			res2 = -1;
		}

		if (ab.F > 0) {
			tmp = min(min(a, b), ab.F + c);
			if (tmp > mx) {
				mx = tmp;
				res1 = ab.S;
				res2 = i;
			}
		}

		if (bc.F > 0) {
			tmp = min(min(c, b), bc.F + a);
			if (tmp > mx) {
				mx = tmp;
				res1 = bc.S;
				res2 = i;
			}
		}

		if (ca.F > 0) {
			tmp = min(min(a, c), ca.F + b);
			if (tmp > mx) {
				mx = tmp;
				res1 = ca.S;
				res2 = i;
			}
		}

		if (c > ab.F) { ab = pii(c, i); }
		if (b > ca.F) { ca = pii(b, i); }
		if (a > bc.F) { bc = pii(a, i); }
	}
	if (res2 == -1) {
		printf("1\n%d\n", res1);
	} else {
		printf("2\n%d %d\n", res1, res2);
	}
	return 0;
}