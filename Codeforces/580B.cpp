#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pii;
const int MAX = 100001;
int n, d, p1, p2;
ll res, sum;
pii p[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> n >> d;
    for (int i = 0; i < n; ++i)
        cin >> p[i].first >> p[i].second;

    sort(p,p+n);

    p1 = p2 = 0;
    sum = res = p[0].second;

    while (1)
    {
        ++p2;
        if (p2 == n) break;
        sum += p[p2].second;
        if (p[p2].first - p[p1].first < d) { res = max(res,sum); }
        else
        {
            sum -= p[p1].second;
            ++p1;
            if (p1 == n) break;
            if (p[p2].first - p[p2-1].first >= d)
            {
                p1 = p2;
                sum = p[p1].second;
                res = max(res,sum);
            }
            else
            {
                while (p[p2].first - p[p1].first >= d) { sum -= p[p2].second; --p2; }
                res = max(res,sum);
            }
        }
    }

    cout << res;
    return 0;
}
