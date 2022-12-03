#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 3e5+3;
int q, x, w[MAXN], a[MAXN], m[MAXN];
int sw, sa, sm;

int merge(int* a, int* b, int sa, int sb, bool r) {
    int cur = -1;
    int i = 0;
    int j = 0;
    int cnt = 0;
    sm = 0;
    bool startWithB = (a[0] > b[0]);

    while (i < sa && j < sb) {
        // printf("%d %d\n", i, j);
        if (a[i] < b[j]) {
            m[sm] = a[i];
            sm++;
            i++;
            if (cur == 2) {
                cnt++;
            }
            cur = 1;
        } else if (a[i] > b[j]) {
            m[sm] = b[j];
            sm++;
            j++;
            if (cur == 1) {
                cnt++;
            }
            cur = 2;
        } else {
            if (cur != 2) {
                m[sm] = a[i];
                sm++;
                i++;
                cur = 1;
            } else {
                m[sm] = b[j];
                sm++;
                j++;
            }
        }
        // printf("%d %d %d %d\n", i, j, cnt, cur);
    }

    while (i < sa) {
        if (cur == 2) {
            cnt++;
            cur = 1;
        }
        m[sm] = a[i];
        sm++;
        i++;
    }
    while (j < sb) {
        if (cur == 1) {
            cnt++;
            cur = 2;
        }
        m[sm] = b[j];
        sm++;
        j++;
    }
    // printf("%d %d %d--\n", cnt, startWithB, r);
    int ret = (cnt+1)/2;
    if (cnt % 2 == 0 && ((startWithB && !r) || (!startWithB && r))) {
        ret++;
    }
    return ret;
}

int solve() {
    if (sw == 0) {
        memcpy(w, a, sa*sizeof(int));
        sw = sa;
        return 1;
    }
    if (sa == 0) {
        return 0;
    }
    int ret;
    if (w[0] == a[0]) {
        ret = min(merge(w, a, sw, sa, false), merge(a, w, sa, sw, true));
    } else {
        ret = merge(w, a, sw, sa, false);
    }
    memcpy(w, m, sm*sizeof(int));
    sw = sm;
    return ret;
}

int main() {
    scanf("%d", &q);
    while (q --> 0) {
        scanf("%d", &sa);
        for (int i = 0; i < sa; i++) {
            scanf("%d", &a[i]);
        }
        printf("%d\n", solve());
    }
    return 0;
}