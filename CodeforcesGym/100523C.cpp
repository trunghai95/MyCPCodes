#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n;

int main() {
    cin >> n;

    while (!(n&1)) {
        n >>= 1;
    }

    if (n == 1)
        cout << "TAK\n";
    else
        cout << "NIE\n";
    return 0;
}
