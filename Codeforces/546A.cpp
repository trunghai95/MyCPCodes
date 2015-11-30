#include <bits/stdc++.h>

using namespace std;

int n, k, w;

int main()
{
    cin >> k >> n >> w;
    k = w*(w+1)/2*k;
    if (k <= n) cout << 0;
    else cout << k - n;
    return 0;
}
