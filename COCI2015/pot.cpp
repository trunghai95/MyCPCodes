#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
int n;
ll res;

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        int mu = s[s.length() - 1] - '0';
        s.erase(s.end() - 1);
        ll coso = atoll(s.c_str());

        ll tmp = 1;
        for (int i = 1; i <= mu; ++i)
            tmp *= coso;

        res += tmp;
    }

    cout << res;
    return 0;
}
