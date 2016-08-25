#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, a[1000010], cnt, lef[1000010], rig[1000010], bit[1000010];
ll res;
map<int,int> id;

void update(int x) {
	while (x <= 1000000) {
		++bit[x];
		x += x&(-x);
	}
}

ll get(int x) {
	ll res = 0;
	while (x > 0) {
		res += (ll)bit[x];
		x -= x&(-x);
	}
	return res;
}

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d",  a+i);
		map<int,int>::iterator it = id.find(a[i]);
		if (it != id.end())
			a[i] = it->second;
		else {
			a[i] = id[a[i]] = ++cnt;
		}
	}

	for (int i = 1; i <= n; ++i) {
		lef[i] = ++bit[a[i]];
	}

	memset(bit, 0, sizeof(bit));

	for (int i = n; i >= 1; --i) {
		rig[i] = ++bit[a[i]];
	}

	memset(bit, 0, sizeof(bit));

	for (int i = n; i >= 1; --i) {
		res += get(lef[i] - 1);
		update(rig[i]);
	}

	printf("%lld\n", res);
	return 0;
}