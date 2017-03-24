#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, c, d, x, y;

int main() {

    cin >> a >> b >> c >> d;

    for(x = 0; x < 1e8; x++)
    {
        ll t1 = b+a*x;
        if (t1 - d >= 0 && (t1-d)%c == 0)
            return cout << t1, 0;
    }
    cout << -1;
    return 0;
}
