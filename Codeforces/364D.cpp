#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 1e6;
int n;
ll a[MAX];

int main()
{
    srand(time(NULL));
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ll res = 1;
    for (int ii = 1; ii <= 3; ++ii)
    {
        int pos = (rand() % n);
        for (ll i = 2; i*i <= a[pos]; ++i)
        {
            if ((a[pos] % i) == 0)
            {
                int cnt = 0, cnt2 = 0;
                for (int j = 0; j < n; ++j)
                    if (a[j] % i == 0)
                        ++cnt;
                for (int j = 0; j < n; ++j)
                    if (a[j] % (a[pos] / i) == 0)
                        ++cnt2;
                if (cnt >= (n+1)/2) res = max(res,i);
                if (cnt2 >= (n+1)/2) res = max(res,a[pos]/i);
            }
        }
    }

    cout << res;

    return 0;
}
