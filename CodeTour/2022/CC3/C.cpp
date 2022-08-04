#include <bits/stdc++.h>

#define pii pair<int,int>

using namespace std;

const int MAXN = 200005;
const int MAXX = 1000003;

int test, n, a[MAXN];
pii pos[MAXN];

bool cmp(pii x, pii y) {
    return x.first > y.first;
}

int solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        pos[i] = pii(a[i], i);
    }
    sort(pos, pos+n, cmp);

    int res = 0;
    for (int i = 0; i < n-1; i++) {
        if (res > pos[i].first + pos[i+1].first) {
            break;
        }

        int left = pos[i].second-1;
        int right = pos[i].second+1;
        int minVal = a[pos[i].second];
        while (left >= 0 && right < n) {
            if (a[left] > pos[i].first && a[right] < pos[i].first) {
                break;
            }
            if (a[left] < a[right] || a[left] > pos[i].first) {
                minVal = min(minVal, a[right]);
                right++;
            } else {
                minVal = min(minVal, a[left]);
                left--;
            }
            if (a[pos[i].second] + minVal < res) {
                break;
            }
            res = a[pos[i].second] + minVal;
        }

        while (left >= 0) {
            if (a[left] > a[pos[i].second]) {
                break;
            }
            minVal = min(minVal, a[left]);
            left--;
            if (a[pos[i].second] + minVal < res) {
                break;
            }
            res = a[pos[i].second] + minVal;
        }
        while (right < n) {
            if (a[right] > a[pos[i].second]) {
                break;
            }
            minVal = min(minVal, a[right]);
            right++;
            if (a[pos[i].second] + minVal < res) {
                break;
            }
            res = a[pos[i].second] + minVal;
        }
    }

    return res;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        printf("%d\n", solve());
    }
    return 0;
}