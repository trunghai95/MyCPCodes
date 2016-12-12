#include <bits/stdc++.h>

using namespace std;

typedef pair<string,int> psi;
#define F first
#define S second

int n, x;
map<string, int> mp;
char s[50];
vector<psi> v;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%s %d", s, &x);
        int &tmp = mp[s];
        tmp += x;
        v.push_back(psi(s, tmp));
    }

    string res;
    int mx = -1e9;
    for (auto &x: mp) {
        mx = max(mx, x.S);
    }

    for (int i = 0; i < (int)v.size(); ++i) {
        if (v[i].S >= mx && mp[v[i].F] == mx) {
            printf("%s\n", v[i].F.c_str());
            return 0;
        }
    }
    return 0;
}
