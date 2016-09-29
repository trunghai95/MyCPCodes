#include <bits/stdc++.h>
using namespace std;

typedef pair <double, double> pdd;
#define F first
#define S second
const int MAX = 2010;
const double EP = 0.0000001;

int n, res, cnt;
double d, val;
pdd cor[MAX], tam;

double dis(pdd x, pdd y){
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}

pdd timtam(pdd A, pdd B){
    double dist = dis(A, B);
    pdd mid((A.F + B.F) / 2, (A.S + B.S) / 2);
    dist = sqrt(d*d - dist*dist/4);

    pdd res(A.F - B.F, A.S - B.S);
    res = pdd(res.S, -res.F);
    double tmp = sqrt(res.F*res.F + res.S*res.S);
    res = pdd(mid.F + dist / tmp * res.F, mid.S + dist / tmp * res.S);
    return res;
}

int main(){
    //freopen("in.txt", "r", stdin);
    while (1){
        scanf("%d %lf", &n, &d);
        if (n == 0)
            break;
        for (int i = 0; i < n; ++i)
            scanf("%lf %lf", &cor[i].first, &cor[i].second);

        res = 1;
        for (int ii = 0; ii < n; ++ii)
        for (int jj = 0; jj < n; ++jj)
        if (ii != jj){
            val = dis(cor[ii], cor[jj]);
            if (abs(val - d * 2) > EP && val > d * 2)
                continue;
            cnt = 0;
            tam = timtam(cor[ii], cor[jj]);
            for (int i = 0; i < n; ++i){
                val = dis(tam, cor[i]);
                if (abs(val - d) < EP || val < d)
                    ++cnt;
            }
            res = max(res, cnt);
        }

        printf("It is possible to cover %d points.\n", res);
    }
    return 0;
}
