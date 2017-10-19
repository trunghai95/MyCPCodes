#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cnt(ll x) {
    int res = 0;
    while (x) {
        if (x % 10 == 6 || x % 10 == 8) {
            ++res;
        }
        x /= 10;
    }
    return res;
}

int main() {
    for (int i = 8; i <= 10000; i += 8) {
        printf("%d %d\n", i, cnt(i));
    }
    return 0;
}
