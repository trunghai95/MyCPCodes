#include <bits/stdc++.h>

using namespace std;

typedef pair<string,string> pss;
pss email[20000];
int n;
map<string, vector<string> > mp;

char low(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;

    return c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> email[i].second;
        int atpos = email[i].second.find('@');
        string domain;
        for (int j = atpos; j < email[i].second.length(); ++j)
            domain.push_back(low(email[i].second[j]));

        if (domain != "@bmail.com")
        {
            for (int j = 0; j < atpos; ++j)
                email[i].first.push_back(low(email[i].second[j]));
        }
        else
        {
            for (int j = 0; j < atpos; ++j)
            {
                if (email[i].second[j] == '+') break;
                if (email[i].second[j] == '.') continue;

                email[i].first.push_back(low(email[i].second[j]));
            }
        }

        email[i].first += domain;
        mp[email[i].first].push_back(email[i].second);
    }

    cout << mp.size() << '\n';

    map<string, vector<string> >::iterator it = mp.begin();

    while (it != mp.end())
    {
        cout << it->second.size();
        for (int i = 0; i < it->second.size(); ++i)
            cout << ' ' << it->second[i];
        ++it;
        cout << '\n';
    }
    return 0;
}
