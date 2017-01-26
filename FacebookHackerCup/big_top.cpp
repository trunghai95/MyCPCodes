#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second

const int MAXN = 800000;
int test, n;
ll a, b, c;
pll p[MAXN+2];

bool cmp(pll x, pll y) {
    return x.S > y.S;
}

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d", &n);

        scanf("%lld %lld %lld %lld", &p[1].F, &a, &b, &c);
        for (int i = 2; i <= n; ++i) {
            p[i].F = ((a*p[i-1].F + b) % c) + 1;
        }

        scanf("%lld %lld %lld %lld", &p[1].S, &a, &b, &c);
        for (int i = 2; i <= n; ++i) {
            p[i].S = ((a*p[i-1].S + b) % c) + 1;
        }

        for (int i = 1; i <= n; ++i) {
            p[i].F *= 2;
            p[i].S *= 2;
        }

        map<ll, ll> mp;
        map<ll,ll>::iterator it, it2;

        sort(p+1, p+1+n, cmp);

        mp[p[1].F] = p[1].S;
        mp[p[1].F - p[1].S] = mp[p[1].F + p[1].S] = 0;

        for (int i = 2; i <= n; ++i) {
            it = mp.lower_bound(p[i].F);

            if (it == mp.end()) {
                --it;
                it2 = it;
                --it2;
                ll k = max((p[i].S + it2->S - (p[i].F - it2->F)) / 2, 0LL);
                mp.erase(it);
                mp[p[i].F - (p[i].S - k)] = k;
                mp[p[i].F + p[i].S] = 0;
                if (!k) {
                    mp[it2->F + it2->S] = 0;
                }
            } else if (it->F == p[i].F) {
                if (p[i].S > it->S) {
                    it->S = p[i].S;
                    it2 = it;
                    
                    if (it != mp.begin()) {
                        --it2;
                        ll k = max((p[i].S + it2->S - (p[i].F - it2->F)) / 2, 0LL);
                        mp[p[i].F - (p[i].S - k)] = k;
                        if (!k) {
                            mp[it2->F + it2->S] = 0;
                        }
                    } else {
                        mp[p[i].F - p[i].S] = 0;
                    }

                    it2 = it; ++it2;
                    if (it2 != mp.end()) {
                        ll k = max((p[i].S + it2->S + (p[i].F - it2->F)) / 2, 0LL);
                        mp[p[i].F + (p[i].S - k)] = k;
                        if (!k) {
                            mp[it2->F - it2->S] = 0;
                        }
                    } else {
                        mp[p[i].F + p[i].S] = 0;
                    }
                }
            } else if (it == mp.begin()) {
                it2 = it;
                ++it2;
                ll k = max((p[i].S + it2->S + (p[i].F - it2->F)) / 2, 0LL);
                mp.erase(it);
                mp[p[i].F + (p[i].S - k)] = k;
                mp[p[i].F - p[i].S] = 0;
                if (!k) {
                    mp[it2->F - it2->S] = 0;
                }
            } else {
                it2 = it;
                --it2;
                if (it2->S < p[i].S) {
                    if (p[i].S <= it->S - (it->F - p[i].F)) {
                        continue;
                    }
                    mp.erase(it2);
                    --it2;
                    ll k = max((p[i].S + it->S + (p[i].F - it->F)) / 2, 0LL);
                    mp[p[i].F + (p[i].S - k)] = k;
                    if (!k) {
                        mp[it->F - it->S] = 0;
                    }

                    k = max((p[i].S + it2->S - (p[i].F - it2->F)) / 2, 0LL);
                    mp[p[i].F - (p[i].S - k)] = k;
                    if (!k) {
                        mp[it2->F + it2->S] = 0;
                    }
                } else {
                    if (p[i].S <= it2->S + (it2->F - p[i].F)) {
                        continue;
                    }
                    mp.erase(it);
                    ++it2;
                    ll k = max((p[i].S + it->S + (p[i].F - it->F)) / 2, 0LL);
                    mp[p[i].F + (p[i].S - k)] = k;
                    if (!k) {
                        mp[it->F - it->S] = 0;
                    }

                    k = max((p[i].S + it2->S - (p[i].F - it2->F)) / 2, 0LL);
                    mp[p[i].F - (p[i].S - k)] = k;
                    if (!k) {
                        mp[it2->F + it2->S] = 0;
                    }
                }
            }
        }

        double res = 0, sum = 0;
        it = mp.begin();
        it2 = it;
        ++it2;

        while (it2 != mp.end()) {
            sum += 1.0 * (it->S + it2->S) * (it2->F - it->F) / 2.0;
            res += sum;
            cout << res << ' ' << sum << '\n';
            ++it;
            ++it2;
        }

        printf("%.2lf\n", res/4.0);
    }
    return 0;
}
