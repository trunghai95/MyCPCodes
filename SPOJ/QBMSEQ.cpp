#include <bits/stdc++.h>

using namespace std;

int n, a[10010], tmp;
bool isU[10010];

bool check(int x) {
	int lo = 0, hi = 14142;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		tmp = mid*(mid+1)/2;

		if (tmp < x)
			lo = mid + 1;
		else
			hi = mid;
	}

	if (lo*(lo+1)/2 == x)
		return true;
	return false;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i), isU[i] = check(a[i]);

	int lef = 0, rig = -1, res = 0;

	while (lef < n && !isU[lef]) ++lef;

	while (lef < n) {
		rig = lef;
		while (rig < n && isU[rig] && (rig == lef || a[rig] >= a[rig - 1]))
			++rig;
		res = max(res, rig - lef);

		lef = rig;
		while (lef < n && !isU[lef]) ++lef;
	}

	printf("%d\n", res);
	return 0;
}