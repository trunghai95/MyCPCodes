#include <bits/stdc++.h>

using namespace std;

typedef pair<double,double> pdd;
#define F first
#define S second

const double EPS = 1e-10;
int test;
pdd a[4];

bool colin(pdd a, pdd b, pdd c) {
    if (a.S == b.S && a.S == c.S) {
        return true;
    }
    if (a.S == b.S || a.S == c.S) {
        return false;
    }

    return (abs((a.F - b.F) / (a.S - b.S) - (a.F - c.F) / (a.S - c.S)) < EPS);
}

bool parallel(pdd a, pdd b, pdd c, pdd d) {
    if (a.S == b.S && c.S == d.S) {
        return true;
    }
    if (a.S == b.S || c.S == d.S) {
        return false;
    }

    return (abs((a.F - b.F) / (a.S - b.S) - (c.F - d.F) / (c.S - d.S)) < EPS);
}

void f(pdd a, pdd b, double& aa, double& bb, double& cc) {
    pdd vec1(b.F - a.F, b.S - a.S);
    pdd vec2(-vec1.S, vec1.F);
    aa = vec2.F, bb = vec2.S, cc = -a.F * vec2.F - a.S * vec2.S;
}

pdd intersect(pdd a, pdd b, pdd c, pdd d) {
    double aa[2], bb[2], cc[2];
    f(a, b, aa[0], bb[0], cc[0]);
    f(c, d, aa[1], bb[1], cc[1]);

    double det = aa[0] * bb[1] - aa[1] * bb[0];
    return pdd(-(bb[1]*cc[0] - bb[0]*cc[1])/det, -(aa[0]*cc[1] - aa[1]*cc[0])/det);
}

bool inmid(pdd a, pdd b, pdd p) {
    if (a.F == p.F || p.F == b.F) {
        return (a.S - p.S)*(p.S - b.S) > 0;
    } else {
        return (a.F - p.F)*(p.F - b.F) > 0;
    }
}

bool cut(pdd a, pdd b, pdd c, pdd d) {
    if (parallel(a, b, c, d)) {
        return false;
    }

    pdd p = intersect(a, b, c, d);
    return inmid(a, b, p) && inmid(c, d, p);
}

bool concave(pdd a, pdd b, pdd c, pdd d) {
    if (parallel(a, b, c, d)) {
        return false;
    }

    pdd p = intersect(a, b, c, d);
    return inmid(a, b, p) || inmid(c, d, p);
}

inline void printRes(pdd a, pdd b, pdd c) {
    printf("YES %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n", 
        a.F, a.S, b.F, b.S, c.F, c.S);
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        for (int i = 0; i < 4; ++i) {
            scanf("%lf %lf", &a[i].F, &a[i].S);
        }

        if (colin(a[0], a[1], a[2])) {
            printRes(min(a[0], min(a[1], a[2])), max(a[0], max(a[1], a[2])), a[3]);
            continue;
        }
        if (colin(a[3], a[1], a[2])) {
            printRes(min(a[3], min(a[1], a[2])), max(a[3], max(a[1], a[2])), a[0]);
            continue;
        }
        if (colin(a[0], a[3], a[2])) {
            printRes(min(a[0], min(a[3], a[2])), max(a[0], max(a[3], a[2])), a[1]);
            continue;
        }
        if (colin(a[0], a[1], a[3])) {
            printRes(min(a[0], min(a[1], a[3])), max(a[0], max(a[1], a[3])), a[2]);
            continue;
        }

        if (cut(a[0], a[1], a[2], a[3])) {
            swap(a[1], a[2]);
        }
        if (cut(a[0], a[3], a[1], a[2])) {
            swap(a[2], a[3]);
        }

        if (concave(a[0], a[1], a[2], a[3])) {
            printf("NO\n");
            continue;
        }

        pdd m, n, p;

        if (parallel(a[0], a[1], a[2], a[3])) {
            if (parallel(a[0], a[3], a[1], a[2])) {
                m = pdd(a[0].F*2 - a[1].F, a[0].S*2 - a[1].S);
                n = pdd(a[1].F*2 - a[0].F, a[1].S*2 - a[0].S);
                p = intersect(m, a[3], n, a[2]);
            } else {
                p = intersect(a[0], a[3], a[1], a[2]);
                if (inmid(a[3], p, a[0])) {
                    m = a[3], n = a[2];
                } else {
                    m = a[0], n = a[1];
                }
            }
        } else {
            p = intersect(a[0], a[1], a[2], a[3]);
            if (inmid(a[0], p, a[1])) {
                m = a[0], n = a[3];
            } else {
                m = a[1], n = a[2];
            }
        }

        printRes(m, n, p);
    }
    return 0;
}
