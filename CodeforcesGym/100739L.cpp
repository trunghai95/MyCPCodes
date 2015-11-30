#include <bits/stdc++.h>

using namespace std;

long long f(long long a)
{
    if (a == 0) return 1;
    if (a == 1) return 2;
    long long aa = a/2;
    long long rr = f(aa)*f(aa);
    if (a&1) rr = rr * 2;
    rr = rr%1000000007;
    return rr;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    long long a;
    scanf("%I64d", &a);
    printf("%I64d", f(a));
    return 0;
}
