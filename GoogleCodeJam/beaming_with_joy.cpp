#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int test, n, m;
char s[MAXN+2][MAXN+2];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
        }

        for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        if (s[i][j] == '-' || s[i][j] == '|') {
            
        }
    }
    return 0;
}
