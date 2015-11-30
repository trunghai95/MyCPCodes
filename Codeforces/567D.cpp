#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int n, k, a, m, sum, x;
vector<pii> seg;

int main()
{
    cin >> n >> k >> a >> m;
    seg.push_back(pii(1,n));
    sum = n/a;
    if (sum < k)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> x;
        for (int j = 0; j < seg.size(); ++j)
        {
            if (seg[j].first == x)
            {
                sum = sum - (seg[j].second - seg[j].first + 1)/a + (seg[j].second - seg[j].first)/a;
                ++seg[j].first;
                break;
            }
            if (seg[j].second == x)
            {
                sum = sum - (seg[j].second - seg[j].first + 1)/a + (seg[j].second - seg[j].first)/a;
                --seg[j].second;
                break;
            }
            if (seg[j].first < x && seg[j].second > x)
            {
                sum = sum - (seg[j].second - seg[j].first + 1)/a + (x - seg[j].first)/a + (seg[j].second - x)/a;
                if (x - seg[j].first >= a) seg.push_back(pii(seg[j].first,x-1));
                if (seg[j].second - x >= a) seg.push_back(pii(x+1,seg[j].second));
                seg.erase(seg.begin()+j);
                break;
            }
        }
        if (sum < k)
        {
            cout << i+1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
