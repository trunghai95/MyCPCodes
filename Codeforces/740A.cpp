#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, a, b, c, res = 2e18;

int main() {
    cin >> n >> a >> b >> c;
    if (n % 4 == 0) {
        cout << "0\n";
        return 0;
    }

    n = (n/4 + 1) * 4 - n;
    if (n == 1) {
        res = min(res, a);
        res = min(res, b+c);
        res = min(res, c*3);
    } else if (n == 2) {
        res = min(res, a+a);
        res = min(res, b);
        res = min(res, c+c);
    } else {
        res = min(res, a*3);
        res = min(res, c);
        res = min(res, a+b);
    }

    cout << res << '\n';
    return 0;
}
