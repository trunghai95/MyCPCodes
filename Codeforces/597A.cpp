#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a, b, k;

int main()
{
    cin >> k >> a >> b;
    ll na, nb;
    na = a % k;
    if (na < 0) na += k;
    a = a - na + k*(na != 0);
    nb = b % k;
    if (nb < 0) nb += k;
    b = b - nb;

    if (a > b) cout << 0;
    else cout << (b - a) / k + 1;
    return 0;
}
