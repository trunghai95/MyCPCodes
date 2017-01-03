#include <bits/stdc++.h>

using namespace std;

char t[1000001];
stringstream ss;
vector<string> res[260000];
int cnt[260000];
int mx;
string s;

int main() {
    scanf("%s", t);
    for (int i = 0; t[i]; ++i)
    if (t[i] == ',')
        t[i] = ' ';
    ss = stringstream(t);

    int level = 0;
    while (ss.good()) {
        level = 0;
        mx = max(level, mx);
        ss >> s >> cnt[level];
        res[level].push_back(s);
        while (level >= 0) {
            if (cnt[level])
                --cnt[level], ++level;
            else {
                --level;
                continue;
            }
            mx = max(level, mx);
            ss >> s >> cnt[level];
            res[level].push_back(s);
            if (cnt[level] == 0) --level;
        }
    }

    printf("%d\n", mx+1);
    for (int i = 0; i <= mx; ++i) {
        for (int j = 0; j < (int)res[i].size(); ++j)
            printf("%s ", res[i][j].c_str());
        printf("\n");
    }
    
    return 0;
}
