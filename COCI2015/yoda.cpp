#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string a, b, resa, resb;

int main()
{
    cin >> a >> b;

    while (a.length() < b.length())
        a = string("0") + a;
    while (b.length() < a.length())
        b = string("0") + b;

    for (int i = 0; i < a.length(); ++i)
    {
        if (a[i] > b[i])
            resa.push_back(a[i]);
        else if (a[i] < b[i])
            resb.push_back(b[i]);
        else
            resa.push_back(a[i]), resb.push_back(b[i]);
    }

    if (resa.empty()) cout << "YODA\n";
    else
    {
        while (resa.length() > 1 && resa[0] == '0') resa.erase(0, 1);
        cout << resa << '\n';
    }

    if (resb.empty()) cout << "YODA\n";
    else
    {
        while (resb.length() > 1 && resb[0] == '0') resb.erase(0, 1);
        cout << resb << '\n';
    }
    return 0;
}
