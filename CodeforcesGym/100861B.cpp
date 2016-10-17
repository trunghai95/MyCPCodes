#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

int A, B, C, n, m, z, res[100000];
pii f[100000], a[100000];
map<int, int> cnt;

int main() {
	scanf("%d %d %d %d %d %d", &f[1].F, &A, &B, &C, &n, &m);
	f[1].S = 1;
	n *= m;

	while (n --> 0) {
		scanf("%d", &m);
		++cnt[m];
	}

	n = cnt.size();
	for (int i = 2; i <= n; ++i) {
		f[i].F = (f[i-1].F*A + B) % C + 1;
		f[i].S = i;
	}

	map<int,int>::iterator it = cnt.begin();
	for (int i = 1; i <= n; ++i) {
		a[i].F = it->S;
		a[i].S = it->F;
		++it;
	}

	sort(f+1, f+1+n);
	sort(a+1, a+1+n);

	for (int i = 1; i <= n; ++i) {
		res[f[i].S] = a[i].S;
	}

	printf("%d\n", n);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", res[i]);
	}
	printf("\n");

	return 0;
}