#include <bits/stdc++.h>

using namespace std;

int n;
string tmp;
map<string,int> mp;
vector<string> nt;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        if (mp[tmp] == 0)
            nt.push_back(tmp);
        ++mp[tmp];
        getline(cin, tmp);
    }
    sort(nt.begin(), nt.end());
    for (int i = 0; i < nt.size(); ++i)
    {
        cout << nt[i] << " " << mp[nt[i]] << endl;
    }
    return 0;
}
