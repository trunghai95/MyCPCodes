#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int n;
pii a[200];

int main()
{
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
        cin >> a[i].first >> a[i].second;

    sort(a+1, a+1+n);

    int lef = -1, rig = -1, res = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (a[i].first > rig)
        {
            ++res;
            lef = a[i].first;
            rig = a[i].second;
        }
        else
            lef = max(lef, a[i].first), rig = min(rig, a[i].second);
    }

    cout << res;

    return 0;
}
