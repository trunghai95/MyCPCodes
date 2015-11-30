#include <bits/stdc++.h>

using namespace std;

typedef map<char, int> mci;

int n;
string s;
vector<int> len;
vector<mci> v;

int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        map<char,int> mp;
        for (int j = 0; j < s.length(); ++j)
        {
            ++mp[s[j]];
        }

        if (mp.size() <= 2)
            v.push_back(mp), len.push_back(s.length());
    }

    int res = 0;
    for (char c1 = 'a'; c1 <= 'z'; ++c1)
    for (char c2 = c1 + 1; c2 <= 'z'; ++c2)
    {
        int tmp = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            if (!((v[i].size() == 2 && (v[i].find(c1) == v[i].end() || v[i].find(c2) == v[i].end()))
                  || (v[i].size() == 1 && (v[i].find(c1) == v[i].end() && v[i].find(c2) == v[i].end()))))
                tmp += len[i];
        }
        res = max(tmp, res);
    }
    cout << res;
    return 0;
}
