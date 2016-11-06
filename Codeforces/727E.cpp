#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define F first
#define S second
const pll MODD = pll(1e9 + 7, 1e9 + 9);
const ll BASE = 31;

int n, k, len, g;
char s[2000010];
pll hash[1000010], poww, h;
map<pll, int> mp;

int main() {
	scanf("%d %d %s", &n, &k, s);
	len = n*k;

	for (int i = 0; i < k; ++i) {
		hash[0].F = (hash[0].F * BASE + s[i] - 'a') % MODD.F;
		hash[0].S = (hash[0].S * BASE + s[i] - 'a') % MODD.S;
	}

	poww.F = poww.S = 1;
	for (int i = 1; i < k; ++i) {
		poww.F = (poww.F * BASE) % MODD.F;
		poww.S = (poww.S * BASE) % MODD.S;
	}

	for (int i = 1; i < len; ++i) {
		hash[i].F = (hash[i-1].F - (s[i-1] - 'a') * poww.F
			+ MODD.F*MODD.F) % MODD.F;
		hash[i].F = (hash[i].F * BASE + s[(i + k - 1) % len] - 'a') % MODD.F;

		hash[i].S = (hash[i-1].S - (s[i-1] - 'a') * poww.S
			+ MODD.S*MODD.S) % MODD.S;
		hash[i].S = (hash[i].S * BASE + s[(i + k - 1) % len] - 'a') % MODD.S;
	}

	scanf("%d", &g);

	for (int i = 1; i <= g; ++i) {
		scanf("%s", s);
		h.F = h.S = 0;
		for (int j = 0; j < k; ++j) {
			h.F = (h.F * BASE + s[j] - 'a') % MODD.F;
			h.S = (h.S * BASE + s[j] - 'a') % MODD.S;
		}
		mp[h] = i;
	}

	for (int start = 0; start < k; ++start) {
		set<pll> s;
		vector<int> res;

		for (int i = start; i < len; i += k) {
			if (s.find(hash[i]) != s.end() || mp.find(hash[i]) == mp.end()) {
				break;
			}
			s.insert(hash[i]);
			res.push_back(mp[hash[i]]);
		}

		if ((int)res.size() == n) {
			printf("YES\n");
			for (int i = 0; i < n; ++i) {
				printf("%d ", res[i]);
			}
			printf("\n");
			return 0;
		}
	}

	printf("NO\n");
	return 0;
}