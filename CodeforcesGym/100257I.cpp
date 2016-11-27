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

const int N = 201;
const int oo = 1000;

set <int> Set[N];
vector <int> Common[N][N];
int n;

int main() {
   // freopen("test.in", "r", stdin);
    scanf("%d", &n);
    fi(i, 1, (n * (n-1)) / 2)
    {
        int u, v, k;
        scanf("%d %d %d" , &u, &v, &k);
        if (u > v) swap(u, v);
        fi(i, 1, k) {
            int x;
            scanf("%d", &x);
            Set[u].insert(x);
            Set[v].insert(x);
            Common[u][v].pb(x);
        }
    }

    fi(i, 1, n) {
        fi(j, i+1, n) {
            vector <int> get;
            get.clear();
            for (set <int> ::iterator it1 = Set[i].begin() ; it1 != Set[i].end(); it1 ++)
                for (set<int> ::iterator it2 = Set[j].begin() ; it2 != Set[j].end(); it2++)
                    if (*it1 == *it2)
                        get.pb(*it1);
            if (get.size() != Common[i][j].size())
                return 0 * printf("No\n");
        }
    }

    printf("Yes\n");
    fi(i, 1, n) {
        printf("%d ", Set[i].size());
        for (set <int> ::iterator it1 = Set[i].begin() ; it1 != Set[i].end(); it1 ++) printf("%d ", *it1);
        printf("\n");
    }
}
