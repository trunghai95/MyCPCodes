#include <bits/stdc++.h>

using namespace std;

int n, m, t, cntA[20], cntC[60], tmp, a, c;
set<int> age, candy;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
        {
            cin >> tmp;
            age.insert(tmp);
            ++cntA[tmp];
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> tmp;
            candy.insert(tmp);
            ++cntC[tmp];
        }
        if (m < n || candy.size() < age.size())
        {
            cout << "NO\n";
            continue;
        }
        while (!age.empty() && !candy.empty())
        {
            a = *age.begin();
            c = *candy.begin();
            candy.erase(candy.begin());
            if (cntC[c] >= cntA[a])
                age.erase(age.begin());
        }
        if (age.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
