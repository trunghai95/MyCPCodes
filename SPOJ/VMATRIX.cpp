#include <bits/stdc++.h>

using namespace std;

int t, n, A[1000][1000], B[1000][1000], C[1000][1000], D[1000], BD[1000], ABD[1000], CD[1000];
char s[1010];

void read(int X[1000][1000])
{
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s);
        for (int j = 0; j < n; ++j)
            X[i][j] = s[j] - '0';
    }
}

bool solve()
{
    memset(BD, 0, sizeof(BD));
    memset(ABD, 0, sizeof(ABD));
    memset(CD, 0, sizeof(CD));
    for (int i = 0; i < n; ++i) D[i] = rand()%10;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            BD[i] += B[i][j]*D[j];
        BD[i] %= 10;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ABD[i] += A[i][j]*BD[j];
            CD[i] += C[i][j]*D[j];
        }
        ABD[i] %= 10; CD[i] %= 10;
        if (ABD[i] != CD[i]) return 0;
    }

    return 1;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        bool f = 1;
        read(A); read(B); read(C);
        for (int ii = 0; ii < 50 && f; ++ii)
            if (!solve()) f = 0;
        if (f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
