#include <bits/stdc++.h>

using namespace std;

int n, nbit[300000], mx;
double a[18][18], p[300000];

int isOn(int S, int i) { return S & (1 << i); }
int setbit(int S, int i) { return S | (1 << i); }
double pDie(int S, int pos)
{
    double res = 0;
    int tmp = (nbit[S] + 1)*(nbit[S]) / 2;
    for (int i = 0; i < n; ++i)
    if (isOn(S,i) && (i != pos))
        res += a[i][pos] * 1.0 / tmp;
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%lf", &a[i][j]);
    mx = (1 << n) - 1;
    nbit[0] = 0;
    for (int i = 1; i <= mx; ++i)
        nbit[i] = nbit[i >> 1] + (i&1);
    p[mx] = 1;
    for (int nn = n-1; nn > 0; --nn)
    {
        for (int i = 1; i < mx; ++i)
        if (nbit[i] == nn)
        {
            for (int j = 0; j < n; ++j)
                if (!isOn(i,j))
                    p[i] += pDie(i,j) * p[setbit(i,j)];
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%.6lf ", p[1 << i]);
    return 0;
}
