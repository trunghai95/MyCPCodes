#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

const int MAXN = 1000;
int n, m;
char a[MAXN+2][MAXN+2];
pii s, t;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
bool ck[MAXN+2][MAXN+2][4][3];

bool valid(int x, int y) {
    return x > 0 && y > 0 && x <= n && y <= m && a[x][y] != '*';
}

void dfs(int x, int y, int dir, int cnt) {
    if (cnt > 2 || !valid(x, y) || ck[x][y][dir][cnt]) {
        return;
    }

    ck[x][y][dir][cnt] = true;

    if (x == t.F && y == t.S) {
        printf("YES\n");
        exit(0);
    }

    int d = (dir + 3) % 4;
    dfs(x + dx[d], y + dy[d], d, cnt+1);
    d = (d + 1) % 4;
    dfs(x + dx[d], y + dy[d], d, cnt);
    d = (d + 1) % 4;
    dfs(x + dx[d], y + dy[d], d, cnt+1);
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%s", a[i] + 1);
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'S') {
                s = pii(i, j);
            } else if (a[i][j] == 'T') {
                t = pii(i, j);
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        dfs(s.F, s.S, i, 0);
    }

    printf("NO\n");
    return 0;
}
