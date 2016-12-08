#include <bits/stdc++.h>
using namespace std;

const int MAX = 3010;
int n, m, need[MAX], cur[MAX], sum, dif;
char s[MAX][MAX];

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i){
        scanf("%d", need + i);
        if (need[i] > 2 * (n - 1)){
            printf("no");
            return 0;
        }
        sum += need[i];
    }

    if (sum > n * (n - 1)){
        printf("no");
        return 0;
    }

    for (int i = 1; i <= n; ++i){
        s[i][i] = 'X';
        cur[i] = n - 1;
    }
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
    if (i != j)
        s[i][j] = 'D';

    for (int i = 1; i <= m; ++i){
        if (cur[i] > need[i]){
            printf("no");
            return 0;
        }
        dif = need[i] - cur[i];
        for (int j = n; j > i && dif > 0; --j, --dif){
            --cur[j];
            s[i][j] = 'W';
            s[j][i] = 'L';
        }
        if (dif > 0){
            printf("no");
            return 0;
        }
        cur[i] = need[i];
    }

    printf("yes\n");
    for (int i = 1; i <= n; ++i)
        printf("%s\n", s[i] + 1);

    return 0;
}
