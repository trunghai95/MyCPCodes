#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, u, v, x, y;

int main() {
    cin >> a >> b >> u >> v >> x >> y;
    
    ll res = min(x - a, u - x) * (min(y - b, v - y) * 2 + 1);
    res += min(y - b, v - y);

    cout << res << '\n';
    return 0;
}
