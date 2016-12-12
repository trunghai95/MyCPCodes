#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

int n, a, b;
map<int, vector<int> > m;
set<int> s;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &a, &b);
        m[a].push_back(b);
        m[b].push_back(a);
    }

    for (auto x: m) {
        if (x.S.size() == 1) {
            a = x.F;
            break;
        }
    }

    while (true) {
        printf("%d ", a);
        s.insert(a);
        vector<int> &v = m[a];
        if (s.find(v[0]) == s.end()) {
            a = v[0];
        } else if (v.size() > 1 && s.find(v[1]) == s.end()) {
            a = v[1];
        } else {
            printf("\n");
            break;
        }
    }
    return 0;
}
