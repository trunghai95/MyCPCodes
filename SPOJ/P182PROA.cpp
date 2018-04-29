#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll c, v0, v1, a, l;

int main() {
    cin >> c >> v0 >> v1 >> a >> l;
    ll cur = 0, res = 0, s = v0;

    while (cur < c) {
        cur -= min(cur, l);
        cur += s;
        ++res;
        s += a;
        s = min(s, v1);
    }

    cout << res << '\n';
    return 0;
}