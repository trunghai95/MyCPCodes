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

const int N = 100;
const int oo = 1000;

bool func(pii a, pii b) {

    if (a.ft == b.ft) {
    if (a.sc == 7) return 1;
    if (b.sc == 7) return 0;
    return a.sc < b.sc ;
    }
    return a.ft > b.ft;
}

pii a[100];
int tcase, n, x;
int dd[100];

int main() {
    //freopen("test.in", "r", stdin);

    scanf("%d", &tcase);
    while (tcase --) {
            reset(dd, 0);

        scanf("%d", &n);
        fi(i, 1, n) {
            fi(j, 1, 6) {
                scanf("%d", &x);
                dd[x] ++;
            }

        }
        fi(i, 1, 49) a[i] = mp(dd[i], i);
        sort (a + 1, a + 50, func);

        vector <int> res;
        res.clear();

        fi(i, 1, 6) res.pb(a[i].sc);
        sort(res.begin(), res.end());
        fi(i, 1, 6) printf("%d ", res[i-1]);
        printf("\n");
    }

}