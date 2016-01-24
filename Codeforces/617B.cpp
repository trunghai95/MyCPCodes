#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, a;
vector<ll> seg;

int main()
{
    cin >> n;
    seg.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if (a)
            seg.push_back(0);
        else
            ++seg.back();
    }

    if (seg.size() == 1)
    {
        cout << 0;
        return 0;
    }

    ll res = 1;
    seg.erase(seg.begin());
    seg.pop_back();
    for (int i = 0; i < seg.size(); ++i)
        res *= (seg[i] + 1);

    cout << res;
    return 0;
}
