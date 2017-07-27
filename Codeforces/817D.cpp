#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 2;
int n;
ll a[MAXN+2], lmax[MAXN+2], rmax[MAXN+2], lmin[MAXN+2], rmin[MAXN+2];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a+i);
    }

    stack<ll> st1, st2;

    for (int i = 1; i <= n; ++i) {
        while (!st1.empty() && a[st1.top()] > a[i]) {
            rmin[st1.top()] = i - st1.top();
            st1.pop();
        }

        while (!st2.empty() && a[st2.top()] < a[i]) {
            rmax[st2.top()] = i - st2.top();
            st2.pop();
        }

        st1.push(i);
        st2.push(i);
    }

    while (!st1.empty()) rmin[st1.top()] = n + 1 - st1.top(), st1.pop();
    while (!st2.empty()) rmax[st2.top()] = n + 1 - st2.top(), st2.pop();

    for (int i = n; i >= 1; --i) {
        while (!st1.empty() && a[st1.top()] >= a[i]) {
            lmin[st1.top()] = st1.top() - i;
            st1.pop();
        }

        while (!st2.empty() && a[st2.top()] <= a[i]) {
            lmax[st2.top()] = st2.top() - i;
            st2.pop();
        }

        st1.push(i);
        st2.push(i);
    }

    while (!st1.empty()) lmin[st1.top()] = st1.top(), st1.pop();
    while (!st2.empty()) lmax[st2.top()] = st2.top(), st2.pop();    

    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        res += a[i] * (lmax[i] * rmax[i] - lmin[i] * rmin[i]);
    }

    printf("%lld\n", res);
    return 0;
}
