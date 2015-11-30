#include <bits/stdc++.h>

using namespace std;

string s;
map<string,int> mp;

int calc(string s)
{
    if (mp[s] != 0)
        return mp[s];
    if (s.length() == 0)
        return (mp[s] = 0);
    if (s.length() == 1)
        return (mp[s] = 1);
    if (s.length() == 2)
        return (mp[s] = 1 + (s[1] != '0' && (s[0] == '1' || (s[0] == '2' && s[1] <= '6'))));
    if (s[1] != '0')
        mp[s] += calc(string(s.begin()+1,s.end()));
    if (s[2] != '0' && (s[0] == '1' || (s[0] == '2' && s[1] <= '6')))
        mp[s] += calc(string(s.begin()+2,s.end()));
    return mp[s];
}

int main()
{
    while (1)
    {
        cin >> s;
        if (s[0] == '0')
            return 0;
        cout << calc(s) << endl;
    }
    return 0;
}
