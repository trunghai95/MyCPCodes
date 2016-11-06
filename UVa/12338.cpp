#include <bits/stdc++.h>

#define fi(a,b,c) for(int a=b; a<=c; a++)
#define fd(a,b,c) for(int a=b; a>=c; a--)
#define fii(a,b,c) for(int a=b; a<c; a++)
#define pb push_back
#define mp make_pair
#define ft first
#define sc second
#define reset(a,b) memset(a,b, sizeof a)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef unsigned int ui;

const int N = 1000009;
const int oo = 1000;

char c[N], S[N];
int len ;
int n, m, tcase ;
vector <int> ed[N];
int pos[N];
int T[N][31];
int d[N], pa[N];
bool mark[N];


void addstring(int index) {
    int u = 0;
    fi(i, 1, len) {
        bool co = 0;
        fii(j, 0, ed[u].size())
            if (c[ed[u][j]] == S[i]) {
                co = 1;
                u = ed[u][j];
            }
        if (!co) {
            c[++m] = S[i];
            ed[u].pb(m);
            u = m;
        }
    }
    pos[index] = u;
}

void DFS(int u ) {
    mark [u] = 1;
    fii(i, 0, ed[u].size()) {
        int v = ed[u][i];
        if (mark[v] ) continue ;
        d[v]  = d[u] + 1;
        pa[v] = u;
        DFS(v);
    }
}

void pre_LCA() {
    fi(i, 0, m) T[i][0] = pa[i];
    fi(j, 1, 20)
        fi(i, 0, m)
            T[i][j] = T[T[i][j-1]][j-1];
}

int getbit(unsigned int x, int k) {
    return (x >> k) & 1;
}

int LCA(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    if (d[u] > d[v] ) {

        int x = (d[u] - d[v]);
        fi(i, 0, 20)
            if(getbit(x, i))
                u = T[u][i];
    }
    if ( u== v) return u ;
    fd(i, 20 , 0 )
        if (T[u][i] != T[v][i]) {
            u = T[u][i];
            v = T[v][i];
        }
    return T[u][0];


}

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);

    scanf("%d", &tcase);
    fi(t, 1,  tcase ) {
        printf("Case %d:\n", t);
        scanf("%d", &n);
        m = 0;

        fi(i, 1, n) {
            scanf("%s", S+1);
            len = strlen(S+1);
            addstring(i);
        }

        d[0] = 0;
        pa[0] = 0;

        DFS(0);
        pre_LCA();

        int query ;

        scanf("%d", &query);
        while (query --) {
            int u , v;
            scanf("%d %d", &u, &v);
            int k = LCA(pos[u] , pos[v]);
            printf("%d\n", d[k]);
        }

        fi(i, 0, m) ed[i].clear();
        fi(i, 0, m) mark[i] = 0;

    }






}