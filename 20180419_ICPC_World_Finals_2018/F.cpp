#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, w, res, resw;
char s[100];
vector<string> v;
vector<string> line;

int bfs(int x, int y) {
    queue<pii> q;
    q.push(pii(x,y));
    int z = 0;

    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        line[u.first][u.second] = '*';
        z = max(z, u.first);

        if (u.first >= line.size() - 1) {
            continue;
        }

        int len = line[u.first+1].length();
        if (u.second > 0 && u.second - 1 < len && line[u.first+1][u.second-1] == ' ') {
            q.push(pii(u.first+1, u.second - 1));
        }
        if (u.second < len && line[u.first+1][u.second] == ' ') {
            q.push(pii(u.first+1, u.second));
        }
        if (u.second + 1 < len && line[u.first+1][u.second+1] == ' ') {
            q.push(pii(u.first+1, u.second+1));
        }
    }
    return z - x + 1;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        v.push_back(string(s));
        w = max(w, int(strlen(s)));
    }

    while (true) {
        line.clear();
        int len = 0;
        int need = 1e7;

        for (int i = 0; i < n; ++i) {
            if (v[i].length() + 1 > len) {
                line.push_back(v[i]);
                if (i > 0) {
                    need = min(need, int(v[i].length() + 1 - len));
                }
                len = w - v[i].length();
            } else {
                line.back().push_back(' ');
                line.back() += v[i];
                len -= v[i].length() + 1;
            }
        }

        if (line.size() <= res) {
            break;
        }

        int lgst = 0;
        for (int i = 0; i < line.size(); ++i) {
            for (int j = 0; j < line[i].size(); ++j) {
                if (line[i][j] == ' ') {
                    lgst = max(lgst, bfs(i, j));
                }
            }
        }

        if (lgst > res) {
            resw = w;
            res = lgst;
        }

        w += need;
    }

    printf("%d %d\n", resw, res);
    return 0;
}
