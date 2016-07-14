#include <bits/stdc++.h>

using namespace std;

const int N = 10009;

typedef long long ll;

int n, tcase;
ll a[3][N];
bool invalid ;
int x, y;


int main() {
    freopen("test.in", "r", stdin);
    int tcase = 0;
    while (scanf("%d %d %d", &n, &x, &y) && (n + x + y != 0)) {
            tcase ++;
        printf("Case %d:\n", tcase);
        ll vmin = 1000000009;
        for (int i = 1 ; i <= 2 ; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d ", &a[i][j]);
            vmin = min(vmin, a[i][j]);
        }
        vmin --;
        ll cnt = 0ll;
        vmin = max(vmin, 0ll);
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j<= n; j++)
            {
                cnt+= vmin;
                a[i][j] -= vmin;
            }

        while (1) {

            if (a[x][y] == 0) {
                a[x][y] = cnt;
                invalid = (x == 1);
                break;
            }
            cnt ++;
            a[x][y] --;
         //   cout <<x<<' '<<y<<' '<<a[x][y] <<endl;
            if (x == 2 && y == 1) x = 1; else
                if (x == 1 && y == n) x = 2;
                else if (x == 2) y--; else y++;
              //  cout <<x <<' '<<y<<endl;
        }
        if (invalid) cout <<"INVALID\n";
        else {
            for (int i = 1; i <= 2; i++) {
                for (int j = 1; j <= n; j++) printf("%d ", a[i][j]);
                printf("\n");
            }
        }
    }
}
