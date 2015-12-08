#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char s[200];
int test;
bool ck[10];

bool Try(int d)
{
    ll a = 0, sa = 1, b = 0, sb = 1, c = 0, sc = 1;
    char op;

    int i = 0;
    if (s[0] == '-')
        sa = -1, ++i;
    if (s[i] == '?' && d == 0 && s[i+1] != '-' && s[i+1] != '+' && s[i+1] != '*') return false;
    if (s[i] == '?' && d == 0 && sa == -1) return false;

    while (s[i] != '-' && s[i] != '+' && s[i] != '*')
    {
        a = a*10 + (s[i] == '?' ? d : (s[i] - '0'));
        ++i;
    }

    op = s[i++];

    if (s[i] == '-')
        sb = -1, ++i;
    if (s[i] == '?' && d == 0 && s[i+1] != '=') return false;
    if (s[i] == '?' && d == 0 && sb == -1) return false;

    while (s[i] != '=')
    {
        b = b*10 + (s[i] == '?' ? d : (s[i] - '0'));
        ++i;
    }

    ++i;
    if (s[i] == '-')
        sc = -1, ++i;
    if (s[i] == '?' && d == 0 && s[i+1] != 0) return false;
    if (s[i] == '?' && d == 0 && sc == -1) return false;

    while (s[i] != 0)
    {
        c = c*10 + (s[i] == '?' ? d : (s[i] - '0'));
        ++i;
    }

    if (op == '-')
        return ((a*sa) - (b*sb) == (c*sc));

    if (op == '+')
        return ((a*sa) + (b*sb) == (c*sc));

    if (op == '*')
        return ((a*sa) * (b*sb) == (c*sc));
}

int main()
{
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> test;

    while (test--)
    {
        cin >> s;
        memset(ck, 0, sizeof(ck));
        for (int i = 0; s[i] != 0; ++i)
            if (s[i] >= '0' && s[i] <= '9') ck[s[i] - '0'] = true;
        bool f = false;
        for (int i = 0; !f && i < 10; ++i)
            if (!ck[i] && Try(i)) cout << i << '\n', f = true;

        if (!f) cout << -1 << '\n';
    }
    return 0;
}
