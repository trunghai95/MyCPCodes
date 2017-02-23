#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pil;
#define F first
#define S second

map<pil, ll> sg;

ll calc(pil u) {
    map<pil,ll>::iterator it = sg.find(u);

    if (it != sg.end()) {
        return it->S;
    }

    if (u.F == 0) {
        return (sg[u] = 0);
    }

    vector<ll> v;
    for (int i = 1; i <= u.F; ++i) {
        if (!((u.S >> i) & 1)) {
            v.push_back(calc(pil(u.F - i, u.S | (1LL << i))));
        }
    }

    sort(v.begin(), v.end());

    if (v.empty() || v[0] > 0) {
        return (sg[u] = 0);
    }

    for (int i = 1; i < (int)v.size(); ++i) {
        if (v[i] > v[i-1] + 1) {
            return (sg[u] = v[i-1] + 1);
        }
    }

    return (sg[u] = v.back() + 1);
}

int g[70], n, a, res;

int main() {
    for (int i = 1; i <= 60; ++i) {
        g[i] = calc(pil(i, 0));
    }

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        res = res ^ g[a];
    }

    if (res) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }

    return 0;
}
