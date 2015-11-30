#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
const int MODD = 14062008;
int n, k;
bool brk[MAXN+1];
int f[MAXN+1];

int main()
{
    ios_base::sync_with_stdio(0);
    memset(brk, 0, sizeof(brk));
    cin >> n >> k;
    for (int i = 0, x; i < k; ++i)
    {
        cin >> x;
        brk[x] = true;
    }

    f[1] = 1;
    f[2] = brk[2] ? 0 : 1;
    for (int i = 3; i <= n; ++i)
        f[i] = brk[i] ? 0 : ((f[i-1] + f[i-2]) % MODD);

    cout << f[n];
    return 0;
}
