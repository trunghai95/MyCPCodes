#include <bits/stdc++.h>

using namespace std;

#define B 0
#define R 1
#define Q 2
#define F first
#define S second

struct Piece {
    int x, y, type;
};

int n, xk, yk;
Piece p[500010];
char s[10];
map<int, vector<int> > hor, ver, diag1, diag2;

void sortMap(map<int, vector<int> > &mp) {
    for (map<int, vector<int> >::iterator it = mp.begin(); it != mp.end(); ++it)
        sort(it->S.begin(), it->S.end());
}

int main() {
    scanf("%d %d %d", &n, &xk, &yk);

    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d", s, &p[i].x, &p[i].y);
        if (s[0] == 'B') p[i].type = B;
        else if (s[0] == 'R') p[i].type = R;
        else p[i].type = Q;

        hor[p[i].x].push_back(p[i].y);
        ver[p[i].y].push_back(p[i].x);
        diag1[p[i].x + p[i].y].push_back(p[i].x);
        diag2[p[i].x - p[i].y].push_back(p[i].x);
    }

    sortMap(hor);
    sortMap(ver);
    sortMap(diag1);
    sortMap(diag2);

    for (int i = 0; i < n; ++i) {
        if (p[i].type == B || p[i].type == Q) {
            if (p[i].x + p[i].y == xk + yk) {
                vector<int> &v = diag1[xk+yk];
                int p1 = lower_bound(v.begin(), v.end(), p[i].x) - v.begin();
                int p2 = lower_bound(v.begin(), v.end(), xk) - v.begin();
                if (p1 == p2 || (p1 < p2 && p2 - p1 <= 1)) {
                    printf("YES\n");
                    return 0;
                }
            } else if (p[i].x - p[i].y == xk - yk) {
                vector<int> &v = diag2[xk-yk];
                int p1 = lower_bound(v.begin(), v.end(), p[i].x) - v.begin();
                int p2 = lower_bound(v.begin(), v.end(), xk) - v.begin();
                if (p1 == p2 || (p1 < p2 && p2 - p1 <= 1)) {
                    printf("YES\n");
                    return 0;
                }
            }
        } else if (p[i].type == R || p[i].type == Q) {
            if (p[i].x == xk) {
                vector<int> &v = hor[xk];
                int p1 = lower_bound(v.begin(), v.end(), p[i].y) - v.begin();
                int p2 = lower_bound(v.begin(), v.end(), yk) - v.begin();
                if (p1 == p2 || (p1 < p2 && p2 - p1 <= 1)) {
                    printf("YES\n");
                    return 0;
                }
            } else if (p[i].y == yk) {
                vector<int> &v = ver[yk];
                int p1 = lower_bound(v.begin(), v.end(), p[i].x) - v.begin();
                int p2 = lower_bound(v.begin(), v.end(), xk) - v.begin();
                if (p1 == p2 || (p1 < p2 && p2 - p1 <= 1)) {
                    printf("YES\n");
                    return 0;
                }
            }
        }
    }

    printf("NO\n");
    return 0;
}
