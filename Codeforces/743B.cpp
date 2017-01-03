#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, k;

ll solve(ll n, ll k) {
    ll cnt = (1LL << n) - 1;
    ll mid = (cnt+1)/2;
    if (k == mid) {
        return n;
    }

    if (k > mid) k -= mid;
    return solve(n-1, k);
}

int main() {
    cin >> n >> k;
    cout << solve(n, k) << '\n';
    return 0;
}
