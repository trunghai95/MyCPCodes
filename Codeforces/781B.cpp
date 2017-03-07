#include <bits/stdc++.h>

using namespace std;

typedef pair<string,string> pss;
typedef pair<int,int> pii;
#define F first
#define S second

const int MAXN = 1000;
int n;
vector<int> adj[MAXN+2][2];
pss a[MAXN+2];
char s[30], t[30];
string res[MAXN+2];
set<string> stt;

bool Try(int p, int type) {
    vector<int> vec;
    queue<pii> q;
    set<string> st[2];
    q.push(pii(p, type));
    vec.push_back(p);
    if (type) {
        st[1].insert(a[p].S);
        st[0].insert(a[p].F);
        res[p] = a[p].S;
    } else if (stt.count(a[p].F)) {
        return false;
    } else {
        st[1].insert(a[p].F);
        res[p] = a[p].F;
    }

    bool ok = true;
    while (!q.empty() && ok) {
        pii u = q.front(); q.pop();

        for (int i = 0; i < (int)adj[u.F][u.S].size(); ++i) {
            int v = adj[u.F][u.S][i];
            if (!res[v].empty()) {
                continue;
            }

            vec.push_back(v);
            int tt = 0;
            if (st[1].count(a[v].F) || st[0].count(a[v].F) || stt.count(a[v].F)) {
                if (st[1].count(a[v].S)) {
                    ok = false;
                    break;
                } else {
                    st[1].insert(a[v].S);
                    st[0].insert(a[v].F);
                    res[v] = a[v].S;
                    tt = 1;
                    q.push(pii(v, 1));
                }
            } else {
                st[1].insert(a[v].F);
                res[v] = a[v].F;
                tt = 0;
                q.push(pii(v, 0));
            }

            if (u.S == 0 && tt == 1 && a[u.F].F == a[v].F) {
                ok = false;
                break;
            }
        }
    }

    if (!ok) {
        for (int i = 0; i < (int)vec.size(); ++i) {
            res[vec[i]].clear();
        }
        return false;
    } else {
        for (auto &x : st[0]) {
            stt.insert(x);
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%s %s", s, t);
        
        a[i].F.push_back(s[0]);
        a[i].F.push_back(s[1]);
        a[i].F.push_back(s[2]);
        
        a[i].S.push_back(s[0]);
        a[i].S.push_back(s[1]);
        a[i].S.push_back(t[0]);

        for (int j = 1; j < n; ++j) {
            if (a[i].F == a[j].F || a[i].F == a[j].S) {
                adj[i][0].push_back(j);
            }
            if (a[i].S == a[j].F || a[i].S == a[j].S) {
                adj[i][1].push_back(j);
            }
            if (a[j].F == a[i].F || a[j].F == a[i].S) {
                adj[j][0].push_back(i);
            }
            if (a[j].S == a[i].F || a[j].S == a[i].S) {
                adj[j][1].push_back(i);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    if (res[i].empty()) {
        if (!Try(i, 0) && !Try(i, 1)) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    for (int i = 1; i <= n; ++i) {
        printf("%s\n", res[i].c_str());
    }
    return 0;
}
