#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 1;
int n, a[MAX], cnt[MAX], lb;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++cnt[a[i]];
    }
    lb = 1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > n || cnt[a[i]] > 1)
        {
            while (cnt[lb]) ++lb;
            --cnt[a[i]];
            ++cnt[lb];
            a[i] = lb;
        }
        cout << a[i] << " ";
    }
    return 0;
}
