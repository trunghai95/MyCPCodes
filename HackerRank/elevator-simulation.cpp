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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = (int) 1e9 + 7;
const int oo = (int) 1e9;
const ll ooll = (ll)(1e18);
const ld EPS = 1e-9;
const int N = 100;

struct node {
    int id , t, des , pos;
    bool operator < (const node&other) const {
        if (id == other.id)
            return pos < other.pos;
        return id > other.id;
    }
    bool operator > (const node&other) const {
        if (id == other.id)
            return pos > other.pos;
        return id < other.id;
    }
};

bool func (node i, node j)  {
    return i.t < j.t;
}

int n, w, c, pos;
node a[N];


int main() {
    // freopen("test.in", "r", stdin);
    scanf("%d %d %d %d", &n, &w, &c, &pos);
    fi(i, 1, n) scanf("%d %d %d", &a[i].id, &a[i].t, &a[i].des);
    sort (a + 1, a + n + 1, func);

    priority_queue<node> in;
    priority_queue<node,vector <node>, greater<node> > out;


    int start = 0;
    int cnt = 0 ;
    int m = 0;


    fi(i, 1, n) {
        if (a[i].t > start + w && in.size() == c) {
                int vmax = 0;
            while (!in.empty()) {
                vmax = max(vmax, in.top().des);
                in.pop();
            }
            start += start + w + 2 * vmax;
        }
        a[i].pos = ++m;
        out.push(a[i]);
        node u = out.top();
        if (in.size() == c && u.id == 2) {
            node v = in.top();
            if (v.id == 1) {
                in.pop();
                out.pop();
                v.pos = ++m;
                out.push(v);
                in.push(u);
            }
        } else {
            out.pop();
            in.push(u);
        }
    }
    int vmax = 0;
    while (!in.empty()) {
        vmax = max(vmax, in.top().des);
        in.pop();
    }
    start += start + w  + vmax * 2;
    cout << start <<endl;
}



