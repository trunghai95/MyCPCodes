#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e7;
long long p, q, paCnt, prCnt, res=-1;
bool notPr[MAX];
char s[15];

void prInit()
{
    notPr[0] = notPr[1] = 1;
    for (int i = 2; i*i <= MAX; ++i)
    {
        if (!notPr[i])
        {
            int j = i*i;
            while (j <= MAX)
            {
                notPr[j] = 1;
                j += i;
            }
        }
    }
}

bool palin(long long n)
{
    itoa(n, s, 10);
    int l = strlen(s);
    for (int i = 0; i <= l/2; ++i)
    {
        if (s[i] != s[l-i-1])
            return 0;
    }
    return 1;
}

int main()
{
    prInit();
    cin >> p >> q;
    for (int i = 1; i < MAX; ++i)
    {
        if (!notPr[i])
            ++prCnt;
        if (palin(i))
            ++paCnt;
        if (prCnt*q <= paCnt*p)
            res = i;
    }
    if (res == -1)
        cout << "Palindromic tree is better than splay tree";
    else
        cout << res;
    return 0;
}
