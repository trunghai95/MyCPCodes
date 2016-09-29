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

const int N = 1009;
const int oo = 1000;

int n;
int dp[N][N];
int tcase;
int a[N];

int Get(int l, int mid, int r) {
    int k1, k2;
    if (l == mid) k1 = 0;
    else k1 = dp[l][mid - 1];
    k2 = dp[mid][r];
    return k1 + k2;
}

int main() {
   // freopen("test.in", "r", stdin);
    scanf("%d", &tcase);
    while (tcase --) {

        scanf("%d", &n);
        fi(i, 1, n) scanf("%d", &a[i]);
        fi(i, 0, n) fi(j, 0, n) dp[i][j] = 0;
        for (int  k= 2; k <=  n; k+= 2) {
            for (int i = 1; i<= n - k + 1; i++)
            {
                int j = i + k - 1;
                if (i + 1 == j) dp[i][j] = (a[i] == a[j]);
                else {
                    dp[i][j] = dp[i + 1][j- 1] + (a[i] == a[j]);
                    int left  = 1;
                    int right = (j - i + 1) >> 1;
                    int ans = 0;
                    while (left <= right) {
                        int mid1 = (left + left + right) / 3;
                        int mid2 = (left + right + right ) / 3;
                        //cout <<mid1 <<' '<<mid2 <<endl;
                        int F1 = Get(i, i + mid1 * 2, j);
                        int F2 = Get(i, i + mid2 * 2, j);
                        //cout <<"xet "<<i <<' '<< i + mid1 * 2<<' '<<i + mid2* 2 <<' '<<j <<' '<<F1 <<' '<<F2<<endl;
                        if (F1 < F2) {
                            left = mid1 + 1;
                            ans = max(ans, F2);
                        } else {
                            right = mid2 - 1;
                            ans = max(ans, F1);
                        }
                    }
                    dp[i][j] = max(dp[i][j], ans);

                }
                //cout <<i <<' '<<j <<' '<< dp[i][j] <<endl;

            }
        }
        printf("%d\n", dp[1][n]);
    }
}