#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
const int MAXN = 1000;
int n, a[30];
char s[MAXN+2];
ll ways[MAXN+2], longest[MAXN+2], minCnt[MAXN+2];

int main() {
    scanf("%d %s", &n, s+1);

    for (int i = 0; i < 26; ++i) {
        scanf("%d", a+i);
    }

    ways[0] = 1;

    for (int i = 1; i <= n; ++i) {
        minCnt[i] = 2e18;
        // cout << i << ' ';
        int bound = 1e9;

        for (int j = i; j >= 1; --j) {
            // cout << j << ' ';
            bound = min(bound, a[s[j]-'a']);
            if (bound < (i - j + 1)) {
                break;
            }

            ways[i] = (ways[i] + ways[j-1]) % MODD;
            longest[i] = max(longest[i], max(longest[j-1], (ll)(i - j + 1)));
            minCnt[i] = min(minCnt[i], minCnt[j-1] + 1);
        }

        // cout << ways[i] << ' ' << longest[i] << ' ' << minCnt[i] << '\n';
    }

    printf("%lld\n%lld\n%lld\n", ways[n], longest[n], minCnt[n]);
    return 0;
}
