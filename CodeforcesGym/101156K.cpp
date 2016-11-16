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
int d[10][7] =
{
    {1, 1, 1, 1, 1, 1, 0}
    ,{0, 1, 1, 0, 0, 0, 0}
    ,{1, 1, 0, 1, 1, 0, 1}
    ,{1, 1, 1, 1, 0, 0, 1}
    ,{0, 1, 1, 0, 0, 1, 1}
    ,{1, 0, 1, 1, 0, 1, 1}
    ,{1, 0, 1, 1, 1, 1, 1}
    ,{1, 1, 1, 0, 0, 0, 0}
    ,{1, 1, 1, 1, 1, 1, 1}
    ,{1, 1, 1, 1, 0, 1, 1}
};

int n;
int err[8], v[1009][8], sure[8];
char s[20];
set<string> st;


void init() {

}

int solve(int start) {
    fii(i, 0, 7) sure[i] = err[i] = 0;

    fi(i, 1, n) {
        fii(j, 0, 7) if (!d[start][j] && v[i][j]) return -1;
        fii(j, 0, 7) if (err[j] && v[i][j]) return -1;
        fii(j, 0, 7) if (sure[j] && !v[i][j] && d[start][j]) return -1;
        fii(j, 0, 7) if (d[start][j] && !v[i][j]) err[j] = 1;// cout << "check "<< j <<endl;
        fii(j, 0, 7) if (d[start][j] && v[i][j]) sure[j] = 1;
        start--;
        if (start == -1) start = 9;
    }
    fii(i, 0, 7) if (d[start][i] && !err[i] && !sure[i]) {
        st.insert("dummy1");
        st.insert("dummy2");
        return -1;
    }
    string res;
    fii(i, 0, 7)
        res.push_back((d[start][i] && !err[i]) ? '1' : '0');
    st.insert(res);
    return start ;
}

int main() {
   // freopen("test.in", "r", stdin);
    init();
    int tcase;

    scanf("%d", &tcase);
    while (tcase --) {
        scanf("%d ", &n);
        fi(i, 1, n) fi(j, 0, 7) v[i][j] = 0;
        fi(i, 1, n) {
            scanf("%s", s);
            fii(j, 0, 7) {
                v[i][j] = (s[j] == '1');
            }
        }
        st.clear();

        fd(start, 9, 0) {
            solve(start);
        }

        if (st.empty() || st.size() > 1) printf("ERROR!\n");
        else printf("%s\n", st.begin()->c_str());
    }
}
