#include <bits/stdc++.h>

using namespace std;

typedef pair<int,char> pic;
#define F first
#define S second

int n, k, a[510], b, kk;
vector<pic> res;

bool proc(int u, int v) {
	if (u == v) return true;

	int mxi = u;
	for (int i = u + 1; i <= v; ++i) {
		if (a[i] > a[mxi]) {
			mxi = i;
		} else if (a[i] == a[mxi]) {
			if (a[i] > a[i-1] || (i < v && a[i] > a[i+1])) {
				mxi = i;
			}
		}
	}

	if (mxi == u && a[mxi] <= a[mxi+1]) {
		return false;
	}

	if (mxi > u && a[mxi] > a[mxi - 1]) {
		for (int i = mxi; i > u; --i) {
			res.push_back(pic(i - u + 1 + kk, 'L'));
		}
		for (int i = mxi + 1; i <= v; ++i) {
			res.push_back(pic(1 + kk, 'R'));
		}
	} else {
		for (int i = mxi + 1; i <= v; ++i) {
			res.push_back(pic(mxi - u + 1 + kk, 'R'));
		}
		for (int i = mxi; i > u; --i) {
			res.push_back(pic(i - u + 1 + kk, 'L'));
		}
	}

	return true;
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}

	scanf("%d", &k);
	int last = 0;
	for (kk = 0; kk < k; ++kk) {
		scanf("%d", &b);
		int j = last, sum = 0;
		while (j <= n && sum < b) {
			if (++j > n) break;
			sum += a[j];
		}
		if (j > n || sum > b || !proc(last+1, j)) {
			printf("NO\n");
			return 0;
		}

		last = j;
	}

	if (last != n) {
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	for (int i = 0; i < (int)res.size(); ++i) {
		printf("%d %c\n", res[i].F, res[i].S);
	}
	return 0;
}