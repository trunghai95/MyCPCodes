#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 15;
int test, n, a[MAXN], b[MAXN];

struct State {
    int data[MAXN];
    ll val;

    State() { memset(data, 0, sizeof(data)); val = 0; }
    State(int *a) {
        for (int i = 0; i < n; ++i)
            data[i] = a[i];
        hash();
    }
    void hash() {
        val = 0;
        for (int i = 0; i < n; ++i)
            val = val*MAXN + data[i];
    }
};

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", a+i), --a[i], b[i] = i;
        State start(a);
        State goal(b);

        int res = 5;
        map<ll, int> dist[2];
        dist[0][start.val] = 0;
        queue<State> q;
        q.push(start);

        while (!q.empty()) {
            State u = q.front();
            q.pop();
            int d = dist[0][u.val];
            if (u.val == goal.val) {
                res = d;
                break;
            }
            if (d == 2) continue;

            for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j) {
                for (int k = -1; k < i-1; ++k) {
                    memcpy(b, u.data, (k+1) * sizeof(int));
                    memcpy(b+k+1, u.data+i, (j-i+1) * sizeof(int));
                    memcpy(b+k+j-i+2, u.data+k+1, (i-k) * sizeof(int));
                    memcpy(b+j+1, u.data+j+1, (n-j-1) * sizeof(int));
                    State v(b);
                    if (!dist[0].count(v.val)) {
                        dist[0][v.val] = d + 1;
                        q.push(v);
                    }
                }

                for (int k = j+1; k < n; ++k) {
                    memcpy(b, u.data, i * sizeof(int));
                    memcpy(b+i, u.data+j+1, (k-j) * sizeof(int));
                    memcpy(b+i+k-j, u.data+i, (j-i+1) * sizeof(int));
                    memcpy(b+k+1, u.data+k+1, (n-k-1) * sizeof(int));
                    State v(b);
                    if (!dist[0].count(v.val)) {
                        dist[0][v.val] = d + 1;
                        q.push(v);
                    }
                }
            }
        }

        if (res < 5) {
            printf("%d\n", res);
            continue;
        }

        dist[1][goal.val] = 0;
        while (!q.empty()) q.pop();
        q.push(goal);

        while (!q.empty()) {
            State u = q.front();
            q.pop();
            int d = dist[1][u.val];
            if (d == 2) continue;

            for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j) {
                for (int k = -1; k < i-1; ++k) {
                    memcpy(b, u.data, (k+1) * sizeof(int));
                    memcpy(b+k+1, u.data+i, (j-i+1) * sizeof(int));
                    memcpy(b+k+j-i+2, u.data+k+1, (i-k) * sizeof(int));
                    memcpy(b+j+1, u.data+j+1, (n-j-1) * sizeof(int));
                    State v(b);
                    if (!dist[1].count(v.val)) {
                        dist[1][v.val] = d + 1;
                        q.push(v);
                    }
                }

                for (int k = j+1; k < n; ++k) {
                    memcpy(b, u.data, i * sizeof(int));
                    memcpy(b+i, u.data+j+1, (k-j) * sizeof(int));
                    memcpy(b+i+k-j, u.data+i, (j-i+1) * sizeof(int));
                    memcpy(b+k+1, u.data+k+1, (n-k-1) * sizeof(int));
                    State v(b);
                    if (!dist[1].count(v.val)) {
                        dist[1][v.val] = d + 1;
                        q.push(v);
                    }
                }
            }
        }

        map<ll,int>::iterator it, it2;
        for (it = dist[0].begin(); it != dist[0].end(); ++it) {
            it2 = dist[1].find(it->first);
            if (it2 != dist[1].end())
                res = min(it->second + it2->second, res);
        }

        if (res < 5)
            printf("%d\n", res);
        else
            printf("5 or more\n");
    }
    return 0;
}
