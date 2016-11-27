#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4000;
const int MAXK = 100;

int n, a[MAXN+1];
unordered_map<int, int> dp[MAXK+1];
// unordered_map<int, int>::iterator it;

inline int getId(int lef, int rig) {
    return lef*4001 + rig;
}
int solve2(const int& lef, const int& rig, const int& k);
int solve(const int& lef = 0, const int& rig = 0, const int& k = 1) {
    int ll = lef + k;
    int newlen = ll + rig;
    if (newlen > n) {
        return a[lef] - a[n] + a[n - rig];
    }

    // it = dp[lef][k].find(rig);
    auto p = dp[k].insert({getId(lef, rig), 0});
    if (!p.second) { return p.first->second; }

    if (newlen == n) {
        return (p.first->second = solve2(ll, rig, k));
    }
    return (p.first->second 
        = max(solve2(ll, rig, k), solve2(ll + 1, rig, k + 1)));
}

int solve2(const int& lef, const int& rig, const int& k) {
    int rr = rig + k;
    int newlen = lef + rr;
    if (newlen > n) {
        return a[lef] - a[n] + a[n - rig];
    }

    auto p = dp[k].insert({getId(lef, rig), 0});
    if (!p.second) { return p.first->second; }

    if (newlen == n) {
        return (p.first->second = solve(lef, rr, k));
    }
    return (p.first->second 
            = min(solve(lef, rr, k), solve(lef, rr + 1, k + 1)));
}

int main() {
    // clock_t t = clock();
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i), a[i] = a[i] + a[i-1];

    printf("%d\n", solve());
    // t = clock() - t;
    // cout << 1.0*t/CLOCKS_PER_SEC << '\n';
    fflush(stdout);
    _Exit(0);
    return 0;
}
