#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e6+5;
int n, a[MAXN], cnt[MAXN], mex;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] <= n) {
            cnt[a[i]]++;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (cnt[i] == 0) {
            mex = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] >= mex || cnt[a[i]] > 1) {
            a[i] = mex;
        }
    }

    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        if (a[i] <= n) {
            cnt[a[i]]++;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (cnt[i] == 0) {
            mex = i;
            break;
        }
    }
    printf("%d\n", mex);
    return 0;
}