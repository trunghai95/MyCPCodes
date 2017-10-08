#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll k;
int x, y, a[4][4], b[4][4];

bool win(int x, int y) {
    if (x == 3) return y == 2;
    if (x == 2) return y == 1;
    return y == 3;
}

int main() {
    scanf("%lld %d %d", &k, &x, &y);

    for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 3; ++j) {
        scanf("%d", a[i]+j);
    }

    for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 3; ++j) {
        scanf("%d", b[i]+j);
    }

    vector<pii> v;
    int s = -1;
    v.push_back(pii(x, y));

    while (true) {
        // cout << x << ' ' << y << '\n';
        int tmp = a[x][y];
        y = b[x][y];
        x = tmp;

        for (int i = 0; i < (int)v.size(); ++i) {
            if (v[i] == pii(x, y)) {
                s = i;
                break;
            }
        }
        if (s != -1) break;

        v.push_back(pii(x, y));
    }

    if (k <= (ll)v.size()) {
        int res1 = 0, res2 = 0;
        for (int i = 0; i < k; ++i) {
            if (win(v[i].first, v[i].second)) {
                ++res1;
            } else if (win(v[i].second, v[i].first)) {
                ++res2;
            }
        }

        printf("%d %d\n", res1, res2);
        return 0;
    }

    k -= v.size();
    ll kk = k / (v.size() - s);
    ll res1 = 0, res2 = 0;

    for (int i = 0; i < (int)v.size(); ++i) {
        if (win(v[i].first, v[i].second)) {
            ++res1;
        } else if (win(v[i].second, v[i].first)) {
            ++res2;
        }
    }

    for (int i = s; i < (int)v.size(); ++i) {
        if (win(v[i].first, v[i].second)) {
            res1 += kk;
        } else if (win(v[i].second, v[i].first)) {
            res2 += kk;
        }
    }

    kk = k % (v.size() - s);

    while (kk --> 0) {
        if (win(v[s].first, v[s].second)) {
            ++res1;
        } else if (win(v[s].second, v[s].first)) {
            ++res2;
        }
        ++s;
    }

    printf("%lld %lld\n", res1, res2);
    return 0;
}
