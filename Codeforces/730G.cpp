#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define F first
#define S second

int n;
ll s, d;
vector<pll> v;

int main() {
	scanf("%d", &n);
	v.push_back(pll(1, 1e18));

	while (n --> 0) {
		scanf("%lld %lld", &s, &d);
		bool done = false;
		for (int i = 0; i < (int)v.size(); ++i) {
			if (v[i].F <= s && v[i].S >= s + d - 1) {
				if (v[i].F < s) {
					v.push_back(pll(v[i].F, s-1));
				}
				if (v[i].S > s + d - 1) {
					v.push_back(pll(s+d, v[i].S));
				}
				v.erase(v.begin() + i);
				done = true;
				printf("%lld %lld\n", s, s+d-1);
				sort(v.begin(), v.end());
				break;
			}
		}

		if (done) continue;
		for (int i = 0; i < (int)v.size(); ++i) {
			if (v[i].S - v[i].F + 1 >= d) {
				printf("%lld %lld\n", v[i].F, v[i].F + d - 1);
				if (v[i].S - v[i].F + 1 > d) {
					v.push_back(pll(v[i].F + d, v[i].S));
				}
				v.erase(v.begin() + i);
				done = true;
				sort(v.begin(), v.end());
				break;
			}
		}
	}
	return 0;
}