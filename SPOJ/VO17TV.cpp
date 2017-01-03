#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second

const int MAXN = 50;
const int MAXL = 100000;
const ll BASE = 29;
const pll MODD = pll(1e9 + 7, 1e9 + 9);
int n, k;
char s[MAXL+2];
vector<pll> hash[MAXN+2];
pll poww[MAXL+2];

void init() {
    poww[0].F = poww[0].S = 1;
    for (int i = 1; i <= MAXL; ++i) {
        poww[i].F = poww[i-1].F * BASE % MODD.F;
        poww[i].S = poww[i-1].S * BASE % MODD.S;
    }
}

bool check(int m) {
    if (!m) return true;
    map<pll, int> rr;

    for (int i = 0; i < n; ++i) {
        set<pll> st;
        for (int j = 0; j <= (int)hash[i].size() - m; ++j) {
            int k = j + m - 1;
            pll h = hash[i][k];
            if (j > 0) {
                h.F = (h.F - hash[i][j-1].F * poww[k-j+1].F + MODD.F*MODD.F) % MODD.F;
                h.S = (h.S - hash[i][j-1].S * poww[k-j+1].S + MODD.S*MODD.S) % MODD.S;
            }
            st.insert(h);
        }
        for (set<pll>::iterator it = st.begin(); it != st.end(); ++it)
            ++rr[*it];
    }

    int mx = 0;
    for (map<pll,int>::iterator it = rr.begin(); it != rr.end(); ++it) {
        mx = max(mx, it->second);
    }
    return mx >= k;
}

int main() {
    init();
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        hash[i] = vector<pll>(strlen(s), pll(0,0));
        hash[i][0].F = hash[i][0].S = s[0] - 'A';
        for (int j = 1; j < (int)hash[i].size(); ++j) {
            hash[i][j].F = (hash[i][j-1].F * BASE + s[j] - 'A') % MODD.F;
            hash[i][j].S = (hash[i][j-1].S * BASE + s[j] - 'A') % MODD.S;
        }
    }

    int lo = 0, hi = MAXL;

    while (lo < hi) {
        int mid = (lo + hi) / 2 + 1;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", lo);
    return 0;
}
