#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define fi(a,b,c) for(int a=b; a<=c; a++)
#define fii(a,b,c) for(int a=b; a<c; a++)

const int MAX = 1e3 + 1;
typedef pair <int, int> pii;
int n, a[MAX][MAX];
int tcase;
int dh[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int d[MAX][MAX];
int x, y;
pii start, End;

void prepare(const int& n){
    int cnt = 0;
    for (int tt = 1; tt <= ((n + 1) >> 1); ++tt){
        for (int j = tt; j <= n - tt; ++j)
            a[tt][j] = ++cnt;
        for (int i = tt; i <= n - tt; ++i)
            a[i][n - tt + 1] = ++cnt;
        for (int j = n - tt + 1; j > tt; --j)
            a[n - tt + 1][j] = ++cnt;
        for (int i = n - tt + 1; i > tt; --i)
            a[i][tt] = ++cnt;
    }
    if (n & 1)
        a[(n + 1) >> 1][(n + 1) >> 1] = ++cnt;
}

int GCD(int a, int b) {
    int r ;
    while (b) {
        r = a % b ;
        a = b ;
        b = r;
    } return a;
}

int BFS() {
    queue <pair <int, int> > Q;
    Q.push(start);
    fi(i, 1, n) fi(j, 1, n) d[i][j] = 0;
    d[start.ft][start.sc] = 1;
    while (!Q.empty()) {

        pii u = Q.front() ; Q.pop() ;
        fii(k, 0, 4) {
            pii v;
            v.ft = u.ft + dh[k];
            v.sc = u.sc + dc[k];
            if (v.ft <= 0 || v.sc <= 0 || v.ft > n || v.sc > n) continue ;
            if (d[v.ft][v.sc]) continue;
            if (GCD(a[u.ft][u.sc], a[v.ft][v.sc]) != 1) continue ;
            d[v.ft][v.sc]= d[u.ft][u.sc] + 1;
            if (a[v.ft][v.sc] == y) return d[v.ft][v.sc] - 1;
            Q.push(v);
        }
    }
    return -1  ;
}

int main(){
    scanf("%d", &tcase) ;
    while (tcase --) {

        scanf("%d %d %d", &n, &x, &y);
        prepare(n);
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j)
                if (a[i][j] == x) {
                    start = mp(i, j);
                } else if (a[i][j] == y) {
                    End = mp(i, j);
                }
        }

        printf("%d\n", BFS());

    }


    return 0;
}
