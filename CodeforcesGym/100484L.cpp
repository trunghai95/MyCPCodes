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
typedef pair <ll, ll> pii;
typedef unsigned int ui;

const int N = 100009;
const int oo = 1000;

pii a[N];
int n;

bool func(pii a, pii b) {
    if (a.sc == b.sc) {
        return a.ft > b.ft;
    }
    return a.sc > b.sc;
}

int main() {
    //freopen("test.in", "r", stdin);
    scanf("%d", &n);
    fi(i, 1, n) scanf("%lld %lld", &a[i].ft, &a[i].sc);
    sort(a + 1, a+ n + 1, func);

    ll ans = 0;
    ll sum = 0;
    fd(i, n, 1) {
        ans = max(ans, (sum - a[i].sc));
        sum += a[i].ft;
       cout <<a[i].ft <<  ' '<<a[i].sc <<endl;
    }

    printf("%lld\n", ans);
}