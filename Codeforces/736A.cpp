#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
int res;

int main() {
    cin >> n;
    res = 1;
    ll tmp = 1;
    while (tmp*2 < n) {
        ++res;
        tmp *= 2;
    }

    cout << res << '\n';
    return 0;
}
