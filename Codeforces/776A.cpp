#include <bits/stdc++.h>

using namespace std;

int n;
string a, b, u, v;

int main() {
    cin >> a >> b;
    cin >> n;

    cout << a << ' ' << b << '\n';
    while (n --> 0) {
        cin >> u >> v;
        if (u == a) {
            a = v;
        } else {
            b = v;
        }

        cout << a << ' ' << b << '\n';
    }
    return 0;
}
