#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cnt[8];

int main() {
    cin >> cnt[2] >> cnt[3] >> cnt[5] >> cnt[6];
    ll res32, res256;
    res256 = min(cnt[2], min(cnt[5], cnt[6]));
    cnt[2] -= res256;
    res32 = min(cnt[2], cnt[3]);
    cout << res256*256 + res32*32 << '\n';
    return 0;
}
