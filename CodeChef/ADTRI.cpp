#include <bits/stdc++.h>

using namespace std;

int m[3][9] = { {1,-2,2,2,-1,2,2,-2,3}, {1,2,2,2,1,2,2,2,3}, {-1,2,2,-2,1,2,-2,2,3} };

int n;
bool ck[5000001];

void Try(int a, int b, int c)
{
    if (c > 5000000) return;

    if (!ck[c])
    for (int i = 1; c*i <= 5000000; ++i)
        ck[c*i] = 1;

    int aa, bb, cc;

    for (int i = 0; i < 3; ++i)
    {
        aa = a*m[i][0] + b*m[i][1] + c*m[i][2];
        bb = a*m[i][3] + b*m[i][4] + c*m[i][5];
        cc = a*m[i][6] + b*m[i][7] + c*m[i][8];

        Try(aa,bb,cc);
    }
}

int main()
{
    Try(3,4,5);
    int test;
    scanf("%d", &test);
    while (test--)
    {
        scanf("%d", &n);
        if (ck[n])
            printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
