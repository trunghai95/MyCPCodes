#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 200010;
char txt[MAX]; //input
int iSA[MAX], SA[MAX]; //output
int cnt[MAX], ne[MAX]; //internal
bool bh[MAX], b2h[MAX];

bool smaller_first_char(int a, int b) {
    return txt[a] < txt[b];
}

void suffixSort(int n) {
for (int i = 0; i < n; ++i)
    SA[i] = i;

sort(SA, SA + n, smaller_first_char);

for (int i = 0; i < n; ++i) {
    bh[i] = i == 0 || txt[SA[i]] != txt[SA[i - 1]];
    b2h[i] = false;
}

for (int h = 1; h < n; h <<= 1) {
    int buckets = 0;
    for (int i = 0, j; i < n; i = j) {
        j = i + 1;
        while (j < n && !bh[j]) j++;
        ne[i] = j;
        buckets++;
    }
    if (buckets == n) break;

    for (int i = 0; i < n; i = ne[i]) {
        cnt[i] = 0;
        for (int j = i; j < ne[i]; ++j)
            iSA[SA[j]] = i;
    }

    cnt[iSA[n - h]]++;
    b2h[iSA[n - h]] = true;
    for (int i = 0; i < n; i = ne[i]) {
        for (int j = i; j < ne[i]; ++j) {
            int s = SA[j] - h;
            if (s >= 0) {
                int head = iSA[s];
                iSA[s] = head + cnt[head]++;
                b2h[iSA[s]] = true;
            }
        }
        for (int j = i; j < ne[i]; ++j) {
            int s = SA[j] - h;
            if (s >= 0 && b2h[iSA[s]])
            for (int k = iSA[s] + 1; !bh[k] && b2h[k]; k++)
                b2h[k] = false;
        }
    }
    for (int i = 0; i < n; ++i) {
        SA[iSA[i]] = i;
        bh[i] |= b2h[i];
    }
}

for (int i = 0; i < n; ++i)
    iSA[SA[i]] = i;
}

int lcp[MAX];
// lcp[i] = length of the longest common prefix of suffix SA[i] and suffix SA[i-1]
// lcp[0] = 0
void getlcp(int n)
{
    for (int i = 0; i < n; ++i)
        iSA[SA[i]] = i;

    lcp[0] = 0;

    for (int i = 0, h = 0; i < n; ++i)
    if (iSA[i] > 0){
        int j = SA[iSA[i] - 1];
        while (i + h < n && j + h < n && txt[i + h] == txt[j + h])
            h++;
        lcp[iSA[i]] = h;

        if (h > 0)
            h--;
    }
}

int n, m, q, nn;
char s[MAX];
int l[MAX], r[MAX];
int sum[MAX];

struct Query {
    char *p;
    int *index, l, r;
};

void solve() {
    int cnt = 0;
    Query* query = new Query[q + 3];

    for (int i = 0; i < q; ++i) {
        query[i].p = new char[nn + 3];
        query[i].index = new int[nn + 3];

        scanf("%s %d %d", query[i].p, &query[i].l, &query[i].r);

        for (int j = 0; j < nn; ++j) {
            query[i].index[j] = cnt;
            txt[cnt++] = query[i].p[j];
        }
    }

    int pos = cnt;
    txt[pos] = 0;
    strcat(txt, s);
    cnt += n;

    suffixSort(cnt);

    for (int i = 0; i < cnt; ++i) {
        sum[i] = sum[i-1];
        if (SA[i] >= pos) {
            ++sum[i];
        }
    }

    getlcp(cnt);

    for (int i = 0; i < q; ++i) {
        int ans = 0;

        for (int j = query[i].l; j <= query[i].r; ++j) {
            int index = iSA[query[i].index[l[j]]];
            int up = index;

            while (lcp[up] >= r[j] - l[j] + 1) {
                --up;
            }

            ans += sum[index] - sum[up - 1];
            int down = index;

            while (lcp[down + 1] >= r[j] - l[j] + 1) {
                ++down;
            }
            
            ans += sum[down] - sum[index - 1];
        }

        printf("%d\n", ans);
    }
}

int main() {
    scanf("%d %d %d %d %s", &n, &m, &q, &nn, s);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &l[i], &r[i]);
    }

    solve();
}
