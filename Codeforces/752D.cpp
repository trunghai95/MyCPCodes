#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXL = 100000;
int n, k, res, best;
char s[MAXL + 5];
map<string, vector<int> > mp;

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0, v; i < n; ++i) {
        scanf("%s %d", s, &v);
        mp[string(s)].push_back(v);
    }

    for (auto &x : mp) {
        vector<int> &v = x.S;
        sort(v.begin(), v.end(), greater<int>());
        string t = x.F;
        reverse(t.begin(), t.end());

        if (t < x.F) {
            vector<int> &v2 = mp[t];
            int sz = min(v.size(), v2.size());
            for (int i = 0; i < sz && v[i] + v2[i] > 0; ++i)
                res += v[i] + v2[i];
        } else if (t == x.F) {
            for (int i = 0; i < (int)v.size() && v[i] > 0; i += 2) {
                if (i+1 < (int)v.size() && v[i] + v[i+1] > 0) {
                    res += v[i] + v[i+1];
                    best = max(best, -v[i+1]);
                } else {
                    best = max(best, v[i]);
                }
            }
        }
    }

    res += best;

    printf("%d\n", res);
    return 0;
}
