#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int test, n, m, k, a[MAX][MAX], b[MAX][MAX], aa[MAX][MAX];
int arr[MAX][MAX], h[MAX], pre[MAX], suf, nn, mm, res;
stack <int> st;

void solve(){
    for (int ii = 1; ii <= n; ++ii)
    for (int jj = 1; jj <= m; ++jj){
        nn = n - ii + 1;
        mm = m - jj + 1;
        for (int i = 1; i <= nn; ++i)
        for (int j = 1; j <= mm; ++j)
            arr[i][j] = (abs(b[i][j] - a[ii + i - 1][jj + j - 1]) <= k);

        memset(h + 1, 0, mm * sizeof(int));
        for (int i = 1; i <= nn; ++i){
            while (!st.empty())
                st.pop();
            for (int j = 1; j <= mm; ++j){
                h[j] = (arr[i][j] == 0 ? 0 : h[j] + 1);
                while (!st.empty() && h[j] <= h[st.top()])
                    st.pop();
                pre[j] = (st.empty() ? 0 : st.top());
                st.push(j);
            }

            while (!st.empty())
                st.pop();
            for (int j = mm; j >= 1; --j){
                while (!st.empty() && h[j] <= h[st.top()])
                    st.pop();
                suf = (st.empty() ? mm : st.top() - 1);
                res = max(res, (suf - pre[j]) * h[j]);
                if (res > 9){
                    int tmp = 1;
                    ++tmp;
                }
                st.push(j);
            }
        }
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &test);
    while (test--){
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &b[i][j]);
        res = 0;
        solve();
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            swap(a[i][j], b[i][j]);
        solve();

        memcpy(aa, a, sizeof(a));
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            a[j][i] = aa[i][m - j + 1];
        }

        memcpy(aa, b, sizeof(b));
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            b[j][i] = aa[i][m - j + 1];
        }

        swap(n, m);
        solve();

        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            swap(a[i][j], b[i][j]);
        solve();

        printf("%d\n", res);
    }

    return 0;
}
