#include <bits/stdc++.h>

using namespace std;

int test, n, p, cnt[30];
char s[30];

int main() {
    int *a = new int[10];
    memset(a, 0, 10 * 4);
    cout << a[5];
    realloc(a, 5 * 4);
    cout << a[5];
    return 0;
    //freopen("in.txt", "r", stdin);
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d", &n, &p);
        gets(s);
        memset(cnt, 0, sizeof(cnt));

        for (int i = 1; i <= n; ++i) {
            gets(s);
            ++cnt[strlen(s)];
        }

        for (int i = 0; i <= p; ++i) {
            if (p >= 10) {
                printf("%2d", i);
            } else {
                printf("%d", i);
            }

            if (cnt[i]) {
                printf(" ");
                for (int j = 0; j < cnt[i]; ++j)
                    printf("*");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
