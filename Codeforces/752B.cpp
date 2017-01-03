#include <bits/stdc++.h>

using namespace std;

typedef pair<char,char> pcc;

const int MAXN = 1000;
int n;
char s[MAXN+5], t[MAXN+5], mp[300];
vector<pcc> res;

int main() {
    scanf("%s %s", s, t);
    n = strlen(s);

    for (int i = 0; i < n; ++i) {
        if (mp[s[i]]) {
            if (mp[s[i]] != t[i]) {
                printf("-1\n");
                return 0;
            }
        } else if (mp[t[i]]) {
            if (mp[t[i]] != s[i]) {
                printf("-1\n");
                return 0;
            }
        } else {
            mp[s[i]] = t[i];
            mp[t[i]] = s[i];
        }
    }

    for (int c = 'a'; c <= 'z'; ++c)
    if (mp[c]) {
        if (mp[mp[c]] != 0 && mp[mp[c]] != c) {
            printf("-1\n");
            return 0;
        }
        if (c != mp[c])
            res.push_back(pcc(c, mp[c]));
        mp[mp[c]] = 0;
    }

    printf("%d\n", res.size());
    for (int i = 0; i < (int)res.size(); ++i)
        printf("%c %c\n", res[i].first, res[i].second);
    return 0;
}
