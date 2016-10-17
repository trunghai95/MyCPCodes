#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k, cnt0, cntneg;
ll x, a[200010];

struct cmp {
	bool operator()(int x, int y) {
		return abs(a[x]) > abs(a[y]);
	}
};

void printa() {
	for (int i = 1; i <= n; ++i) {
		printf("%lld ", a[i]);
	}
	printf("\n");
}

int main() {
	scanf("%lld %lld %lld", &n, &k, &x);

	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a+i);
		if (a[i] < 0) ++cntneg;
		else if (a[i] == 0) ++cnt0;
	}

	if (cnt0 > k) {
		printa();
		return 0;
	}

	k -= cnt0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) {
			if (cntneg&1) {
				a[i] += x;
			} else {
				++cntneg;
				a[i] -= x;
			}
		}
	}

	if (k == 0) {
		printa();
		return 0;
	}

	if (!(cntneg&1)) {
		int mni = 1;
		for (int i = 2; i <= n; ++i) {
			if (abs(a[i]) < abs(a[mni])) {
				mni = i;
			}
		}

		ll cc = min(abs(a[mni])/x + 1, k);
		k -= cc;
		if (a[mni] > 0) {
			a[mni] -= cc*x;
		} else {
			a[mni] += cc*x;
		}

		if (k == 0) {
			printa();
			return 0;
		}
	}

	priority_queue<int, vector<int>, cmp> heap;
	for (int i = 1; i <= n; ++i)
		heap.push(i);

	while (k --> 0) {
		int p = heap.top();
		heap.pop();
		if (a[p] > 0) {
			a[p] += x;
		} else {
			a[p] -= x;
		}

		heap.push(p);
	}

	printa();
	return 0;
}