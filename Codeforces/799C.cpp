#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int n, c, d, x, y;
char s[5];
deque<int> cc[MAXN+2], dd[MAXN+2];

void ins(deque<int> &dq, int x) {
    if (dq.empty()) {
        dq.push_back(x);
    } else if (dq.size() == 1) {
        if (dq.front() < x) {
            dq.push_front(x);
        } else {
            dq.push_back(x);
        }
    } else {
        if (dq.front() < x) {
            dq.pop_back();
            dq.push_front(x);
        } else if (dq.back() < x) {
            dq.pop_back();
            dq.push_back(x);
        }
    }
}

int getBest(deque<int> &d1, deque<int> &d2) {
    if (d1.empty() || d2.empty()) {
        return 0;
    }

    if (d1.front() != d2.front()) {
        return d1.front() + d2.front();
    }

    int res = 0;
    if (d1.size() > 1) {
        res = max(d1.back() + d2.front(), res);
    }
    if (d2.size() > 1) {
        res = max(d1.front() + d2.back(), res);
    }
    return res;
}

int main() {
    scanf("%d %d %d", &n, &c, &d);

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %s", &x, &y, s);
        if (s[0] == 'C') {
            ins(cc[y], x);
        } else {
            ins(dd[y], x);
        }
    }

    for (int i = 2; i <= MAXN; ++i) {
        if (cc[i-1].size() > 0) {
            ins(cc[i], cc[i-1].front());
        }
        if (cc[i-1].size() > 1) {
            ins(cc[i], cc[i-1].back());
        }
        if (dd[i-1].size() > 0) {
            ins(dd[i], dd[i-1].front());
        }
        if (dd[i-1].size() > 1) {
            ins(dd[i], dd[i-1].back());
        }
    }

    int res = 0;
    if (!cc[c].empty() && !dd[d].empty()) {
        res = cc[c].front() + dd[d].front();
    }

    for (int i = 1; i <= c - i; ++i) {
        int j = c - i;
        res = max(res, getBest(cc[i], cc[j]));
    }

    for (int i = 1; i <= d - i; ++i) {
        int j = d - i;
        res = max(res, getBest(dd[i], dd[j]));
    }

    printf("%d\n", res);
    return 0;
}
