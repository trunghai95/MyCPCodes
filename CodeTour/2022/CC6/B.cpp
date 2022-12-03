#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 1e5+5;
int n, t, k, res, cnt1, cnt2, v;
char s[MAXN];

int main() {
    scanf("%s %d %d", s, &t, &k);
    n = strlen(s);

    for (int i = 0; i < n; i++) {
        res++;
        if (s[i] == '*') {
            cnt1++;
            cnt2 = 0;
            if (cnt1 > k) {
                printf("FAIL\n");
                return 0;
            }
            v++;
            if (v == t && i != n-1) {
                res += t;
                v = 0;
            }
        } else {
            cnt2++;
            cnt1 = 0;
            if (cnt2 > k) {
                printf("FAIL\n");
                return 0;
            }
            if (v > 0) v--;
        }
        // printf("%d %d %d %d\n", res, v, cnt1, cnt2);
    }
    printf("%d\n", res);
    return 0;
}